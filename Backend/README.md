# Python Script

## Functionality
The python script takes in the data from the arduino, sorts it, then stores it in a csv file on a day by day basis.

## Repeatability
When running this code, there will be issues that need to be addressed. 
+ The first is the import serial issue which occurs when 1 of two things happen, there is either no serial library installed or it is outdated. To fix this, install or update the pyserial library.
+ The second issue has to do with finding the correct serial port where the arduino is connected. This is dependant on the OS that the computer is running. Linux will use "/dev/ttyACM*", mac will use "/dev/tty.usbmodem*", windows will use "P1AM-100 (COM*)". Thiws project was run on a linux (ubuntu 20.04), and in this case to run the code, there was an additional step which included using "sudo chmod a+rw /dev/ttyACM0". 
Aside from these two issues, the rest of the code should be ready to run.