#include "Plotter.h"

Plotter::Plotter()
    : currentState(UNINITIALIZED)
    , currentCalibratedState(IDLE)
{
}

Calibrated_State Plotter::HandleBusyState(Event ev)
{
    Calibrated_State result = BUSY;

    switch (ev)
    {
    case workDone:
        BusyExitActions();
        result = IDLE;
        IdleEntryActions();
        break;
    default:
        break;
    }
    return result;
}

void Plotter::HandleCalibratedEvent(Event ev)
{
    switch(currentCalibratedState)    
    {
    case IDLE:
    	currentCalibratedState = HandleIdleState(ev);
    	break;
    case BUSY:
    	currentCalibratedState = HandleBusyState(ev);
    	break;
     default:
        std::cerr << "ERROR: illegal/unhandled state with number: " << currentState;
        break;
    }
}

State Plotter::HandleCalibratedState(Event ev)
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

State Plotter::HandleCalibratingState(Event ev)
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

void Plotter::HandleEvent(Event ev)
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

Calibrated_State Plotter::HandleIdleState(Event ev)
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

State Plotter::HandleUninitializedState(Event ev)
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

void Plotter::BusyEntryActions()
{

}

void Plotter::BusyExitActions()
{

}

void Plotter::CalibratedEntryActions()
{
    currentCalibratedState = IDLE;
}

void Plotter::CalibratedExitActions()
{
    
}

void Plotter::CalibratingEntryActions()
{

}

void Plotter::CalibratingExitActions()
{

}

void Plotter::IdleEntryActions()
{

}

void Plotter::IdleExitActions()
{

}

void Plotter::UninitializedEntryActions()
{

}

void Plotter::UninitializedExitActions()
{
    
}