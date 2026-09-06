#!/bin/bash
# script_analisis_csv.sh

SCRIPT_DIR="$(dirname "$0")"
PROJECT_DIR="$SCRIPT_DIR/.."
DATASETS_DIR="$PROJECT_DIR/datasets"
LOG="$PROJECT_DIR/log.txt"
FILE="constituents-financials_$(date +"%Y%m%d").csv"

ANALYSIS_DIR="$PROJECT_DIR/informes"
TXT_FILE="analysis_$(date +"%Y%m%d").txt"

echo "[$(date +"%Y/%m/%d %H:%M:%S.%3N")] - Analyzing $FILE in route /project/datasets/$FILE" >> "$LOG"

# Analyzing

cd "$ANALYSIS_DIR" || exit 1
echo "[$(date +"%Y/%m/%d %H:%M:%S.%3N")] - Creating $TXT_FILE in route /project/informes/$TXT_FILE" >> "$LOG"

# TOP MARKET CAP COMPANIES

echo -e "\t[$(date +"%H:%M:%S.%3N")] - DUMPING TOP MARKET CAP COMPANIES IN $TXT_FILE" >> "$LOG"

echo -e "TOP MARKET CAP COMPANIES" > "$ANALYSIS_DIR/$TXT_FILE"
echo -e "Processed $(( $(wc -l < "$DATASETS_DIR/$FILE") - 1 )) entries" >> "$ANALYSIS_DIR/$TXT_FILE"
echo -e "-----------------------------------------------------------------------\n" >> "$ANALYSIS_DIR/$TXT_FILE"

awk -F',' 'NR > 1 { print $0 }' "$DATASETS_DIR/$FILE" |
sort -t',' -k10,10nr |
awk -F',' '
BEGIN {
  printf "%-8s %-20s %-40s %s\n", "Symbol", "Market Cap", "Name", "Sector"
} {
  printf "%-8s %-20s %-40s %s\n", $1, $10, $2, $3
}
' >> "$ANALYSIS_DIR/$TXT_FILE"

echo -e "\t[$(date +"%H:%M:%S.%3N")] - DUMP SUCCESSFUL $TXT_FILE" >> "$LOG"

# HIGHEST GROSSING SECTORS

echo -e "\t[$(date +"%H:%M:%S.%3N")] - DUMPING HIGHEST GROSSING SECTORS $TXT_FILE" >> "$LOG"

echo -e "\nHIGHEST GROSSING SECTORS" >> "$ANALYSIS_DIR/$TXT_FILE"
echo -e "Processed $(( $(wc -l < "$DATASETS_DIR/$FILE") - 1 )) entries" >> "$ANALYSIS_DIR/$TXT_FILE"
echo -e "-----------------------------------------------------------------------\n" >> "$ANALYSIS_DIR/$TXT_FILE"

awk -F',' 'NR > 1 { print $0 }' "$DATASETS_DIR/$FILE" |
sort -t',' -k10,10nr |
awk -F',' '
NR > 1 {
  sector_sum[$3] += $10
  companies[$3] = companies[$3] sprintf("\t%-8s %-40s %20.0f\n", $1, $2, $10)
}
END {
  n = 0

  for (i in sector_sum) {
    sectors[++n] = i
  }

  # Sort sectors by gross market cap, highest first
  # Find the highest grossing sector and put it in position 1...
  for (i = 1; i <= n; i++) {
    max = i

    for (j = i + 1; j <= n; j++) {
      if (sector_sum[sectors[j]] > sector_sum[sectors[max]]) {
        max = j
      }
    }

    if (max != i) {
      tmp = sectors[i]
      sectors[i] = sectors[max]
      sectors[max] = tmp
    }
  }

  printf "%-51s %20s\n", "Sector", "Gross Market Cap"
  print ""

  for (i = 1; i <= n; i++) {
    sector = sectors[i]

    print sector
    print "Comprised of:"
    printf "%s", companies[sector]
    printf "------------------------------------------------------------------------\n"
    printf "\t%-8s %-40s %20.0f\n", "Total:", "", sector_sum[sector]
    print ""
  }
}
' "$DATASETS_DIR/$FILE" >> "$ANALYSIS_DIR/$TXT_FILE"

echo -e "\t[$(date +"%H:%M:%S.%3N")] - DUMP SUCCESSFUL $TXT_FILE" >> "$LOG"

# HIGHEST WINNERS (52 WEEK METRIC)

echo -e "\t[$(date +"%H:%M:%S.%3N")] - HIGHEST WINNERS (52 WEEK METRIC) $TXT_FILE" >> "$LOG"

echo -e "\nHIGHEST WINNERS (52 WEEK METRIC)" >> "$ANALYSIS_DIR/$TXT_FILE"
echo -e "Processed $(( $(wc -l < "$DATASETS_DIR/$FILE") - 1 )) entries" >> "$ANALYSIS_DIR/$TXT_FILE"
echo -e "-----------------------------------------------------------------------\n" >> "$ANALYSIS_DIR/$TXT_FILE"

awk -F',' '
NR > 1 {
  if ($9 > 0) {
    distance = (($9 - $4) / $9) * 100
    printf "%.6f\t%s\t%s\t%s\t%.2f\t%.2f\t%.2f\n", \
      distance, $1, $2, $3, $4, $8, $9
  }
}
' "$DATASETS_DIR/$FILE" |
sort -t$'\t' -k1,1n |
awk -F'\t' '
BEGIN {
  printf "%-8s %-40s %15s %15s %15s %15s\n",
    "Symbol", "Name", "Price", "52W Low", "52W High", "Distance"
  print ""
}
{
  printf "%-8s %-40s %15.2f %15.2f %15.2f %14.2f%%\n",
    $2, $3, $5, $6, $7, $1
}
' >> "$ANALYSIS_DIR/$TXT_FILE"

echo -e "\t[$(date +"%H:%M:%S.%3N")] - DUMP SUCCESSFUL $TXT_FILE" >> "$LOG"

# HIGHEST LOSERS (52 WEEK METRIC)

echo -e "\t[$(date +"%H:%M:%S.%3N")] - HIGHEST LOSERS (52 WEEK METRIC) $TXT_FILE" >> "$LOG"

echo -e "\nHIGHEST LOSERS (52 WEEK METRIC)" >> "$ANALYSIS_DIR/$TXT_FILE"
echo -e "Processed $(( $(wc -l < "$DATASETS_DIR/$FILE") - 1 )) entries" >> "$ANALYSIS_DIR/$TXT_FILE"
echo -e "-----------------------------------------------------------------------\n" >> "$ANALYSIS_DIR/$TXT_FILE"

awk -F',' '
NR > 1 {
  if ($9 > 0) {
    distance = (($9 - $4) / $9) * 100
    printf "%.6f\t%s\t%s\t%s\t%.2f\t%.2f\t%.2f\n", \
      distance, $1, $2, $3, $4, $8, $9
  }
}
' "$DATASETS_DIR/$FILE" |
sort -t$'\t' -k1,1nr |
awk -F'\t' '
BEGIN {
  printf "%-8s %-40s %15s %15s %15s %15s\n",
    "Symbol", "Name", "Price", "52W Low", "52W High", "Distance"
  print ""
}
{
  printf "%-8s %-40s %15.2f %15.2f %15.2f %14.2f%%\n",
    $2, $3, $5, $6, $7, $1
}
' >> "$ANALYSIS_DIR/$TXT_FILE"

echo -e "\t[$(date +"%H:%M:%S.%3N")] - DUMP SUCCESSFUL $TXT_FILE" >> "$LOG"