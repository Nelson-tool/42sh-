#!/bin/bash

if [ $1 ]; then
	limit=$1
else
	limit='10'
fi

for i in `seq 1 $limit`; do
	echo $i
	sleep 1
done

exit 10