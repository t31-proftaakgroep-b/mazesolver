#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <stdint.h>
#include <string>

const uint16_t PortNumber = 1135;
const std::string AckMessage = "ACK";
const std::string NackMessage = "NACK";
const int BufferSize = 100;

#endif