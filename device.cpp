#include "device.hpp"
#include <random>
#include <thread>
#include <chrono>

Device::Device() {}

vector<uint16_t> Device::read_samples() {
    this_thread::sleep_for(chrono::microseconds(10)); // hw latency

    default_random_engine generator;
    uniform_int_distribution<int> distribution(numeric_limits<uint16_t>::min(),numeric_limits<uint16_t>::max());

    vector<uint16_t> samples;
    for(int i = 0; i < 5; i++){
        samples.push_back(distribution(generator));
    }

    return samples;
}