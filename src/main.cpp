#include "Arduino.h"
#include "StepperPololu.h"

#define PIN_DIR   6
#define PIN_STEP  7
#define PIN_RST   9
#define PIN_MODE0 2
#define PIN_MODE1 3
#define PIN_MODE2 4

StepperPololu st(PIN_DIR, PIN_STEP, PIN_RST, PIN_MODE0, PIN_MODE1, PIN_MODE2);
void setup() {
    st.setMode(StepperPololu::MODE_SIX);
}

void loop() {
    st.step();
    delayMicroseconds(20);
}
