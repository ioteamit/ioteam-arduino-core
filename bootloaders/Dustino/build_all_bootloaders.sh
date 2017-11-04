#!/bin/bash -ex

make cleanRoot 

BOARD_ID=dustino NAME=dustino_boot CPU=__SAMD21G18A__ make clean all

mv -v *.bin ../
mv -v *.hex ../

echo Done building bootloaders!

