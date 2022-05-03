

#ifndef PUMP_h
#define PUMP_h

#include "Arduino.h"

class Pump{
private:
    int pin; 
    bool pump_status = false;

public:
    // Methods
    Pump(int new_pin);
    void get_status();
    void set(bool set);
};


// Constructor
Pump::Pump(int new_pin){
    // Gets the pin associated with the pump and sets pump off by default
    pin = new_pin;
    pinMode(pin, OUTPUT);
    pump_status = false;
    digitalWrite(pin, LOW);
}


void Pump::set(bool set_to){
    // Sets the pump to the input on/off
    pump_status = set_to;

    // If the pump is set to on, turn the pump on
    if(pump_status == true){
        digitalWrite(pin, HIGH);
    }

    // Turns the pump off
    else{
        digitalWrite(pin, LOW);
    }
}

// Returns the pumps status on/off
void Pump::get_status(){
    if(pump_status == true){
      Serial.print("On");
    }
    else{
        Serial.print("Off");
    }
}

//Since it is constantly running, I don't think a deconstructor 

#endif