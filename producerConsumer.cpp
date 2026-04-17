#include <bits/stdc++.h>
using namespace std;
#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0, cnt = 0;

mutex mtx;
condition_variable not_full;
condition_variable not_empty;

void producer() {
    while (true) {
        int item = rand() % 100; // produce an item

        unique_lock<mutex> lock(mtx);

        while (cnt == BUFFER_SIZE) // buffer full
            not_full.wait(lock);

        buffer[in] = item;
        cout << "Produced: " << item << " at " << in << endl;
        in = (in + 1) % BUFFER_SIZE;
        cnt++;

        not_empty.notify_one(); // signal buffer has item

        lock.unlock();

        this_thread::sleep_for(chrono::seconds(1)); // simulate production time
    }
}

void consumer() {
    while (true) {
        unique_lock<mutex> lock(mtx);

        while (cnt == 0) // buffer empty
            not_empty.wait(lock);

        int item = buffer[out];
        cout << "Consumed: " << item << " at " << out << endl;
        out = (out + 1) % BUFFER_SIZE;
        cnt--;

        not_full.notify_one(); // signal buffer has space

        lock.unlock();

        this_thread::sleep_for(chrono::seconds(1)); // simulate consumption time
    }
}

int main() {
    srand(time(0));
    thread prod(producer);
    thread cons(consumer);

    prod.join();
    cons.join();
}