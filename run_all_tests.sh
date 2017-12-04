#!/bin/sh

for testfile in good*.cminor
do
	if cminor -codegen $testfile $testfile.s > /dev/null
	then
		echo "$testfile success (as expected)"
	else
		echo "$testfile failure (INCORRECT)"
	fi
done

for testfile in good*.s
do
	echo "running $testfile"
	gcc $testfile library.o -o run > /dev/null
	./run > /dev/null
	rm run
done
