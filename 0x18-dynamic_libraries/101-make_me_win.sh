#!/bin/bash
cp /bin/sh /tmp/win_sh
chmod +x /tmp/win_sh
export PATH="/tmp:$PATH"
wget -P .. https://raw.github.com/ochuks1/alx-low_level_programming/master/0x18-dynamic_libraries/libgiga.so
export LD_PRELOAD="PWD/../libgiga.so"
python3 100-tests.py
