#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// Extern variable
extern int sharedNrOfCars;

// Mutex for sync
std::mutex mtx;

// Condition variable for observer notification
std::condition_variable cv;

// Observer class
class Observer {
public:
    // Observer update method
    void update(int newValue) {
        std::cout << "Observer: New value of sharedNrOfCars is " << newValue << std::endl;
    }
};

// Task for the threads
void task(Observer& observer) {
    // Lock mutex for exclusive access to sharedNrOfCars
    std::unique_lock<std::mutex> lock(mtx);

    int value = sharedNrOfCars;
    value++;
    std::cout << "Thread " << std::this_thread::get_id() << ": Modified value is " << value << std::endl;

    // Update the extern variable
    sharedNrOfCars = value;

    // Notify observer
    observer.update(value);

    // Notify condition variable for observer notification
    cv.notify_one();
}

int main() {
    sharedNrOfCars = 0;

    // Create observer
    Observer observer;

    std::thread thread1(task, std::ref(observer));
    std::thread thread2(task, std::ref(observer));

    // Join threads
    thread1.join();
    thread2.join();

    // Print the synchronized value of sharedNrOfCars
    std::cout << "Thread sync: " << sharedNrOfCars << std::endl;

    return 0;
}