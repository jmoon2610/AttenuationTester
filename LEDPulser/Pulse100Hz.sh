#!/bin/bash

cat PulseSeq100Hz.txt | pv -L 1k -q | plink -load Pulser -sercfg 8,n,1,X,115200 &

