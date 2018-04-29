#include "ticks.hpp"

const int RADIATION_PORT = 8;

char MESSAGE_BUFFER[50];
int last_state = LOW;
int current_state = LOW;
int loop_counter = 0;
long state_counter=0;
const int REPORT_FREQUENCY = 500000;
const int SERIAL_BAUD_RATE=9600;


void setup() {
    // put your setup code here, to run once:
    Serial.begin(SERIAL_BAUD_RATE);
    pinMode(LED_BUILTIN,OUTPUT);
    pinMode(RADIATION_PORT,INPUT);
}

void loop() {
    int current_state = digitalRead(RADIATION_PORT);
    if(current_state != last_state){
        state_counter+=1;
        digitalWrite(LED_BUILTIN, current_state);
    }
    if((loop_counter % REPORT_FREQUENCY) == 0){
        int curr_state = (state_counter+1)/2;
        sprintf(MESSAGE_BUFFER,"{radiation_ticks: %ld}",curr_state);
        Serial.println(MESSAGE_BUFFER);
        Serial.flush();
        loop_counter=1;
        state_counter=0;
        last_state=0;
    }
    last_state=current_state;
    loop_counter+=1;
}