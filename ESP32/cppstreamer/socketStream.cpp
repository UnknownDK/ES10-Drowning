#include <iostream>
#include <fstream>
#include <sstream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

#define HOST "0.0.0.0"
#define PORT 33333
#define CHUNK_SIZE 2048
#define MAX_FILE_SIZE (2 * 1024 * 1024) // 5 MB

std::string intToString(int value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

void receiveDataAndSave(SOCKET conn) {
    char buffer[CHUNK_SIZE];
    int bytesReceived = 0;
    std::ofstream outputFile;
    std::string fileName = "received_data_" + intToString(GetCurrentProcessId()) + ".txt";

    while (true) {
        // Receive data in chunks
        int bytes = recv(conn, buffer, CHUNK_SIZE, 0);
        if (bytes <= 0)
            break;

        outputFile.open(fileName, std::ios::out | std::ios::app | std::ios::binary);
        if (!outputFile.is_open()) {
            std::cerr << "Error opening file for writing." << std::endl;
            return;
        }
        outputFile.write(buffer, bytes);
        outputFile.close();

        bytesReceived += bytes;

        // Save to file if reached MAX_FILE_SIZE
        if (bytesReceived >= MAX_FILE_SIZE) {
            fileName = "received_data_" + intToString(GetCurrentProcessId()) + ".txt";
            bytesReceived = 0;
        }
    }
}

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed." << std::endl;
        return 1;
    }

    // Create a socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed." << std::endl;
        WSACleanup();
        return 1;
    }

    // Bind the socket to the host and port
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);
    if (bind(serverSocket, reinterpret_cast<SOCKADDR*>(&serverAddr), sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Listen failed." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server listening on " << HOST << ":" << PORT << std::endl;

    while (true) {
        // Accept connections from clients
        sockaddr_in clientAddr;
        int clientAddrSize = sizeof(clientAddr);
        SOCKET clientSocket = accept(serverSocket, reinterpret_cast<SOCKADDR*>(&clientAddr), &clientAddrSize);
        if (clientSocket == INVALID_SOCKET) {
            std::cerr << "Accept failed." << std::endl;
            closesocket(serverSocket);
            WSACleanup();
            return 1;
        }

        // Extract IP address bytes and print them
        unsigned char *ip = reinterpret_cast<unsigned char*>(&clientAddr.sin_addr.s_addr);
        std::cout << "Connected by ";
        for (int i = 0; i < 4; ++i) {
            std::cout << static_cast<int>(ip[i]);
            if (i < 3) std::cout << ".";
        }
        std::cout << std::endl;

        // Receive data from the client and save to file
        receiveDataAndSave(clientSocket);

        closesocket(clientSocket);
    }

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
