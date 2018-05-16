#ifndef STEPPER_POLOLU_H_INCLUDED
#define STEPPER_POLOLU_H_INCLUDED

class StepperPololu {
    public:
        typedef unsigned char byte;

        // step resolution modes
        static const byte MODE_FULL  = 0;
        static const byte MODE_TWO   = 1;
        static const byte MODE_FOUR  = 2;
        static const byte MODE_EIGHT = 3;
        static const byte MODE_SIX   = 7;

        StepperPololu(byte directionPin, 
                      byte stepPin, 
                      byte resetPin, 
                      byte mode0Pin, 
                      byte mode1Pin, 
                      byte mode2Pin);

        void setMode(byte mode);
        byte getMode();

        void step();

        void toggleDirection();

        void reset();


    private:
        // used for direction
        static const byte CW = 0;
        static const byte CCW = 1;
        // masks for addressing each mode bit
        static const byte MODE_MASK_1 = 01;
        static const byte MODE_MASK_2 = 02;
        static const byte MODE_MASK_3 = 04;

        byte directionPin;
        byte stepPin;
        byte resetPin;
        byte mode0Pin;
        byte mode1Pin;
        byte mode2Pin;

        byte direction;
        byte mode;

        void _writeMode();
        void _setDirection(byte dir);
        byte _getDirection();
        void _writeDirection();
};

#endif

