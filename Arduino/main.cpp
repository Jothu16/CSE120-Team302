
#include <P1_HSC.h> // Used for the analog input and output 24V
#include <Ethernet.h> 
#include <P1AM.h>
#include "Pump.h"
#include "Sensors.h"


// Declaring/initializing global variables 
bool on = true, off = false;

// Setting the pin values
int pump_pin = 14;
int wind_direction_pin = 13;

// Initializing the classes
Pump test_pump(on);
Sensors wind_direction("wind direction", wind_direction_pin);

void setup() { 
    //Setting up the inputs/outputs
    pinMode(pump_pin, OUTPUT);
    pinMode(wind_direction_pin, INPUT);
}

void loop() {
    // Baud set to 115200
    Serial.begin(115200);
  
    // Testing
    test_pump.set(off);
    test_pump.set(on);


    // Setting a delay so it doesn't overload
    delay(500);
}