#!/bin/bash
# script_delete_old_files.sh

SCRIPT_DIR="$(dirname "$0")"
PROJECT_DIR="$SCRIPT_DIR/.."
DATASETS_DIR="$PROJECT_DIR/datasets"
LOG="$PROJECT_DIR/log.txt"
DAYS=30

log_command_error() {
  local tool="$1" error
  while IFS= read -r error; do
    echo -e "\t[$(date +"%H:%M:%S.%3N")] [ko] [ERROR] [$tool] - $error" >> "$LOG"
  done
}

echo "[$(date +"%Y/%m/%d %H:%M:%S.%3N")] - DATASET CLEANUP STARTED" >> "$LOG"
echo -e "\t[$(date +"%H:%M:%S.%3N")] [ok] - Removing datasets older than $DAYS days from $DATASETS_DIR" >> "$LOG"

if [ ! -d "$DATASETS_DIR" ]; then
  echo -e "\t[$(date +"%H:%M:%S.%3N")] [ko] [ERROR] - Directory $DATASETS_DIR does not exist" >> "$LOG"
  exit 1
fi

files_to_delete=$(find "$DATASETS_DIR" -type f -name "constituents-financials_*.csv" -mtime +$DAYS 2> >(log_command_error "find") | wc -l)

if [ "$files_to_delete" -gt 0 ]; then
  find "$DATASETS_DIR" -type f -name "constituents-financials_*.csv" -mtime +$DAYS -delete 2> >(log_command_error "find")
  
  echo -e "\t[$(date +"%H:%M:%S.%3N")] [ok] - Deleted $files_to_delete expired dataset(s)" >> "$LOG"
else
  echo -e "\t[$(date +"%H:%M:%S.%3N")] [ok] - No expired datasets found" >> "$LOG"
fi

echo "[$(date +"%Y/%m/%d %H:%M:%S.%3N")] - DATASET CLEANUP COMPLETED" >> "$LOG"
