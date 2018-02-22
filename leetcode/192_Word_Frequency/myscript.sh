#!/bin/bash
cat words.txt | tr ' ' '\n' | sort | uniq -c | awk '{if ($2 != "") print $2" "$1}' | sort -n -k 2 -r
