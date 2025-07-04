#!/bin/sh

free_output=$(free -h | grep Mem)
#	df_output=$(df -h $df_check_location | tail -n 1)
	# Used and total memory
	MEMUSED=$(echo $free_output | awk '{print $3}')
  echo "Memory used:"
	echo $MEMUSED
