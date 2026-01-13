#include "controller.hpp"
#include <chrono>
#include <iostream>

Controller::Controller() {}

void Controller::acquire(int acquisition_id) {
    auto start = chrono::high_resolution_clock::now();

    auto data = device_.read_samples();

    {
        lock_guard<mutex> lock(mtx_);
        buffer_.insert(buffer_.end(), data.begin(), data.end());
    }

    auto end = chrono::high_resolution_clock::now();
    auto us = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "Acq" << acquisition_id << ": Acquisition took " << us << " us\n";
}