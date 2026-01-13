#pragma once
#include "device.hpp"
#include <vector>
#include <mutex>

using namespace std;

class Controller {
public:
    Controller();
    void acquire(int acquisition_id);

private:
    Device device_;
    vector<uint16_t> buffer_;
    mutex mtx_;
};