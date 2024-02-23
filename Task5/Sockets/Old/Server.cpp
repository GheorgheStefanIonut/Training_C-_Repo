#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fstream>

int main() {
    // Create socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Error: Failed to create socket\n";
        return 1;
    }

    // Bind socket to address
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error: Failed to bind socket\n";
        close(serverSocket);
        return 1;
    }

    // Listen for connections
    if (listen(serverSocket, 1) < 0) {
        std::cerr << "Error: Failed to listen for connections\n";
        close(serverSocket);
        return 1;
    }

    // Accept client connection
    sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientAddrSize);
    if (clientSocket < 0) {
        std::cerr << "Error: Failed to accept client connection\n";
        close(serverSocket);
        return 1;
    }

    // Modify shared value
    int sharedValue = 0;
    sharedValue += 10;

    // Print modified value to file
    std::ofstream outputFile("server_output.txt");
    if (outputFile.is_open()) {
        outputFile << "Modified value: " << sharedValue << std::endl;
        outputFile.close();
    }
    else {
        std::cerr << "Error: Failed to open output file\n";
    }

    // Close sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}