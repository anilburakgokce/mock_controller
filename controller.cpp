#include "controller.hpp"
#include <chrono>
#include <iostream>

Controller::Controller(){}

Controller::Controller(Entangled_Photon_Timestamps_Gen *ts_gen) {
    static mutex ts_gen_mtx;
    {
        lock_guard<mutex> lock(ts_gen_mtx);
        this->ts_gen = ts_gen;
        this->device = Device(ts_gen);
    }
}

void Controller::acquire(int acquisition_id) {
    auto start = chrono::high_resolution_clock::now();

    auto data = device.read_samples();

    {
        lock_guard<mutex> lock(mtx);
        buffer.insert(buffer.end(), data.begin(), data.end());
    }

    auto end = chrono::high_resolution_clock::now();
    auto us = chrono::duration_cast<chrono::microseconds>(end - start).count();

    static mutex cout_mtx;
    {
        lock_guard<mutex> lock(cout_mtx);
        cout << "Acq" << acquisition_id << ": Acquisition took " << us << " us\n";
    }

}

void Controller::get_ts_from_device(){
    ts_buffer = this->device.read_timestamps_delayed();
}

vector<uint16_t> Controller::read_ts_buffer(){
    return ts_buffer;
}