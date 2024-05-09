import socket
import os
from datetime import datetime

# Host and port to bind the server to
HOST = '0.0.0.0'
PORT = 33333
CHUNK_SIZE = 3584
MAX_FILE_SIZE = 7 * 1024 * 1024
name = str(datetime.now())

def receive_data_and_save(server_socket):
    total_data = b''
    bytes_received = 0

    while True:
        # Receive data in chunks
        data, addr = server_socket.recvfrom(CHUNK_SIZE)
        if not data:
            break

        total_data += data
        bytes_received += len(data)

        # Save to file if reached MAX_FILE_SIZE
        if bytes_received >= MAX_FILE_SIZE:
            save_to_file(total_data)
            total_data = b''
            bytes_received = 0

    # Save any remaining data to file
    if total_data:
        save_to_file(total_data)

def save_to_file(data):
    with open("data_{}".format(name), "ab") as file:
        file.write(data)
    print("Data saved to file")

def main():
    # Create a socket object
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as server_socket:
        # Bind the socket to the host and port
        server_socket.bind((HOST, PORT))

        print(f"Server listening on {HOST}:{PORT}")

        # Receive data from clients and save to file
        receive_data_and_save(server_socket)

if __name__ == "__main__":
    main()
