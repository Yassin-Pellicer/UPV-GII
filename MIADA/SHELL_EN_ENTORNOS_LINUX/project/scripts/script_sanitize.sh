#!/bin/bash
# script_sanitize.sh

SCRIPT_DIR="$(dirname "$0")"
PROJECT_DIR="$SCRIPT_DIR/.."
DATASETS_DIR="$PROJECT_DIR/datasets"
LOG="$PROJECT_DIR/log.txt"
FILE="constituents-financials_$(date +"%Y%m%d").csv"

echo "[$(date +"%Y/%m/%d %H:%M:%S.%3N")] - Sanitizing $FILE" >> "$LOG"

cd "$DATASETS_DIR" || exit 1

# Removing "," from fields and avoiding rows with empty fields

awk '
{
  n = 0
  field = ""
  quoted = 0

  for (i = 1; i <= length($0); i++) {
    c = substr($0, i, 1)

    if (c == "\"") {
      # Found a quote
      if (quoted && substr($0, i + 1, 1) == "\"") {
        field = field "\""
        i++
      } else {
        quoted = !quoted
      }
    }
    else if (c == "," && !quoted) {
      # Found a field and it is not quoted
      a[++n] = field
      field = ""
    }
    else {
      field = field c
    }
  }

  a[++n] = field

  if (NR == 1) {
    print
    next
  }

  if (a[1] == "" || # Symbol
      a[2] == "" || # Name
      a[3] == "" || # Sector
      a[4] == "" || # Price
      a[7] == "" || # Earnings/Share
      a[8] == "" || # 52 Week Low
      a[9] == "" || # 52 Week High
      a[10] == "" ) { # Market Cap
    cmd = "date +\"%H:%M:%S.%3N\""
    cmd | getline now
    close(cmd)

    print "\t[" now "] (Row no: " NR ") - Deleted row missing required field: " $0 >> log_file
    next
  }

  gsub(/,/, "", a[2])
  gsub(/,/, "", a[3])

  printf "%s", a[1]
  for (i = 2; i <= n; i++)
    printf ",%s", a[i]
  printf "\n"
}
' log_file="$LOG" "$FILE" > tmp.csv && mv tmp.csv "$FILE"

echo "[$(date +"%Y/%m/%d %H:%M:%S.%3N")] - $FILE Sanitized and saved successfully" >> "$LOG"
