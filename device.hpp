#include <vector>
#include <cstdint>

using namespace std;

class Device {
public:
    Device();
    std::vector<uint16_t> read_samples();
};