#include "Plotter.h"

#include <iostream>

Plotter::Plotter()
    : currentState(UNINITIALIZED)
    , currentCalibratedState(IDLE)
{
}

void Plotter::HandleEvent(Events ev)
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

void Plotter::HandleCalibratedEvents(Events ev)
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

States Plotter::HandleUninitializedState(Events ev)
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

States Plotter::HandleCalibratingState(Events ev)
{
    States result = CALIBRATING;

    switch (ev)
    {
        case calibratingDone:
            CalibratingExitActions();
            result = CALIBRATING; // Je bedoelt Calibrated?
            // En hier dan ook de CalibratedEntryActons ?
            // Anders staat de currentCalibratedState mogelijk fout
            IdleEntryActions();
            break;
        default:
            break;
    }
    return result;
}

States Plotter::HandleCalibratedState(Events ev)
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

Calibrated_States Plotter::HandleIdleState(Events ev)
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

Calibrated_States Plotter::HandleBusyState(Events ev)
{
    Calibrated_States result = BUSY;

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

void Plotter::UninitializedEntryActions()
{

}

void Plotter::UninitializedExitActions()
{
    
}

void Plotter::CalibratingEntryActions()
{

}

void Plotter::CalibratingExitActions()
{

}

void Plotter::CalibratedEntryActions()
{
    currentCalibratedState = IDLE;
}

void Plotter::CalibratedExitActions()
{
    
}

void Plotter::IdleEntryActions()
{

}

void Plotter::IdleExitActions()
{

}

void Plotter::BusyEntryActions()
{

}

void Plotter::BusyExitActions()
{

}
