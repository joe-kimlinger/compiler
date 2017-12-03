#!/bin/bash
./cminor -codegen in.cminor out.s
gcc out.s library.o -o run
./run
RESULT=$?
echo "RESULT:"
echo $RESULT
rm run
