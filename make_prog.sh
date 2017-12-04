#!/bin/sh
NAME=$1
cminor -codegen $NAME.cminor $NAME.s 
gcc -c gfx.c -o gfx.o -g
gcc $NAME.s gfx.o library.o -o $NAME -lX11 -lm
