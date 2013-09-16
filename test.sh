#!/bin/sh
echo Fast:
dd if=/dev/zero bs=4096 count=100000 | time ./getalpha_fast
echo Slow:
dd if=/dev/zero bs=4096 count=100000 | time ./getalpha_slow
