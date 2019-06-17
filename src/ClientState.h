#pragma once
#include<vector>

enum ClientState
{
    Idle,
    Busy,
    Done
};

const std::vector<std::string> ClientStateString {"Idle", "Busy", "Done"};