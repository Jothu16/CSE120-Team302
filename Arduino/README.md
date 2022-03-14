## Main
This is the running code.
This **ONLY** runs on the P1AM board.
This **CANNOT** compile or run in any other IDE, except for the arduino IDE.


## Pump
This header file is meant to control the relay connected to the pump.


## Sensor
This header file is meant to make a class for each input sensor.


## Arduino

The arduino model being used is the P1AM with the folowing expansion:
+ GPIO
+ Ethernet
+ Discrete input mudule

Other Specifications:
Set the Baud to 115200

Use the arduino IDE and follow instructions on downloading the library as well as setting up the board.


### GPIO Expansion

GPIO Inputs and Outputs
pin | Functions
VCC | 3.3V supply output
DAC0* | GPIO, Analog input, analog output
A1 | GPIO, Analog input, interrupt
A2 | GPIO, Analog input, interrupt
A5 | GPIO, Analog input
A6 | GPIO, Analog input
0 | GPIO, PWM, interrupt
1 | GPIO, PWM, interrupt
2 | GPIO, PWM, interrupt
3 | GPIO, PWM, interrupt
4 | GPIO, PWM, interrupt
6 | GPIO, PWM, interrupt
7 | GPIO, PWM, interrupt
11 | GPIO, SDA
12 | GPIO, SCL
13 | GPIO, RX
14 | GPIO, TX
GND | Ground


### Ethernet Expansion

This information is board specific and can be found on the label of the ethernet expansion.
Mac ID: 60:52:D0:06:81:C8

This is how you would set up a webpage with the ethernet expansion
byte mac[] = {0x60, 0x52, 0xD0, 0x06, 0x81, 0xC8}; 
IPAddress ip(192, 168, 1, 177);
EthernetServer server(80) port


### Descrete Input/Output Module

24V
4 input
l1
l2
l3
l4

0V
2 outputs
l1
l2

Com
Com