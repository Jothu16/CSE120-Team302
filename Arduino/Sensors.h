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
    void set_data();
    float get_data();
    void set_type(String new_type);
    
};

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
    //data = map(wind_direction_data, 0, 1023, 0, 255); // Sets a range for the inputs
    data = analogRead(pin);
    data = map(data, 0, 1023, 0, 255);
    
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
    Serial.print("Data: ");
    Serial.println(data);
}

#endif 