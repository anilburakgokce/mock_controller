#include "device.hpp"
#include <thread>
#include <chrono>
#include "ent_photon_ts_gen.hpp"
#include <iostream>

Device::Device(){ }

Device::Device(Entangled_Photon_Timestamps_Gen *ts_gen) {
    uniform_int_distribution<uint16_t> distribution(numeric_limits<uint16_t>::min(),numeric_limits<uint16_t>::max());

    static mutex ts_gen_mtx;
    {
        lock_guard<mutex> lock(ts_gen_mtx);
        this->ts_gen = ts_gen;
    }
}

vector<uint16_t> Device::read_samples() {
    this_thread::sleep_for(chrono::microseconds(10)); // hw latency

    vector<uint16_t> samples;
    for(int i = 0; i < 5; i++){
        samples.push_back(distribution(generator));
    }

    return samples;
}

// returns delayed the timestamp array for the acquired photons
vector<uint16_t> Device::read_timestamps_delayed(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> delay_distribution(1, 8);
    uint16_t delay = 1 + delay_distribution(gen) % 8; // delay max is 8 ms
    std::cout << delay << std::endl;

    this_thread::sleep_for(chrono::microseconds(10)); // hw latency

    vector<uint16_t> delayed_timestamps;
    static mutex ts_gen_mtx;
    {
        lock_guard<mutex> lock(ts_gen_mtx);
        delayed_timestamps = ts_gen->read_buffer_noisy();
    }


    for(int i = 0; i < delayed_timestamps.size(); i++){
        delayed_timestamps[i] += delay;
    }
    return delayed_timestamps;
}