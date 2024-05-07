import socket

print("Creating server...")
s = socket.socket()
s.bind(('0.0.0.0', 33333))
s.listen(0)

while True:
        client, addr = s.accept()
        while True:
                content = client.recv(2048)
                if len(content) == 0:
                        break
                else:
                        print(len(content))
        print("Closing connection")
        client.close()