#include "device.hpp"
#include <vector>
#include <mutex>

class Controller {
public:
    Controller();
    void acquire();

private:
    Device device_;
    std::vector<uint16_t> buffer_;
    std::mutex mtx_;
};