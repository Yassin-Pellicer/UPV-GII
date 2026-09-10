#!/bin/bash
# script_cron.sh

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
LOG="$PROJECT_DIR/log.txt"

log() {
  echo "[$(date +"%Y/%m/%d %H:%M:%S.%3N")] - $*" >> "$LOG"
}

log_detail() {
  echo -e "\t[$(date +"%H:%M:%S.%3N")] $*" >> "$LOG"
}

run_step() {
  local name="$1"
  local script="$2"

  log_detail "[ok] - Starting: $name"
  if "$script"; then
    log_detail "[ok] - Completed: $name"
  else
    log_detail "[ko] [ERROR] - Failed: $name"
    log "DAILY AUTOMATION FAILED"
    exit 1
  fi
}

# Separate this execution from the previous cron-run block.
echo >> "$LOG"
log "DAILY AUTOMATION STARTED"
run_step "removing expired datasets" "$PROJECT_DIR/scripts/script_delete.sh"
run_step "downloading the current dataset" "$PROJECT_DIR/scripts/script_download.sh"
run_step "sanitizing the dataset" "$PROJECT_DIR/scripts/script_sanitize.sh"
run_step "creating text reports" "$PROJECT_DIR/scripts/script_analisis_csv_txt.sh"
run_step "creating HTML reports" "$PROJECT_DIR/scripts/script_analisis_csv_html.sh"
log "DAILY AUTOMATION COMPLETED SUCCESSFULLY"
