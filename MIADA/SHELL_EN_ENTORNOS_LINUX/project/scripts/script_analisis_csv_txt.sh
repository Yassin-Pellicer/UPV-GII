#!/bin/bash
# script_analisis_csv_txt.sh [YYYYMMDD]

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
DATASETS_DIR="$PROJECT_DIR/datasets"
ANALYSIS_DIR="$PROJECT_DIR/analysis"
LOG="$PROJECT_DIR/log.txt"

# Local variables

REPORT_DATE="${1:-$(date +"%Y%m%d")}"
FILE="constituents-financials_${REPORT_DATE}.csv"
DATA_FILE="$DATASETS_DIR/$FILE"
DAY_DIR="$ANALYSIS_DIR/$REPORT_DATE"
DATE_FORMATTED="${REPORT_DATE:6:2}/${REPORT_DATE:4:2}/${REPORT_DATE:0:4}"

# We declare a local log function

log() {
  echo "[$(date +"%Y/%m/%d %H:%M:%S.%3N")] - $*" >> "$LOG"
}

# If the download fails (the file does not exist), we log the error and exit

if [[ ! -f "$DATA_FILE" ]]; then
  log "Dataset not found: $DATA_FILE"
  exit 1
fi

# We declare the nº of entries and create the folder for the reports

entries=$(( $(wc -l < "$DATA_FILE") - 1 ))
mkdir -p "$DAY_DIR"

log "BEGAN CREATION OF TXT REPORTS"

log "Analyzing $FILE; reports will be stored in /project/analysis/$REPORT_DATE"

table_preamble() {
  local output="$1"
  local title="$2"
  local length="${3:-100}"
  {
    printf '+%*s+\n' "$length" '' | tr ' ' '='
    printf '| %-*s |\n' "$((length - 2))" "$title"
    printf '+%*s+\n' "$length" '' | tr ' ' '='

    printf '| Date: %-8s | Processed entries: %-*s |\n' \
      "$DATE_FORMATTED" \
      "$((length - 40))" \
      "$entries"
  } > "$output"
}

# TOP MARKET CAP COMPANIES

TOP_REPORT="$DAY_DIR/top_market_cap_companies.txt"

table_preamble "$TOP_REPORT" "TOP MARKET CAP COMPANIES" 64

log "Creating $TOP_REPORT"

tail -n +2 "$DATA_FILE" |
sort -t',' -k10,10nr |
awk -F',' '
  function fit(value, width) {
    return length(value) <= width ? value : substr(value, 1, width - 3) "..."
  }
  function commas(value, text, result) {
    text = sprintf("%.0f", value)
    result = ""
    while (length(text) > 3) {
      result = "," substr(text, length(text) - 2) result
      text = substr(text, 1, length(text) - 3)
    }
    return text result
  }
  BEGIN {
    print "+--------------------+----------+--------------------------------+"
    print "| Market Cap         | Symbol   | Company                        |"
    print "+--------------------+----------+--------------------------------+"
  }
  {
    printf "| %18s | %-8s | %-30s |\n",
      commas($10),
      fit($1, 8),
      fit($2, 30)
  }
  END {
    print "+--------------------+----------+--------------------------------+"
  }
' >> "$TOP_REPORT"

log "$TOP_REPORT CREATED SUCCESSFULLY"

# HIGHEST GROSSING SECTORS

SECTORS_REPORT="$DAY_DIR/highest_grossing_sectors.txt"

log "Creating $SECTORS_REPORT"

table_preamble "$SECTORS_REPORT" "HIGHEST GROSSING SECTORS" 65

tail -n +2 "$DATA_FILE" |
sort -t',' -k10,10nr |
awk -F',' '
  function fit(value, width) {
    return length(value) <= width ? value : substr(value, 1, width - 3) "..."
  }
  function commas(value, text, result) {
    text = sprintf("%.0f", value)
    result = ""
    while (length(text) > 3) {
      result = "," substr(text, length(text) - 2) result
      text = substr(text, 1, length(text) - 3)
    }
    return text result
  }
  {
    sector_sum[$3] += $10
    companies[$3] = companies[$3] sprintf("| %-8s | %-31s | %18s |\n",
      fit($1, 8),
      fit($2, 32),
      commas($10))
  }
  END {
    # SORTING BY HIGHEST GROSSING SECTORS
    for (sector in sector_sum) sectors[++count] = sector

    for (i = 1; i <= count; i++) {
      for (j = i + 1; j <= count; j++) {
        if (sector_sum[sectors[j]] > sector_sum[sectors[i]]) {
          temp = sectors[i];
          sectors[i] = sectors[j];
          sectors[j] = temp
        }
      }
    }

    for (i = 1; i <= count; i++) {
      sector = sectors[i]
      print "+=================================================================+"
      printf "| %-63s |\n", fit(sector, 84)
      print "+=================================================================+"
      print "| Symbol   | Company                         |  Market Cap        |"
      print "+----------+------------------------------------------------------+"
      printf "%s", companies[sector]
      print "+-----------------------------------------------------------------+"
      printf "| %-38s    %21s |\n", "SECTOR TOTAL", commas(sector_sum[sector])
      print "+-----------------------------------------------------------------+"
    }
  }
  ' >> "$SECTORS_REPORT"

