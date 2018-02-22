#!/bin/bash

line=$(cat file.txt | wc -l)

if [ $line -gt 9 ];then
    cat file.txt | head -n 10 | tail -n 1
else
    echo ""
fi
