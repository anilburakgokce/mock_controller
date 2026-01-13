#include <vector>
#include <cstdint>

class Device {
public:
    Device();
    std::vector<uint16_t> read_samples();
};