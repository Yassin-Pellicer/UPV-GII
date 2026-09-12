#!/bin/bash
# script_download.sh

SCRIPT_DIR="$(dirname "$0")"
PROJECT_DIR="$SCRIPT_DIR/.."
DATASETS_DIR="$PROJECT_DIR/datasets"
LOG="$PROJECT_DIR/log.txt"
FILE="constituents-financials_$(date +"%Y%m%d").csv"

log_command_error() {
  local tool="$1" error
  while IFS= read -r error; do
    echo -e "\t[$(date +"%H:%M:%S.%3N")] [ko] [ERROR] [$tool] - $error" >> "$LOG"
  done
}

echo "[$(date +"%Y/%m/%d %H:%M:%S.%3N")] - DATASET DOWNLOAD STARTED: $FILE" >> "$LOG"
echo -e "\t[$(date +"%H:%M:%S.%3N")] [ok] - Source: S&P 500 financial dataset" >> "$LOG"
echo -e "\t[$(date +"%H:%M:%S.%3N")] [ok] - Destination: /project/datasets/$FILE" >> "$LOG"

cd "$DATASETS_DIR" || exit 1

attempt=1

until curl -fsSL -o "$FILE" \
  "https://raw.githubusercontent.com/datasets/s-and-p-500-companies-financials/main/data/constituents-financials.csv" \
  2> >(log_command_error "curl")
do
  echo -e "\t[$(date +"%H:%M:%S.%3N")] [ko] - Error downloading $FILE, retry $attempt/10" >> "$LOG"

  if [ "$attempt" -ge 10 ]; then
    echo -e "\t[$(date +"%H:%M:%S.%3N")] [ko] [ERROR] - Download failed after 10 attempts" >> "$LOG"
    exit 1
  fi

  attempt=$((attempt + 1))
  sleep 30
done

echo -e "\t[$(date +"%H:%M:%S.%3N")] [ok] - Downloaded $FILE successfully" >> "$LOG"
echo "[$(date +"%Y/%m/%d %H:%M:%S.%3N")] - DATASET DOWNLOAD COMPLETED" >> "$LOG"
