#pragma once

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
