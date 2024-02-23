#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <fstream>

int main() {
    // Open shared memory
    int sharedMemoryFd = shm_open("/shared_memory", O_RDONLY, 0666);
    if (sharedMemoryFd < 0) {
        std::cerr << "Error: Failed to open shared memory\n";
        return 1;
    }
    
    // Map the shared memory
    int* sharedValue = (int*)mmap(NULL, sizeof(int), PROT_READ, MAP_SHARED, sharedMemoryFd, 0);
    if (sharedValue == MAP_FAILED) {
        std::cerr << "Error: Failed to map shared memory\n";
        close(sharedMemoryFd);
        return 1;
    }
    
    // Print modified value to file
    std::ofstream outputFile("client_output.txt");
    if (outputFile.is_open()) {
        outputFile << "Client modified value: " << *sharedValue << std::endl;
        outputFile.close();
    }
    else {
        std::cerr << "Error: Failed to open output file\n";
    }

    // Unmap and close shared memory
    munmap(sharedValue, sizeof(int));
    close(sharedMemoryFd);

    return 0;
}