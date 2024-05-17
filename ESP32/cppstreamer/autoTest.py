import socket
import os
from datetime import datetime
import pygame
import time

# Host and port to bind the server to
HOST = '0.0.0.0'
PORT = 33333
CHUNK_SIZE = 8*190*4
#MAX_FILE_SIZE = 1 * 1024 * 1024
SAMPLE_RATE = 41667
SECONDS = 8
MAX_FILE_SIZE =  SAMPLE_RATE*8*4*SECONDS   #CHUNK_SIZE * 256
name = str(datetime.now()).replace(" ", "").replace(":", "")
current_degree = 0

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
            return True

    # Save any remaining data to file
    if total_data:
        save_to_file(total_data)



def save_to_file(data):
    folder_name = str(name)
    if not os.path.exists(folder_name):
        os.makedirs(folder_name)
    with open(os.path.join(folder_name, "degree_{}".format(current_degree)), "ab") as file:
        file.write(data)
    print("Data saved to file")


def do_measurement():
    # Create a socket object
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as server_socket:
        # Bind the socket to the host and port
        server_socket.bind((HOST, PORT))

        print(f"Server listening on {HOST}:{PORT}")

        # Receive data from clients and save to file
        receive_data_and_save(server_socket)


UDP_PORT = 6668
COMMAND_MOVE_FORWARD = 1
COMMAND_MOVE_BACKWARD = 2
COMMAND_STOP = 3
COMMAND_READ_ANGLE = 4
COMMAND_SET_ZERO = 5

REPLY_OK = 0x33
REPLY_ERR = 0x66

STATUS_MOVING = 4
STATUS_STOPPED = 5
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
import struct

def send_command(command, arg = 0):
    checksum = ((command & 0xff) ^ ((arg >> 8) & 0xff)) ^ (arg & 0xff)
    message = struct.pack(">BhB", command, arg, checksum)
    sock.sendto(message, ("192.168.1.34", UDP_PORT))

    reply = sock.recvfrom(7)
    return reply[0]

def check_simple_command(reply):
    return reply[0] == REPLY_OK

def move_forward(degree):
    if degree == 0.0:
        return True

    reply = send_command(COMMAND_MOVE_FORWARD, int(degree * 10))
    return check_simple_command(reply)

def move_backward(degree):
    if degree == 0.0:
        return True

    reply = send_command(COMMAND_MOVE_BACKWARD, int(degree * 10))
    return check_simple_command(reply)

def set_zero():
    reply = send_command(COMMAND_SET_ZERO)
    return check_simple_command(reply)

def read_angle():
    reply = send_command(COMMAND_READ_ANGLE)
    (status, degree, direction, checksum) = struct.unpack(">BIBB", reply)

    if status == 4:
        status = "moving"
    elif status == 5:
        status = "stopped"

    if direction == 1:
        direction = "counterclockwise"
    elif direction == 2:
        direction = "clockwise"

    print("status= %s dir= %s degree= %.2f" % (status, direction, float(degree / 10)))
    return float(degree / 10)

def move_zero():
    degree = read_angle()
    if (degree > 180):
        move_forward(360 - degree)
    else:
        move_backward(degree)

    return True

def stop():
    reply = send_command(COMMAND_STOP)
    return check_simple_command(reply)


    
def play_wav():
    # Initialize Pygame mixer
    pygame.mixer.init()

    # Load the WAV file
    #sound = pygame.mixer.Sound("expSweptSine2s10s2s.wav")
    sound = pygame.mixer.Sound("sine1000Hz10s2s.wav")

    # Play the WAV file blocking until it finishes
    sound.play()
    



if __name__ == "__main__":

    play_wav()
    do_measurement()
    """
    while current_degree < 180:
        #move_zero()

        play_wav()
        do_measurement()
        current_degree = current_degree + 1
        oldAngle = read_angle()
        print(current_degree)
        print(oldAngle)
        move_backward(1)
        time.sleep(3)
    """





