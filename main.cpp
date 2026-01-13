#include "controller.hpp"
#include <thread>
#include <vector>

using namespace std;

int main(){
    const int num_threads = 4;
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