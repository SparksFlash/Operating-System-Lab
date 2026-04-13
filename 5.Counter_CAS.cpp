// CAS example: multiple threads increment a global counter using compare-and-swap
#include<bits/stdc++.h>
using namespace std;

atomic<int> counter{0};

void worker(int ops) {
    for (int i = 0; i < ops; ++i) {
        int expected = counter.load(memory_order_relaxed);
        
        while (!counter.compare_exchange_weak(expected, expected + 1,
                                              memory_order_acq_rel,
                                              memory_order_relaxed)) {

            this_thread::yield();
        }
    }
}

int main() {
    const int num_threads = 4;
    const int ops_per_thread = 100000;

    vector<thread> threads;
    for (int i = 0; i < num_threads; ++i)
        threads.emplace_back(worker, ops_per_thread);

    for (auto &t : threads) t.join();

    cout << "Expected final counter: " << (num_threads * ops_per_thread) << '\n';
    cout << "Actual final counter:   " << counter.load() << '\n';
}
