
#include <P1_HSC.h> // Used for the analog input and output 24V
#include <Ethernet.h> 
#include <P1AM.h>
#include "Pump.h"
#include "Sensors.h"


// Declaring/initializing global variables 
bool on = true, off = false;
int wind_direction_data = 0;
String sensor1 = "Wind direction";

// Setting the pin values
int pump_pin = 14;
int wind_direction_pin = 10;

// Initializing the classes
Pump test_pump(on);
Sensors wind_direction(wind_direction_pin);

void setup() { 
    Serial.begin(115200);
    wind_direction.set_type("Wind_direction");
}

void loop() {
  
    // Testing Pump
    test_pump.set(off);
    test_pump.set(on);
    
    // Testing the Sensots class
    wind_direction.set_data();  // Sends the data to be filtered
    wind_direction.get_data();  // Prints the data back out
    wind_direction.get_type();  // Tells me what sensor it is

    // Setting a delay
    delay(1000);
}
