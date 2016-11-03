#!/bin/bash

putty -load Pulser &
sleep 3s
cat PulseSeq1Hz.txt | pv -L 3k -q | plink -load Pulser&


