// 3. A file system allows multiple threads to write logs. 
// To prevent corruption: 
// i. Only one thread should write at a time  
// ii. Others should wait efficiently (no busy spinning)  
// Implement using C++

#include <bits/stdc++.h>
using namespace std;

void func(int i) {
    cout << i << endl;
}

int main() {
    thread t1(func, 1);
    t1.join();  
    
    thread t2(func, 2);
    t2.join();  
    return 0;
}