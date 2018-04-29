#ifndef Arduino
    #include <Arduino.h>
#endif

static volatile long TICKS_COUNTER = 0;
static volatile int TICKS_STATE = LOW;

static void ticks_counter() {
    TICKS_COUNTER += 1;
    TICKS_STATE = !TICKS_STATE;
}


