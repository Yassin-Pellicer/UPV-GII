#!/bin/bash
# script_delete_old_files.sh

SCRIPT_DIR="$(dirname "$0")"
PROJECT_DIR="$SCRIPT_DIR/.."
DATASETS_DIR="$PROJECT_DIR/datasets"
LOG="$PROJECT_DIR/log.txt"
DAYS=30

echo "[$(date +"%Y/%m/%d %H:%M:%S.%3N")] - Starting cleanup of files older than $DAYS days in $DATASETS_DIR" >> "$LOG"

if [ ! -d "$DATASETS_DIR" ]; then
  echo -e "\t[$(date +"%H:%M:%S.%3N")] [ko] [ERROR] - Directory $DATASETS_DIR does not exist" >> "$LOG"
  exit 1
fi

files_to_delete=$(find "$DATASETS_DIR" -type f -name "constituents-financials_*.csv" -mtime +$DAYS | wc -l)

if [ "$files_to_delete" -gt 0 ]; then
  find "$DATASETS_DIR" -type f -name "constituents-financials_*.csv" -mtime +$DAYS -delete >> "$LOG" 2>&1
  
  echo "[$(date +"%Y/%m/%d %H:%M:%S.%3N")] [ok] - Cleanup successful. Deleted $files_to_delete file(s)" >> "$LOG"
else
  echo "[$(date +"%Y/%m/%d %H:%M:%S.%3N")] [ok] - No files older than $DAYS days found. Nothing to delete" >> "$LOG"
fi
