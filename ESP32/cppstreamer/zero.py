import socket

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
    degree = degree - 90
    if (degree > 180):
        move_forward(360 - degree)
    else:
        move_backward(degree)

    return True

def move_to(wish):
    degree = read_angle()
    degree = degree + wish
    if (degree > 180):
        move_forward(360 - degree)
    else:
        move_backward(degree)

    return True

def stop():
    reply = send_command(COMMAND_STOP)
    return check_simple_command(reply)


if __name__ == "__main__":

    move_to(90)





