#ifndef SENSORS_H
#define SENSORS_H

#include "Pump.h"

class Sensors{
private:
    int pin;
    float data;
    String type;
    bool warning = false;
  
public:
    // Methods
    Sensors(String sensor_type, int new_pin); 
    String get_type();
    void set_data(float input);
    float get_data();
};

// Constructor
Sensors::Sensors(String sensor_type, int new_pin){
    // Gets the sensors name and the pin, then starts off the data set to 0 until real data comes in
    pin = new_pin;
    type = sensor_type;
    data = 0;
    Serial.print("Created sensor ");
    Serial.println(type);
}

String Sensors::get_type(){
    Serial.print("Type: ");
    Serial.println(type);
    return type;
}

void Sensors::set_data(float input){
    // Sets the data as the current data coming in
    data = input;
    // Based off of the type, do the correct conversion
    // Set the input as the converte input
    // Check the pump warning
}

float Sensors::get_data(){
    Serial.print("Data: ");
    Serial.println(data);
    return data;
}

// No deconstructor because it is continously running

#endif 