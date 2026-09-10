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

HTML_TEMPLATE="$SCRIPT_DIR/html/template.html"
JAVASCRIPT_TEMPLATE="$SCRIPT_DIR/html/script.js"
CSS_TEMPLATE="$SCRIPT_DIR/html/style.css"

HTML_REPORT="$DAY_DIR/report/report.html"
JAVASCRIPT_REPORT="$DAY_DIR/report/script.js"
CSS_REPORT="$DAY_DIR/report/style.css"

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

mkdir -p "$DAY_DIR/report"
cp "$HTML_TEMPLATE" "$HTML_REPORT"
cp "$JAVASCRIPT_TEMPLATE" "$JAVASCRIPT_REPORT"
cp "$CSS_TEMPLATE" "$CSS_REPORT"

log "BEGAN CREATION OF HTML REPORTS"

log "Analyzing $FILE; reports will be stored in /project/analysis/$REPORT_DATE/report"

# TOP MARKET CAP COMPANIES

log "Creating TOP MARKET CAP ANALYSIS in $HTML_REPORT"

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
    printf "              <tr>\n"
    printf "                <td>%s</td>\n", commas($10)
    printf "                <td>%s</td>\n", fit($1, 8)
    printf "                <td>%s</td>\n", fit($2, 30)
    printf "              </tr>\n"
  }
' > rows.html

sed -i '/<!-- TOP MARKET CAP ROWS -->/{
  r rows.html
  d
}' "$HTML_REPORT"

log "TOP MARKET CAP ANALYSIS CREATED SUCCESSFULLY in $HTML_REPORT"

# HIGHEST GROSSING SECTORS

SECTORS_REPORT="$DAY_DIR/highest_grossing_sectors.txt"

log "Creating $SECTORS_REPORT"

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
    companies[$3] = companies[$3] sprintf("              <tr>\n")
    companies[$3] = companies[$3] sprintf("                <td>%s</td>\n", fit($1, 8))
    companies[$3] = companies[$3] sprintf("                <td>%s</td>\n", fit($2, 31))
    companies[$3] = companies[$3] sprintf("                <td>%s</td>\n", commas($10))
    companies[$3] = companies[$3] sprintf("              </tr>\n")
  }

  END {
    # SORT SECTORS BY TOTAL MARKET CAP
    for (sector in sector_sum)
      sectors[++count] = sector

    for (i = 1; i <= count; i++) {
      for (j = i + 1; j <= count; j++) {
        if (sector_sum[sectors[j]] > sector_sum[sectors[i]]) {
          temp = sectors[i]
          sectors[i] = sectors[j]
          sectors[j] = temp
        }
      }
    }

    # GENERATE HTML
    for (i = 1; i <= count; i++) {
      sector = sectors[i]

      printf "    <div class=\"sector-table\">\n"

      printf "      <h3 class=\"table-header\">%s</h3>\n", fit(sector, 63)

      printf "      <table>\n"

      printf "        <thead>\n"
      printf "          <tr>\n"
      printf "            <th>Symbol</th>\n"
      printf "            <th>Company</th>\n"
      printf "            <th>Capitalización Bursátil</th>\n"
      printf "          </tr>\n"
      printf "        </thead>\n"

      printf "        <tbody>\n"

      printf "%s", companies[sector]

      printf "          <tr class=\"sector-total\">\n"
      printf "            <td colspan=\"2\">SECTOR TOTAL</td>\n"
      printf "            <td>%s</td>\n", commas(sector_sum[sector])
      printf "          </tr>\n"

      printf "        </tbody>\n"
      printf "      </table>\n"
      printf "    </div>\n\n"
    }
  }
' > rows.html

sed -i '/<!-- SECTOR_ROWS -->/{
  r rows.html
  d
}' "$HTML_REPORT"

# TOP WINNERS

WINNERS_REPORT="$DAY_DIR/highest_winners_52_week_metric.txt"

log "Creating $WINNERS_REPORT"


tail -n +2 "$DATA_FILE" |
awk -F',' '
  function fit(value, width) {
    return length(value) <= width ? value : substr(value, 1, width - 3) "..."
  }
  NR > 1 && $9 > 0 {
    distance = (($9 - $4) / $9) * 100

    printf "%012.6f|%s|%s|%s|%s|%s\n", \
      distance, \
      $1, \
      fit($2, 20), \
      $4, \
      $9, \
      distance
  }
' "$DATA_FILE" |
sort -t'|' -k1,1n |
cut -d'|' -f2- |
awk -F'|' '
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
    printf "              <tr>\n"
    printf "                <td>%s</td>\n", $1
    printf "                <td>%s</td>\n", $2
    printf "                <td>%s</td>\n", $3
    printf "                <td>%s</td>\n", $4
    printf "                <td>%.2f%%</td>\n", $5
    printf "              </tr>\n"
  }
' > rows.html

sed -i '/<!-- TOP MARKET WINNERS -->/{
  r rows.html
  d
}' "$HTML_REPORT"

log "Analysis complete: reports created in /project/analysis/$REPORT_DATE"

# PRICE AND MARKET CAP EVOLUTION

EVOLUTION_REPORT="$DAY_DIR/price_market_cap_evolution.txt"

log "Creating $EVOLUTION_REPORT"

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
  } |
  awk -F'|' '
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
      price = $4
      market_cap = $5

      if (company != current_company) {
        if (current_company != "") {
          printf "        </tbody>\n"
          printf "      </table>\n"
          printf "    </div>\n\n"
        }

        current_company = company
        previous_price = ""
        previous_market_cap = ""

        printf "    <div class=\"sector-table\">\n"
        printf "      <h3 class=\"table-header\">%s | %s</h3>\n", symbol, fit(company, 63)

        printf "      <table>\n"

        printf "        <thead>\n"
        printf "          <tr>\n"
        printf "            <th class=\"date-row\">Fecha</th>\n"
        printf "            <th class=\"price-row\">Precio</th>\n"
        printf "            <th class=\"price-row-diff\">Diferencia de precio</th>\n"
        printf "            <th>Capitalización bursátil</th>\n"
        printf "            <th>Diferencia de Capitalización</th>\n"
        printf "          </tr>\n"
        printf "        </thead>\n"

        printf "        <tbody>\n"
      }

      printf "          <tr>\n"
      printf "            <td class=\"date-row\">%s</td>\n", format_date(date)
      printf "            <td class=\"price-row\">%.2f</td>\n", price

      if (previous_price == "") {
        printf "            <td class=\"price-row-diff\">No record</td>\n"
        printf "            <td>%s</td>\n", commas(market_cap)
        printf "            <td>No record</td>\n"
      }
      else {
        price_diff = price - previous_price
        market_cap_diff = market_cap - previous_market_cap

        printf "            <td class=\"price-row-diff\">%.2f</td>\n", price_diff
        printf "            <td>%s</td>\n", commas(market_cap)
        printf "            <td>%s</td>\n", commas(market_cap_diff)
      }

      printf "          </tr>\n"

      previous_market_cap = market_cap
      previous_price = price
    }

    END {
      if (current_company != "") {
        printf "        </tbody>\n"
        printf "      </table>\n"
        printf "    </div>\n"
      }
    }
  '
} > rows.html

sed -i '/<!-- EVOLUTION -->/{
  r rows.html
  d
}' "$HTML_REPORT" && rm -f rows.html