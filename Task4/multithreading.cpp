#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

// Extern variable
extern int sharedNrOfCars;

// Mutex for sync
std::mutex mtx;

// Task for the threads
void task(std::ofstream& outputFile) {
    for (int i = 0; i < 5; ++i) 
{
        // Lock mutex for exclusive access to sharedNrOfCars
        std::lock_guard<std::mutex> lock(mtx);

        int value = sharedNrOfCars;
        value++;
        outputFile << "Thread " << std::this_thread::get_id() << ": Modified value is " << value << std::endl;

        // Update the extern variable
        sharedNrOfCars = value;
    }
}

int main() {
    sharedNrOfCars = 0;

    // file open
    std::ofstream outputFile("ThreadSync.txt");

    std::thread thread1(task, std::ref(outputFile));
    std::thread thread2(task, std::ref(outputFile));

    // Join  threads
    thread1.join();
    thread2.join();

 
    outputFile << "Thread sync: " << sharedNrOfCars << std::endl;

    // close file
    outputFile.close();

    return 0;
}