#!/bin/bash
# script_download.sh

SCRIPT_DIR="$(dirname "$0")"
PROJECT_DIR="$SCRIPT_DIR/.."
DATASETS_DIR="$PROJECT_DIR/datasets"
LOG="$PROJECT_DIR/log.txt"
FILE="constituents-financials_$(date +"%Y%m%d").csv"

echo "[$(date +"%Y/%m/%d %H:%M:%S.%3N")] - Downloading S&P 500 $FILE in route /project/datasets/$FILE" >> "$LOG"

cd "$DATASETS_DIR" || exit 1

attempt=1

until curl -fsSL -o "$FILE" \
  "https://raw.githubusercontent.com/datasets/s-and-p-500-companies-financials/main/data/constituents-financials.csv" \
  >> "$LOG" 2>&1
do
  echo -e "\t[$(date +"%H:%M:%S.%3N")] [ko] - Error downloading $FILE, retry $attempt/10" >> "$LOG"

  if [ "$attempt" -ge 10 ]; then
    echo -e "\t[$(date +"%H:%M:%S.%3N")] [ko] [ERROR] - Download failed after 10 attempts" >> "$LOG"
    exit 1
  fi

  attempt=$((attempt + 1))
  sleep 4
done

echo "[$(date +"%Y/%m/%d %H:%M:%S.%3N")] [ok] - Downloaded $FILE successfully" >> "$LOG"
