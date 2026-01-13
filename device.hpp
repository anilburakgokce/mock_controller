#pragma once
#include <vector>
#include <cstdint>
#include <random>

using namespace std;

class Device {
public:
    Device();
    vector<uint16_t> read_samples();

private:
    default_random_engine generator;
    uniform_int_distribution<uint16_t> distribution;
};