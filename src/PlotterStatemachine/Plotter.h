#ifndef PLOTTER_H
#define PLOTTER_H

#include "Events.h"
#include "States.h"


class Plotter
{
    public:
        Plotter();
        void HandleEvent(Event ev);
        State HandleUninitializedState(Event ev);
        State HandleCalibratingState(Event ev);
        State HandleCalibratedState(Event ev);
        void HandleCalibratedEvent (Event ev);
        Calibrated_State HandleIdleState(Event ev);
        Calibrated_State HandleBusyState(Event ev); 
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
};

#endif
