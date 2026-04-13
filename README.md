# Operating-System-Lab

This repository contains small C++ examples demonstrating concurrency concepts.

1. 1.Race_Condition.cpp
   - Demonstrates a race condition when multiple threads update a shared variable
   - Compile: `g++ -std=c++17 1.Race_Condition.cpp -o output/1.Race_Condition`
   - Run: `./output/1.Race_Condition`

2. 2.Peterson's_Solution.cpp
   - Implements Peterson's algorithm for mutual exclusion between two threads
   - Compile: `g++ -std=c++17 2.Peterson's_Solution.cpp -o output/2.Peterson's_Solution`
   - Run: `./output/2.Peterson's_Solution`

3. 3.Writing_logs.cpp
   - Shows synchronized logging / writing to shared output to avoid interleaving
   - Compile: `g++ -std=c++17 3.Writing_logs.cpp -o output/3.Writing_logs`
   - Run: `./output/3.Writing_logs`

4. 4.Bank.cpp
   - ATM/bank example that uses a low-level spinlock (`std::atomic_flag`) to protect a shared `balance`
   - Compile: `g++ -std=c++17 4.Bank.cpp -o output/4.Bank`
   - Run: `./output/4.Bank`

5. 5.Counter_CAS.cpp
   - Uses Compare-And-Swap (`std::atomic::compare_exchange_weak`) to implement a lock-free increment counter
   - Compile: `g++ -std=c++17 5.Counter_CAS.cpp -O2 -o output/5.Counter_CAS`
   - Run: `./output/5.Counter_CAS`

Notes:
- The `output/` directory is used for compiled binaries. Create it if missing: `mkdir -p output`.
- For small experiments prefer `-std=c++17` and `-O2` for the CAS example.

