#pragma once
#include <vector>
#include <cstdint>

using namespace std;

class Device {
public:
    Device();
    vector<uint16_t> read_samples();
};