#include "controller.hpp"
#include <thread>
#include <vector>

using namespace std;

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