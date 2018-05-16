#include "StepperPololu.h"
#include "Arduino.h"

StepperPololu::StepperPololu(byte directionPin,
                             byte stepPin,
                             byte resetPin,
                             byte mode0Pin, byte mode1Pin, byte mode2Pin) {
    this->directionPin = directionPin;
    this->stepPin = stepPin;
    this->resetPin = resetPin;
    this->mode0Pin = mode0Pin;
    this->mode1Pin = mode1Pin;
    this->mode2Pin = mode2Pin;

    pinMode(stepPin,      OUTPUT);
    pinMode(directionPin, OUTPUT);
    pinMode(resetPin,     OUTPUT);
    pinMode(mode0Pin,     OUTPUT);
    pinMode(mode1Pin,     OUTPUT);
    pinMode(mode2Pin,     OUTPUT);

    setMode(MODE_FULL);
    _setDirection(CW);
}

void StepperPololu::setMode(byte mode) {
    this->mode = mode;
    if (mode != MODE_FULL && mode != MODE_TWO   && 
        mode != MODE_FOUR && mode != MODE_EIGHT &&
        mode != MODE_SIX) {
        
        this->mode = MODE_FULL;
    }
    _writeMode();
}

byte StepperPololu::getMode() {
    return this->mode;
}

void StepperPololu::_writeMode() {
    digitalWrite(this->mode0Pin, this->mode & MODE_MASK_1);
    digitalWrite(this->mode1Pin, this->mode & MODE_MASK_2);
    digitalWrite(this->mode2Pin, this->mode & MODE_MASK_3);
    /*
     * resetting prevents missing stepps (page 7 (Microstep Select (MSx))
     * A4988 manual
     */
    reset();
}

void StepperPololu::reset() {
    digitalWrite(this->resetPin, LOW);
    digitalWrite(this->resetPin, HIGH);
    /*TODO ad delay afterwards if it's funky
     * though I doubt a stepp will be made too soon
     */
}

void StepperPololu::step() {
    digitalWrite(this->stepPin, LOW);
    digitalWrite(this->stepPin, HIGH);
    digitalWrite(this->stepPin, LOW);
}

void StepperPololu::toggleDirection() {
    this->direction = this->direction == CW ? CCW : CW;
    _writeDirection();
}

void StepperPololu::_setDirection(byte dir) {
    this->direction = dir;
}

byte StepperPololu::_getDirection() {
    return this->direction;
}

void StepperPololu::_writeDirection() {
    digitalWrite(this->directionPin, this->direction);
}



