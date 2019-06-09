#ifndef STATES_H
#define STATES_H

// Ook hier enkelvoud (State en Calibrated_State). Je zult zien dat de
// code die deze types gebruikt een stuk leesbaarder wordt.
enum States
{
    UNINITIALIZED,
    CALIBRATING,
    CALIBRATED  
};

enum Calibrated_States
{
    IDLE,
    BUSY,
};

#endif
