#!/bin/bash -ex

make cleanRoot 

BOARD_ID=asme_fox NAME=fox_boot CPU=__SAMD21J18A__ make clean all

BOARD_ID=asme_lion NAME=lion_boot CPU=__SAMD21J18A__ make clean all

BOARD_ID=asme_dragonfly NAME=dragonfly_boot CPU=__SAMD21J18A__ make clean all

BOARD_ID=dustino NAME=dustino_boot CPU=__SAMD21G18A__ make clean all

mv -v *.bin ../
mv -v *.hex ../

echo Done building bootloaders!

