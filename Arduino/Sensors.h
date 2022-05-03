#ifndef SENSORS_H
#define SENSORS_H

#include "Pump.h"

class Sensors{
private:
    int pin;
    float data;
    String EngrUnit;
    String type = "Default";
    bool warning = false;

public:
    // Methods
    Sensors(int new_pin);
    String get_type();
    void set_data();
    float get_data();
    void set_type(String new_type);

};

// Constructor
Sensors::Sensors(int new_pin){
    // Gets the pin associated with the pump and sets pump off by default
    pin = new_pin;
    pinMode(pin, INPUT);
    data = 0;
}

String Sensors::get_type(){
    Serial.print("Type: ");
    Serial.println(type);
    return type;
}

void Sensors::set_type(String new_type){
    type = new_type;
}

void Sensors::set_data(){
    // Sets the data as the current data coming in
    //data = analogRead(wind_direction_pin); // Reads the sensor values
    //data = map(wind_direction_data, 0, 1023, 0, 255); // Sets a range for the inputs
    data = analogRead(pin);
    data = map(data, 0, 1023, 0, 255);

    switch(pin){ //MULTIPLIERS FOR Sensors
      case 1: //Wind_direction
        data = map(data, 0, 8, 0, 255);
        EngrUnit = "Volt";
        break;
      case 2: //ambient_temp
        data = map(data, 0, 12, 0, 255);
        EngrUnit = "C";
        break;
      case 3: //solar_irradiance
        data = map(data, -4, 1023, 0, 255);
        EngrUnit = "W/m2";
        break;
      case 4: // collector_inlet              Collector and tank data input and outputs usually follow each other
        data = map(data, 0, 89.88, 0, 255);
         float collector_inlet_data = data;
        EngrUnit = "C";
        break;
      case 5://collector_outlet
        if (collector_inlet_data > 30){
        data collector_inlet_data - 2.1;
      } else{ data = collector_inlet_data + 1.5; }
        EngrUnit = "C";
        break;
      case 6://tank_inlet
        data = map(data, 0, 91.23, 0, 255);
        float tank_inlet_data = data;
        EngrUnit = "C";
        break;
      case 10: //tank_outlet
      if (tank_inlet_data > 70){
       data = tank_inlet_data - 20;
     } else{ data = tank_inlet_data + 18.9; }
      EngrUnit = "C";
        break;
      case 11:// loop_pressure
        data = map(data, 51, 62, 0, 255);
        EngrUnit = "psig";
        break;
      case 12: //flow_meter
        data = 0
        int count = 0;
        if (data = 0){ count ++}
        if (count = 15){
          data = map(data, 0, 29, 0, 255);
          count = 0;
        }
        EngrUnit = "g/s";
        break;
      case 13://Wind_speed
        data = map(data, 483398, 540000, 0, 255);
        EngrUnit = "Cnts";
        break;
      case 14: // test_pump
        // nothing needs to happen here
        break;
    }
    // Based off of the type, do the correct conversion
    // Set the input as the converte input
    // Check the pump warning
    /*
     if(data <= 1){
         pump.set_status(on);
         Serial.write("Pump warning temp too low");
     }
     */
}

float Sensors::get_data(){
    //Serial.write(data); // Sends this to the computer through the port as bytes
    Serial.print("Data: ");
    Serial.print(data);
}

#endif
