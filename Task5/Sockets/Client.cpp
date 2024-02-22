#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fstream>

int main() {
    // Create socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Error: Failed to create socket\n";
        return 1;
    }

    // Connect to server
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error:  connection failed\n";
        close(clientSocket);
        return 1;
    }

    // Read modified value 
    int modifiedValue;
    read(clientSocket, &modifiedValue, sizeof(modifiedValue));

    // Print modified value to file
    std::ofstream outputFile("client_output.txt");
    if (outputFile.is_open()) {
        outputFile << "Modified value: " << modifiedValue << std::endl;
        outputFile.close();
    }
    else {
        std::cerr << "Error: Failed to open output file\n";
    }

    // Close socket
    close(clientSocket);

    return 0;
}