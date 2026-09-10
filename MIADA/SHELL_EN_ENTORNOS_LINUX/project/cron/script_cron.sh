#!/bin/bash
# script_cron.sh

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

"$PROJECT_DIR/scripts/script_download.sh" || exit 1
"$PROJECT_DIR/scripts/script_sanitize.sh" || exit 1
"$PROJECT_DIR/scripts/script_analisis_csv_txt.sh" || exit 1
"$PROJECT_DIR/scripts/script_analisis_csv_html.sh" || exit 1
"$PROJECT_DIR/scripts/script_delete.sh" || exit 1
