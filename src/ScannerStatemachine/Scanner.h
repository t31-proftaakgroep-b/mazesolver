#ifndef SCANNER_H
#define SCANNER_H

#include "Events.h"
#include "States.h"


class Scanner
{
    public:
        Scanner();
        void HandleEvent(Events ev);
            States HandleUninitializedState(Events ev);
            States HandleCalibratingState(Events ev);
            States HandleCalibratedState(Events ev);
        void HandleCalibratedEvents (Events ev);
            Calibrated_States HandleIdleState(Events ev);
            Calibrated_States HandleBusyState(Events ev);
            Calibrated_States HandleSendingSolutionState(Events ev); 
    private:
        States currentState;
        Calibrated_States currentCalibratedState;

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
