
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
int wind_direction_data = 0;

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
  
    // Testing Pump
    test_pump.set(off);
    test_pump.set(on);
    test_pump.get_status();

    // Testing the Sensots class
    wind_direction_data = analogRead(wind_direction_pin); // Reads the sensor values
    wind_direction_data = map(wind_direction_data, 0, 1023, 0, 255); // Sets a range for the inputs
    wind_direction.set_data(wind_direction_data);   // Sends the data to be filtered
    wind_direction.get_data(); // Prints the data back out
    wind_direction.get_type();  // Tells me what sensor it is

    // Setting a delay so it doesn't overload
    delay(500);
}

/*
Might add a loop that takes in the sensors in a vector then cycles through them


    for (i in vector size){
        current_data = analogRead(sensor pin);
        vector[i].set_data(current_data);
        vector[i].get_data();
    }

*/