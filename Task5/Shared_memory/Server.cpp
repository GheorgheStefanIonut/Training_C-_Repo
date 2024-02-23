#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <fstream>

int main() {
    // Create shared memory
    int sharedMemoryFd = shm_open("/shared_memory", O_CREAT | O_RDWR, 0666);
    if (sharedMemoryFd  < 0) {
        std::cerr << "Error: Failed to create shared memory\n";
        return 1;
    }
    
    // Set the size of the shared memory
    if (ftruncate(sharedMemoryFd, sizeof(int))  < 0) {
        std::cerr << "Error: Failed to set the size of shared memory\n";
        close(sharedMemoryFd);
        shm_unlink("/shared_memory");
        return 1;
    }
    
    // Map the shared memory
    int* sharedValue = (int*)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, sharedMemoryFd, 0);
    if (sharedValue == MAP_FAILED) {
        std::cerr << "Error: Failed to map shared memory\n";
        close(sharedMemoryFd);
        shm_unlink("/shared_memory");
        return 1;
    }
    
    // Modify shared value
    *sharedValue = 100;

    // Print modified value to file
    std::ofstream outputFile("server_output.txt");
    if (outputFile.is_open()) {
        outputFile << "Server modified value: " << *sharedValue << std::endl;
        outputFile.close();
    }
    else {
        std::cerr << "Error: Failed to open output file\n";
    }

    // Unmap and close shared memory
    munmap(sharedValue, sizeof(int));
    close(sharedMemoryFd);
    
    // Unlink shared memory
    shm_unlink("/shared_memory");

    return 0;
}