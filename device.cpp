#include "device.hpp"
#include <random>
#include <thread>
#include <chrono>

using namespace std;

Device::Device() {}

vector<uint16_t> Device::read_samples() {
    this_thread::sleep_for(chrono::microseconds(10)); // hw latency
    return {1, 2, 3, 4, 5};
}