log "$SECTORS_REPORT CREATED SUCCESSFULLY"

# TOPP WINNERS

WINNERS_REPORT="$DAY_DIR/highest_winners_52_week_metric.txt"

log "Creating $WINNERS_REPORT"

table_preamble "$WINNERS_REPORT" "HIGHEST WINNERS (52-WEEK METRIC)" 68

{
  echo "+----------+------------------------+----------+----------+----------+"
  echo "| Symbol   | Company                | Price    | 52W High | Distance |"
  echo "+----------+------------------------+----------+----------+----------+"

  tail -n +2 "$DATA_FILE" |
  awk -F',' '
    function fit(value, width) {
      return length(value) <= width ? value : substr(value, 1, width - 3) "..."
    }
    $9 > 0 {
      distance = (($9 - $4) / $9) * 100
      printf "%012.6f|| %-8s | %-22.22s | %8.2f | %8.2f | %7.2f%% |\n", \
        distance, $1, fit($2, 22), $4, $9, distance
    }
  ' |
  sort -t'|' -k1,1n |
  cut -d'|' -f2-

  echo "+----------+------------------------+----------+----------+----------+"
} >> "$WINNERS_REPORT"

log "Analysis complete: reports created in /project/analysis/$REPORT_DATE"

log "$WINNERS_REPORT CREATED SUCCESSFULLY"

# PRICE AND MARKET CAP EVOLUTION

EVOLUTION_REPORT="$DAY_DIR/price_market_cap_evolution.txt"

log "Creating $EVOLUTION_REPORT"

table_preamble "$EVOLUTION_REPORT" "PRICE AND MARKET CAP EVOLUTION" 90

{
  {
    for DATA_FILE_DAY in "$DATASETS_DIR"/constituents-financials_*.csv; do
      [[ -f "$DATA_FILE_DAY" ]] || continue

      DATE_DAY=$(basename "$DATA_FILE_DAY" | sed 's/constituents-financials_//' | sed 's/.csv//')

      # An evolution report is a snapshot: never include a later dataset.
      [[ "$DATE_DAY" =~ ^[0-9]{8}$ && "$DATE_DAY" -le "$REPORT_DATE" ]] || continue

      tail -n +2 "$DATA_FILE_DAY" |
      sort -t',' -k10,10nr |
      awk -F',' -v date="$DATE_DAY" '
      {
        printf "%s|%s|%s|%.6f|%.6f\n",
          $1,
          $2,
          date,
          $4,
          $10
      }
    '
  done |
  awk -F'|' '
  {
    sum[$1] += $5
    count[$1]++
    data[NR] = $0
  }
  END {
    for (i = 1; i <= NR; i++) {
      split(data[i], f, "|")
      symbol = f[1]
      mean = sum[symbol] / count[symbol]

      printf "%.6f|%s|%s\n", mean, symbol, data[i]
    }
  }' |
  sort -t'|' -k1,1nr -k2,2 -k4,4 |
  cut -d'|' -f3-
  } | awk -F'|' '
    function commas(value, text, result) {
      if (value < 0) {
        return "-" commas(-value)
      }

      text = sprintf("%.0f", value)
      result = ""

      while (length(text) > 3) {
        result = "," substr(text, length(text) - 2) result
        text = substr(text, 1, length(text) - 3)
      }

      return text result
    }

    function fit(value, width) {
      return length(value) <= width ? value : substr(value, 1, width - 3) "..."
    }

    function format_date(value) {
      return substr(value, 7, 2) "/" substr(value, 5, 2) "/" substr(value, 1, 4)
    }

    {
      symbol = $1
      company = $2
      date = $3
      price=$4
      market_cap=$5

      if (company != current_company) {
        current_company = company
        previous_price = ""
        previous_market_cap = ""

        print "+==========================================================================================+"
        printf "| %-10s | %-75s |\n", symbol, fit(company, 62)
        print "+------------+------------+------------+--------------------------+------------------------+"
        print "| Date       | Price      | Price Diff | Market Cap               | Market Cap Diff        |"
        print "+------------+------------+------------+--------------------------+------------------------+"
      }

      if (previous_price == "") {
        printf "| %-8s | %10.2f | %10s | %24s | %22s |\n",
          format_date(date),
          price,
          "No record",
          commas(market_cap),
          "No record" 
      }
      else {
        price_diff = price - previous_price
        market_cap_diff = market_cap - previous_market_cap 
        
        if (price_diff != 0) {
          printf "| %-8s | %10.2f | %10s | %24s | %22s |\n",
            format_date(date),
            price,
            price_diff,
            commas(market_cap),
            commas(market_cap_diff)
        }
      }

      previous_market_cap = market_cap
      previous_price = price  
    }

    END {
      if (current_company != "") {
        print "+------------+------------+------------+--------------------------+------------------------+"
      }
    }
  '
} >> "$EVOLUTION_REPORT"

log "$EVOLUTION_REPORT CREATED SUCCESSFULLY"
