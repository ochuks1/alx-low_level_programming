#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -shared -fPIC *.c -o liball.so
gcc *.c -c -fpic
gcc -shared -o liball.so *.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
