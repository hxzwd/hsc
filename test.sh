#!/bin/bash
COUNTER=0
NUM_OF_EXEC=500

echo TEST NUMBER OF EXECUTIONS: $NUM_OF_EXEC
echo ARGUMENT IS: $1

while (( $COUNTER < $NUM_OF_EXEC ))
do

	if [[ $1 == "1" ]]
	then
		./main_bin_1
	else
		if [[ $1 == "2" ]]
		then
			./main_bin_2
		else
			if [[ $1 == "3" ]]
			then
				./main_bin_3
			else
				./main_bin
			fi
		fi
	fi
	COUNTER=$COUNTER+1
done

