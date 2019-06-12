#include "Scanner.h"

#include <iostream>

Scanner::Scanner()
    : currentState(UNINITIALIZED)
    , currentCalibratedState(IDLE)
{
}

Calibrated_State Scanner::HandleBusyState(Event ev)
{
    Calibrated_State result = BUSY;

    switch (ev)
    {
    case workDone:
        BusyExitActions();
        result = SENDINGSOLUTION;
        SendingSolutionEntryActions();
        break;
    default:
        break;
    }
    return result;
}

void Scanner::HandleCalibratedEvent(Event ev)
{
    switch(currentCalibratedState)    
    {
    case IDLE:
    	currentCalibratedState = HandleIdleState(ev);
    	break;
    case BUSY:
    	currentCalibratedState = HandleBusyState(ev);
    	break;
    case SENDINGSOLUTION:
        currentCalibratedState = HandleSendingSolutionState(ev);
        break;
     default:
        std::cerr << "ERROR: illegal/unhandled state with number: " << currentState;
        break;
    }
}

State Scanner::HandleCalibratedState(Event ev)
{
    State result = CALIBRATED;

    switch (ev)
    {
        case logError:
            CalibratedExitActions();
            result = UNINITIALIZED;
            UninitializedEntryActions();
            break;
        default:
            break;
    }
    return result;
}

State Scanner::HandleCalibratingState(Event ev)
{
    State result = CALIBRATING;

    switch (ev)
    {
        case calibratingDone:
            CalibratingExitActions();
            result = CALIBRATED;
            CalibratedEntryActions();
            IdleEntryActions();
            break;
        default:
            break;
    }
    return result;
}

void Scanner::HandleEvent(Event ev)
{
    switch (currentState)
    {
    case UNINITIALIZED:
        currentState = HandleUninitializedState(ev);
        break;
    case CALIBRATING:
    	currentState = HandleCalibratingState(ev);
    	break;
    case CALIBRATED:
    	currentState = HandleCalibratedState(ev);
    	break;
    default:
        std::cerr << "ERROR: illegal/unhandled state with number: " << currentState;
        break;
    };
}

Calibrated_State Scanner::HandleIdleState(Event ev)
{
    Calibrated_State result = IDLE;

    switch (ev)
    {
    case cmdStart:
        IdleExitActions();
        result = BUSY;
        BusyEntryActions();
        break;
    default:
        break;
    }
    return result;
}

Calibrated_State Scanner::HandleSendingSolutionState(Event ev)
{
    Calibrated_State result = SENDINGSOLUTION;

    switch (ev)
    {
    case sendComplete:
        SendingSolutionExitActions();
        result = IDLE;
        IdleEntryActions();
        break;
    default:
        break;
    }
    return result;
}

State Scanner::HandleUninitializedState(Event ev)
{
    State result = UNINITIALIZED;

    switch (ev)
    {
        case cmdCalibrate:
            UninitializedExitActions();
            result = CALIBRATING;
            CalibratingEntryActions();
            break;
        default:
            break;
    }
    return result;
}

void Scanner::BusyEntryActions()
{

}

void Scanner::BusyExitActions()
{

}

void Scanner::CalibratedEntryActions()
{
    currentCalibratedState = IDLE;
}

void Scanner::CalibratedExitActions()
{
    
}

void Scanner::CalibratingEntryActions()
{

}

void Scanner::CalibratingExitActions()
{

}

void Scanner::IdleEntryActions()
{

}

void Scanner::IdleExitActions()
{

}

void Scanner::SendingSolutionEntryActions()
{

}

void Scanner::SendingSolutionExitActions()
{

}

void Scanner::UninitializedEntryActions()
{

}

void Scanner::UninitializedExitActions()
{
    
}
