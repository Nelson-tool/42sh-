#!/bin/bash

echo $# "arguments"

count=0
for i in "${BASH_ARGV[@]}"; do
	count=$(expr $count + 1)
	echo -e "$count: $i"
done
