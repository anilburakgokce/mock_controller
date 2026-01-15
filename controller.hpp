#pragma once
#include "device.hpp"
#include <vector>
#include <mutex>
#include "ent_photon_ts_gen.hpp"

using namespace std;

class Controller {
public:
    Controller();
    Controller(Entangled_Photon_Timestamps_Gen *ts_gen);
    void acquire(int acquisition_id);
    vector<uint16_t> read_ts_buffer();
    void get_ts_from_device();

private:
    Device device;
    vector<uint16_t> buffer;
    vector<uint16_t> ts_buffer;
    mutex mtx;
    Entangled_Photon_Timestamps_Gen *ts_gen;
};