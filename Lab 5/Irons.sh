#! /bin/bash
if test "$#" -eq 0 
	then
		echo "Must provide an argument"
		exit 1
elif test "$1" = "-c"
	then
		echo "The number of files"
		echo "How many bytes"
elif test "$1" = "-l"
	then
		echo "List all the files"
elif test "$1" = "--help"
	then
		echo "How to run this script"
fi



if test ! -d ~/backup
	then
		mkdir ~/backup
fi



ls | wc -l
du -b
