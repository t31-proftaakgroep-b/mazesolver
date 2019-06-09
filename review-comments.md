# Algemeen

* De top-level makefile doet het (nog steeds) niet
* https://github.com/kees-jan/ptt3/wiki/Gebruik-geen-..-in-%23includes
* https://github.com/kees-jan/ptt3/wiki/pragma-once
* Kijk nog eens terug naar het commentaar van Sander. Nog niet alles is verwerkt

# PlotterStateMachine, ScannerStateMachine

* Zit netjes in elkaar. Let wel op dat hij niet teveel verantwoordelijkheden krijgt.
* Als je een enum definieert, gebruik dan altijd enkelvoud als typenaam
* Hoe moet de gebruiker weten of hij HandleEvent() moet aanroepen of HandleCalibratedEvents() ? Ik zou eigenlijk verwachten dat de HandleCalibratedState() method zelf HandleCalibratedEvents() zou aanroepen

