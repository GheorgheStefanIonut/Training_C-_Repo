#include <iostream>
#include <thread>
#include <mutex>

// Extern variable
extern int sharedNrOfCars;

// Mutex for sync
std::mutex mtx;

// Task for the threads
void task() {

    // Lock mutex for exclusive access to sharedNrOfCars
    mtx.lock();

    int value = sharedNrOfCars;
    value++;
    std::cout << "Thread " << std::this_thread::get_id() << ": Modified value is " << value << std::endl;

    // Update the extern variable
    sharedNrOfCars = value;

    // mutex unlock 
    mtx.unlock();
}

int main() {
    sharedNrOfCars = 0;
    std::thread thread1(task);
    std::thread thread2(task);

    // Join  threads
    thread1.join();
    thread2.join();

    return 0;
}