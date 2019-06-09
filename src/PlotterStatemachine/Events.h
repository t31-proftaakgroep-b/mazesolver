#ifndef EVENTS_H
#define EVENTS_H

// Noem dit type Event (enkelvoud) i.p.v. Events. Een variabele van dit type bevat altijd maar 1 event
enum Events
{
    cmdCalibrate,
    calibratingDone,
    cmdStart,
    workDone,
    logError
};

#endif
