#include "ent_photon_ts_gen.hpp"

Entangled_Photon_Timestamps_Gen::Entangled_Photon_Timestamps_Gen(){ 
    uniform_int_distribution<uint16_t> distribution(numeric_limits<uint16_t>::min(),numeric_limits<uint16_t>::max());
}

void Entangled_Photon_Timestamps_Gen::gen_timestamps(int count){
    uint16_t current_time = 0; // in ms
    for(int i = 0; i < count; i++){
        uint16_t next_timestamp = current_time + 10 + distribution(generator) % 90; // lower and upper bound for the time between two timestamps are 10 and 100 ms
        buffer.push_back(next_timestamp);
        current_time = next_timestamp;
    }
}

vector<uint16_t> Entangled_Photon_Timestamps_Gen::read_buffer_noisy(){
    vector<uint16_t> timestamps;
    for(int i = 0; i < buffer.size(); i++){
        // add noise with 10% probability
        if(distribution(generator) % 10 == 0){
            uint16_t noise_between = buffer[i-1] + 1 + (distribution(generator) % (buffer[i+1] - buffer[i] - 1));
            timestamps.push_back(noise_between);
        }

        // add next buffer element
        timestamps.push_back(buffer[i]);
    }

    return timestamps;
}

void Entangled_Photon_Timestamps_Gen::clear_buffer(){
    buffer.clear();
}