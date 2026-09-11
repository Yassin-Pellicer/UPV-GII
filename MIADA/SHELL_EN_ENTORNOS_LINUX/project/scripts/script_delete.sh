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

files_to_delete=0

for dataset in "$DATASETS_DIR"/constituents-financials_*.csv; do
  [ -f "$dataset" ] || continue
  dataset_date=$(basename "$dataset" | grep -oE '[0-9]{8}')
  if [[ "$dataset_date" < "$(date -d "$DAYS days ago" +%Y%m%d)" ]]; then
    rm -- "$dataset" 2> >(log_command_error "rm") && files_to_delete=$((files_to_delete + 1))
  fi
done

if [ "$files_to_delete" -eq 0 ]; then
  echo -e "\t[$(date +"%H:%M:%S.%3N")] [ok] - No expired datasets found" >> "$LOG"
else
  echo -e "\t[$(date +"%H:%M:%S.%3N")] [ok] - Deleted $files_to_delete expired dataset(s)" >> "$LOG"
fi

echo "[$(date +"%Y/%m/%d %H:%M:%S.%3N")] - DATASET CLEANUP COMPLETED" >> "$LOG"
