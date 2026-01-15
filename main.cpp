#include "controller.hpp"
#include "ent_photon_ts_gen.hpp"
#include <thread>
#include <vector>
#include <iostream>

using namespace std;

#if 0
int main(){
    int num_threads_hint = thread::hardware_concurrency();
    const int num_threads = num_threads_hint ? num_threads_hint : 1;
    vector<thread> threads;

    Controller ctrl;
    
    for(int i = 0; i < num_threads; i++) {
        threads.emplace_back([&ctrl, i]() {
            ctrl.acquire(i);
        });
    }

    for(auto& t : threads) {
        t.join();
    }

    return 0;
}

#else
// the part to run for timestamp reading

int main(){
    // init ts generator and generate ts
    Entangled_Photon_Timestamps_Gen ts_gen;
    ts_gen.gen_timestamps(16);

    Controller ctrl1(&ts_gen), ctrl2(&ts_gen);
    
    thread t1_get([&ctrl1]() {
        ctrl1.get_ts_from_device();
    });    
    thread t2_get([&ctrl2]() {
        ctrl2.get_ts_from_device();
    });

    t1_get.join();
    vector<uint16_t> d1_ts = ctrl1.read_ts_buffer();
    t2_get.join();
    vector<uint16_t> d2_ts = ctrl2.read_ts_buffer();

    for (auto i: d1_ts)
        cout << i << ' ';
    cout << endl;
    for (auto i: d2_ts)
        cout << i << ' ';
    cout << endl;

    return 0;
}


#endif