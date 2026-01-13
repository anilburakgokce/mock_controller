#include "device.hpp"
#include <random>
#include <thread>
#include <chrono>

Device::Device() {}

std::vector<uint16_t> Device::read_samples() {
    std::this_thread::sleep_for(std::chrono::microseconds(10)); // hw latency
    return {1, 2, 3, 4, 5};
}