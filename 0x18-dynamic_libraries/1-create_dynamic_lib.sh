#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -shared -fPIC *.c -o libdynamic.so
gcc *.c -c -fpic
gcc -shared -o libdynamic.so *.o
