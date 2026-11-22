#!/usr/bin/env sh
set -eu

COMMIT_MSG_FILE="$1"
FIRST_LINE=$(head -n 1 "$COMMIT_MSG_FILE" | tr -d '\r')

# Allow automated Git merge/revert commits
case "$FIRST_LINE" in
  Merge\ *|Revert\ \"*) exit 0 ;;
esac

PATTERN='^(feat|fix|chore|docs|refactor|test|perf|build|ci|style|revert)(\([a-z0-9._-]+\))?!?: .+'

if ! printf '%s\n' "$FIRST_LINE" | grep -Eq "$PATTERN"; then
  printf 'Invalid commit message: "%s"\n' "$FIRST_LINE" >&2
  printf 'Expected format: <type>(<optional-scope>): <description>\n' >&2
  printf 'Allowed types: feat, fix, chore, docs, refactor, test, perf, build, ci, style, revert\n' >&2
  exit 1
fi
