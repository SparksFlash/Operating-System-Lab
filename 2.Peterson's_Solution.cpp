// 2. Two processes update a shared database record. 
// The system designer wants a software-only solution (no hardware support) that ensures: 
// i. Mutual exclusion  
// ii. Fair turn/other-taking  
// Implement the solution in C++

#include <bits/stdc++.h>
using namespace std;

int shared_id = 0;

int turn = 0;
bool interested[2] = {false, false};

void func(int i) {
    interested[i] = true;
    turn = 1-i;
    while (interested[1-i] && turn == (1-i));

    int id = shared_id;
    id++;
    cout << id << endl;
    shared_id = id;

    interested[i] = false;
}

int main() {
    thread t1(func, 0);
    thread t2(func, 1);

    t1.join();  
    t2.join();  
    cout << "Main thread finished. ID -> " << shared_id << endl;
    return 0;
}