#ifndef STATES_H
#define STATES_H

enum State
{
    UNINITIALIZED,
    CALIBRATING,
    CALIBRATED  
};

enum Calibrated_State
{
    IDLE,
    BUSY,
    SENDINGSOLUTION
};

#endif