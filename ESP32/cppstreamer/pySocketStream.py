import socket
import time

def stream_audio(file_path, server_address):
    # Open the audio file
    with open(file_path, 'rb') as f:
        # Connect to the server
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.connect(server_address)

        # Stream the audio file
        data = f.read(1024)
        while data:
            client_socket.sendall(data)
            data = f.read(1024)

        # Close the connection
        client_socket.close()

if __name__ == "__main__":
    # Server address and port
    SERVER_ADDRESS = ('localhost', 8080)

    # Stream "woo.wav"
    print("Streaming wee.wav...")
    stream_audio("wee.wav", SERVER_ADDRESS)

    # Wait for 500 milliseconds
    time.sleep(1)

    # Stream "wee.wav"
    print("Streaming woo.wav...")
    stream_audio("woo.wav", SERVER_ADDRESS)
