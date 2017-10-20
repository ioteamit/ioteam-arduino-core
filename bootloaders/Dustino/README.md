# SmartEverything bootloaders

The bootloader of all the SmartEverything boards is based on the Arduino Zero/MKR100 bootloaders.

It is based on the arduino Zero Release 1.6.7


## Procedure
### Preparation
Copy all the files that are in the bootloader directory of the arduino Zero unit.

DOES NOT COPY the following files, which shall be use the SmartEverything version:
* [board_definitions.h] 		- the general include file from the soirce files.
* [board_definitions_asme_lion.h] 	- Specific Lion description file.
* [board_definitions_asme_fox.h] 	- Specific Fox description file.
* [board_definitions_adi.h] 		- great UI boilerplate for modern web apps.
* [build_all_bootloaders.sh] 		- The script to run.
* [Makefile]                    	- The makefile.
* [build_all_bootloaders.sh]    	- The script file to run for compile all the bootloader

### Compile
Once You copy all the required file just run the scritp
 `build_all_bootloaders.sh`.


   
