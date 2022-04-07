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
    bool get_status();
    void set(bool set);
};


// Constructor
Pump::Pump(int new_pin){
    // Gets the pin associated with the pump and sets pump off by default
    pin = new_pin;
    pinMode(pin, OUTPUT);
    pump_status = false;
    digitalWrite(pin, LOW);
    Serial.write("Pump has been turned on. Pump is set to off.")
}

void Pump::set(bool set_to){
    // Sets the pump to the input on/off
    pump_status = set_to;

    // If the pump is set to on, turn the pump on
    if(pump_status == true){
        digitalWrite(pin, HIGH);
        Serial.println("Pump set to on");
    }

    // Turns the pump off
    else{
        digitalWrite(pin, LOW);
        Serial.println("Pump set to off");
    }
}

// Returns the pumps status on/off
bool Pump::get_status(){
    Serial.write(pump_status); // Sends the status to the connected computer
    Serial.print("Pump status: ");
    Serial.print(pump_status);
}

//Since it is constantly running, I don't think a deconstructor 

#endif