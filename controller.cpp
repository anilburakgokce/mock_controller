#include "controller.hpp"
#include <chrono>
#include <iostream>

Controller::Controller() {}

void Controller::acquire() {
    auto start = std::chrono::high_resolution_clock::now();

    auto data = device_.read_samples();

    {
        std::lock_guard<std::mutex> lock(mtx_);
        buffer_.insert(buffer_.end(), data.begin(), data.end());
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << "Acquisition took " << us << " us\n";
}