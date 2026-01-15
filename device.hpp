#pragma once
#include <vector>
#include <cstdint>
#include <random>
#include <mutex>
#include "ent_photon_ts_gen.hpp"

using namespace std;

class Device {
public:
    Device();
    Device(Entangled_Photon_Timestamps_Gen *ts_gen);
    vector<uint16_t> read_samples();
    vector<uint16_t> read_timestamps_delayed();

private:
    default_random_engine generator;
    uniform_int_distribution<uint16_t> distribution;

    Entangled_Photon_Timestamps_Gen *ts_gen;
};