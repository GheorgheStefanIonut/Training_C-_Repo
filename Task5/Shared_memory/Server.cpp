#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <fstream>
#include <cstring> // Added for memset

int main() {
    // Create shared memory
	//int shm_open(const char *name, int oflag, mode_t mode);
    int sharedMemoryFd = shm_open("/shared_memory", O_CREAT | O_RDWR, 0666);
    if (sharedMemoryFd  < 0) {
        std::cerr << "Error: Failed to create shared memory\n";
        return 1;
    }
    
    // Set the size of the shared memory
	// int ftruncate(int fd, off_t length);
    if (ftruncate(sharedMemoryFd, sizeof(int))  < 0) {
        std::cerr << "Error: Failed to set the size of shared memory\n";
        close(sharedMemoryFd);
        shm_unlink("/shared_memory");
        return 1;
    }
    
    // Map the shared memory
	//void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
    int* sharedValue = (int*)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, sharedMemoryFd, 0);
    if (sharedValue == MAP_FAILED) {
        std::cerr << "Error: Failed to map shared memory\n";
        close(sharedMemoryFd);
        shm_unlink("/shared_memory");
        return 1;
    }
    
	// Initialize shared memory
    memset(sharedValue, 0, sizeof(int)); // Zero-initialize shared memory

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
	//int munmap(void *addr, size_t length);
    munmap(sharedValue, sizeof(int));
    close(sharedMemoryFd);
    
    // Unlink shared memory
	//int shm_unlink(const char *name);
    //shm_unlink("/shared_memory");		//it should persist until explicitly unlinked

    return 0;
}