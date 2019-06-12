#pragma once

#include "Events.h"
#include "States.h"

class Scanner
{
    public:
        Scanner();        
        Calibrated_State HandleBusyState(Event ev);
        void HandleCalibratedEvent (Event ev);
        State HandleCalibratedState(Event ev);
        State HandleCalibratingState(Event ev);
        void HandleEvent(Event ev);
        Calibrated_State HandleIdleState(Event ev);
        Calibrated_State HandleSendingSolutionState(Event ev); 
        State HandleUninitializedState(Event ev);
    
    private:
        State currentState;
        Calibrated_State currentCalibratedState;
        
        void BusyEntryActions();
        void BusyExitActions();
        void CalibratedEntryActions();
        void CalibratedExitActions();
        void CalibratingEntryActions();
        void CalibratingExitActions();
        void IdleEntryActions();
        void IdleExitActions();
        void SendingSolutionEntryActions();
        void SendingSolutionExitActions();
        void UninitializedEntryActions();
        void UninitializedExitActions();
};

