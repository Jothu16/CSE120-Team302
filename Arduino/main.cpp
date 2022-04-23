
#include <P1_HSC.h> // Used for the analog input and output 24V
#include <Ethernet.h> 
#include <P1AM.h>
#include "Pump.h"
#include "Sensors.h"


// Declaring/initializing global variables 
bool on = true, off = false;

// Setting the pin values
int pump_pin = 14;


// Initializing the classes
Pump test_pump(14);
Sensors wind_direction(1);
Sensors ambient_temp(2);
Sensors solar_irradiance(3);
Sensors collector_inlet(4);
Sensors collector_outlet(5);
Sensors tank_inlet(6);
Sensors tank_outlet(10);
Sensors loop_pressure(11);
Sensors flow_meter(12);
Sensors wind_speed(13);


void setup() { 
    Serial.begin(115200);
    wind_direction.set_type("Wind_direction");
    ambient_temp.set_type("Ambient_temp");
    solar_irradiance.set_type("Solar_irradiance");
    collector_inlet.set_type("Collector_inlet");
    collector_outlet.set_type("Collector_outlet");
    tank_inlet.set_type("Tank_inlet");
    tank_outlet.set_type("Tank_outlet");
    loop_pressure.set_type("Loop_pressure");
    flow_meter.set_type("Flow_meter");
    wind_speed.set_type("Wind_speed");
}

void loop() {
  
    wind_direction.set_data();  // Sends the data to be filtered
    wind_direction.get_data();  // Prints the data back out
    Serial.print(", ");
    ambient_temp.set_data();  // Sends the data to be filtered
    ambient_temp.get_data();  // Prints the data back out
    Serial.print(", ");
    solar_irradiance.set_data();  // Sends the data to be filtered
    solar_irradiance.get_data();  // Prints the data back out
    Serial.print(", ");
    collector_inlet.set_data();  // Sends the data to be filtered
    collector_inlet.get_data();  // Prints the data back out
    Serial.print(", ");
    collector_outlet.set_data();  // Sends the data to be filtered
    collector_outlet.get_data();  // Prints the data back out
    Serial.print(", ");
    tank_inlet.set_data();  // Sends the data to be filtered
    tank_inlet.get_data();  // Prints the data back out
    Serial.print(", ");
    tank_outlet.set_data();  // Sends the data to be filtered
    tank_outlet.get_data();  // Prints the data back out
    Serial.print(", ");
    loop_pressure.set_data();  // Sends the data to be filtered
    loop_pressure.get_data();  // Prints the data back out
    Serial.print(", ");
    flow_meter.set_data();  // Sends the data to be filtered
    flow_meter.get_data();  // Prints the data back out
    Serial.print(", ");
    wind_speed.set_data();  // Sends the data to be filtered
    wind_speed.get_data();  // Prints the data back 
    Serial.print(", ");
    test_pump.get_status();
    Serial.println("");

    // Setting a delay
    delay(1000);
}
