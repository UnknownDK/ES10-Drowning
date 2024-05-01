// Compile using g++ socketStream.cpp -o socketStream -lstdc++

#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <ctime>
#include <cstdint>

// Define the port number to listen on
#define PORT 8080
// Define the size of the buffer for receiving data
#define BUFFER_SIZE 1024
// Define the sample rate
#define SAMPLE_RATE 44100

std::string get_current_time_as_string() {
    std::time_t now = std::time(nullptr);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d%H%M%S", std::localtime(&now));
    return std::string(buffer);
}

void write_wav_header(std::ofstream& wav_file, int sample_rate) {
    // Write WAV header
    wav_file << "RIFF----WAVEfmt "; // ChunkID and subchunk1ID
    std::uint32_t subchunk1Size = 16;
    wav_file.write(reinterpret_cast<const char*>(&subchunk1Size), 4); // Subchunk1Size
    std::uint16_t audioFormat = 1; // PCM format
    wav_file.write(reinterpret_cast<const char*>(&audioFormat), 2); // AudioFormat
    std::uint16_t numChannels = 1; // Mono
    wav_file.write(reinterpret_cast<const char*>(&numChannels), 2); // NumChannels
    std::uint32_t byteRate = sample_rate * numChannels * 2; // SampleRate * NumChannels * BitsPerSample/8
    wav_file.write(reinterpret_cast<const char*>(&byteRate), 4); // ByteRate
    std::uint16_t blockAlign = numChannels * 2; // NumChannels * BitsPerSample/8
    wav_file.write(reinterpret_cast<const char*>(&blockAlign), 2); // BlockAlign
    std::uint16_t bitsPerSample = 16; // 16-bit PCM
    wav_file.write(reinterpret_cast<const char*>(&bitsPerSample), 2); // BitsPerSample
    wav_file << "data----"; // Subchunk2ID
}

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create a socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (true) {
        // Accept a connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Generate file name with timestamp
        std::string filename = "received_audio_" + get_current_time_as_string() + ".wav";

        // Open a file for writing the received data as a WAV file
        std::ofstream wav_file(filename, std::ios::binary);
        if (!wav_file.is_open()) {
            std::cerr << "Failed to open file for writing" << std::endl;
            exit(EXIT_FAILURE);
        }

        // Write WAV header with specified sample rate
        write_wav_header(wav_file, SAMPLE_RATE);

        // Receive data from the client and write it to the file
        while ((valread = read(new_socket, buffer, BUFFER_SIZE)) > 0) {
            wav_file.write(buffer, valread);
        }

        if (valread < 0) {
            perror("read");
        }

        // Close the socket and file
        close(new_socket);
        wav_file.close();
    }

    close(server_fd);

    return 0;
}
