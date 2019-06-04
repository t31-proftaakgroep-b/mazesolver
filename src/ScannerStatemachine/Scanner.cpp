#include "Scanner.h"

#include <iostream>

Scanner::Scanner()
    : currentState(UNINITIALIZED)
    , currentCalibratedState(IDLE)
{
}

void Scanner::HandleEvent(Events ev)
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

void Scanner::HandleCalibratedEvents(Events ev)
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

States Scanner::HandleUninitializedState(Events ev)
{
    States result = UNINITIALIZED;

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

States Scanner::HandleCalibratingState(Events ev)
{
    States result = CALIBRATING;

    switch (ev)
    {
        case calibratingDone:
            CalibratingExitActions();
            result = CALIBRATING;
            IdleEntryActions();
            break;
        default:
            break;
    }
    return result;
}

States Scanner::HandleCalibratedState(Events ev)
{
    States result = CALIBRATED;

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

Calibrated_States Scanner::HandleIdleState(Events ev)
{
    Calibrated_States result = IDLE;

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

Calibrated_States Scanner::HandleBusyState(Events ev)
{
    Calibrated_States result = BUSY;

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

Calibrated_States Scanner::HandleSendingSolutionState(Events ev)
{
    Calibrated_States result = SENDINGSOLUTION;

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

void Scanner::UninitializedEntryActions()
{

}

void Scanner::UninitializedExitActions()
{
    
}

void Scanner::CalibratingEntryActions()
{

}

void Scanner::CalibratingExitActions()
{

}

void Scanner::CalibratedEntryActions()
{
    currentCalibratedState = IDLE;
}

void Scanner::CalibratedExitActions()
{
    
}

void Scanner::IdleEntryActions()
{

}

void Scanner::IdleExitActions()
{

}

void Scanner::BusyEntryActions()
{

}

void Scanner::BusyExitActions()
{

}

void Scanner::SendingSolutionEntryActions()
{

}

void Scanner::SendingSolutionExitActions()
{

}