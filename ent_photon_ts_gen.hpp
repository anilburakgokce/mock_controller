#pragma once
#include <queue>
#include <cstdint>
#include <random>

using namespace std;

class Entangled_Photon_Timestamps_Gen {
public:
    Entangled_Photon_Timestamps_Gen();
    void gen_timestamps(int count); // generated photons are represented as uint16_t for simulation purposes
    vector<uint16_t> read_buffer_noisy();
    void clear_buffer();

private:
    default_random_engine generator;
    uniform_int_distribution<uint16_t> distribution;

    // generated photons are stored in buffers for simulation purposes
    vector<uint16_t> buffer;

};