#ifndef SENSORS_H
#define SENSORS_H

#include "Pump.h"

class Sensors{
private:
    int pin;
    float data;
    String type = "Default";
    bool warning = false;
  
public:
    // Methods
    Sensors(int new_pin);
    String get_type();
    void set_data(float input);
    float get_data();
    void set_type(String new_type);
    
};

// Constructor
//Sensors::Sensors(String sensor_type, int new_pin){
//    // Gets the sensors name and the pin, then starts off the data set to 0 until real data comes in
//    pin = new_pin;
//    pinMode(pin, INPUT);
//    type = sensor_type;
//    data = 0;
//    Serial.print("Created sensor ");
//    Serial.println(type);
//}

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

void Sensors::set_data(float input){
    // Sets the data as the current data coming in
    data = input;
    // Based off of the type, do the correct conversion
    // Set the input as the converte input
    // Check the pump warning
}

float Sensors::get_data(){
    Serial.write(data); // Sends this to the computer through the port
    Serial.print("Data: ");
    Serial.println(data);
}

// No deconstructor because it is continously running

#endif 