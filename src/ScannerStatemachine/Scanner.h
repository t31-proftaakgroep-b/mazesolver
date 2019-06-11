#ifndef SCANNER_H
#define SCANNER_H

#include "Events.h"
#include "States.h"


class Scanner
{
    public:
        Scanner();
        void HandleEvent(Event ev);
        State HandleUninitializedState(Event ev);
        State HandleCalibratingState(Event ev);
        State HandleCalibratedState(Event ev);
        void HandleCalibratedEvent (Event ev);
        Calibrated_State HandleIdleState(Event ev);
        Calibrated_State HandleBusyState(Event ev);
        Calibrated_State HandleSendingSolutionState(Event ev); 
    private:
        State currentState;
        Calibrated_State currentCalibratedState;

        void UninitializedEntryActions();
        void UninitializedExitActions();
        void CalibratingEntryActions();
        void CalibratingExitActions();
        void CalibratedEntryActions();
        void CalibratedExitActions();
        void IdleEntryActions();
        void IdleExitActions();
        void BusyEntryActions();
        void BusyExitActions();
        void SendingSolutionEntryActions();
        void SendingSolutionExitActions();

        


};

#endif
