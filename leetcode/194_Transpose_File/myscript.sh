#!/bin/bash

awk '
{
    for (i = 1; i <= NF; i++) {
        if(NR == 1) {
            s[i] = $i;
        } else {
					  print s[i]; 
            s[i] = s[i] " " $i;
					  print s[i]; 
        }
    }
}
END {
    for (i = 1; s[i] != ""; i++) {
        print s[i];
    }
}' file.txt
