// 4. A bank has implemented an ATM system where multiple users can access their accounts 
// simultaneously. Each transaction updates a shared variable called balance. 
// Recently, the bank noticed that sometimes the balance becomes incorrect when multiple users 
// withdraw or deposit money at the same time. 
// The system designer decides to use a low-level hardware-supported locking mechanism where: 
//  A lock variable is checked and set in one atomic step  
//  Threads repeatedly check the lock until it becomes free  
// Tasks 
// 1. Identify the synchronization technique used  
// 2. Write a C++ program to solve this problem


#include <bits/stdc++.h>
using namespace std;

int balance = 1000;
atomic_flag locker = ATOMIC_FLAG_INIT;

void acquire_locker() {
    while (locker.test_and_set(memory_order_acquire));
}

void release_locker() {
    locker.clear(memory_order_release);
}

void func() {
    acquire_locker();

    int local_bal = balance;
    local_bal++;
    cout << local_bal << endl;
    balance = local_bal;

    release_locker();
}

int main() {
    thread t1(func);
    thread t2(func);

    t1.join();  
    t2.join();  
    cout << "Final bal. -> " << balance << endl;
}