#pragma once

#include <stdint.h>
#include <string>

const uint16_t PortNumber = 1135;
const std::string AckMessage = "ACK";
const std::string NackMessage = "NACK";
const int BufferSize = 100;

const std::string GetCurrentState = "GET STATE";

const std::string PlotterPrintSolution = "PRINT SOLUTION";
const std::string PlotterReceiveSolution = "RECEIVE SOLUTION";

const std::string ScannerScanMaze = "SCAN MAZE";
const std::string ScannerSave = "SAVE FILE";
const std::string ScannerSendFile = "SEND FILE";

