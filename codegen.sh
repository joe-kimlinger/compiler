#!/bin/bash
./cminor -codegen in.cminor out.s
gcc -g out.s library.o -o run
