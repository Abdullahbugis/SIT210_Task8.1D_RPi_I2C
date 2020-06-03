#include "Particle.h"
#include "dct.h"  
#include <Wire.h>
#define Address 0x05



int LightSensor = A3;
int analogVal;



void setup() {
    const uint8_t val = 0x01;
    dct_write_app_data(&val, DCT_SETUP_DONE_OFFSET, 1);
    
    
    Wire.begin(Address);
    Wire.onRequest(dataSent);
    pinMode(LightSensor, INPUT);

}

void loop() {
    delay(500);
}

void dataSent(){
    analogVal = analogRead(LightSensor);
    Wire.write(analogVal);
}
    
    
