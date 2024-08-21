#!/bin/bash

# Check if a commit message was provided
if [ -z "$1" ]; then
  echo "Error: No commit message provided."
  echo "Usage: $0 \"<commit message>\""
  exit 1
fi

# Perform git add, commit, and push
git add .
git commit -m "$1"
git push

# Check if the push was successful
if [ $? -eq 0 ]; then
  echo "Changes have been successfully pushed!"
else
  echo "Error: Failed to push changes."
fi
