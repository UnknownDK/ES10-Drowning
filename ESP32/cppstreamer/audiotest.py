import wave
import array
import os
from datetime import datetime

yee = [
    [],
    [],
    [],
    [],
    [],
    [],
    []
]
q = 0
# 2998272

numMic = 7

with open("received_data.txt", "rb") as file:
    q = 0
    while True:  # Iterate until the end of the file
        for i in range(numMic):
            for y in range(256):
                chunk = file.read(2)
                q += 1
                # If no more bytes are read, break out of the loop
                if not chunk:
                    break

                # Process the chunk of bytes
                # For example, you can print the chunk in hexadecimal format
                yee[i].append(chunk.hex())
                q += 1
        
        # If no more bytes are read, break out of the outer loop
        if not chunk:
            break

converted = [
    [],
    [],
    [],
    [],
    [],
    [],
    []
]
for z in range(numMic):

    converted[z] = [int(value, 16) - (1 << 16) if int(value, 16) > 32767 else int(value, 16) for value in yee[z]]



# Path to the directory where you want to create the new directory
curr_dir = os.getcwd()
new_dir = os.path.join(curr_dir, "{}".format(datetime.now().strftime("%Y-%m-%d_%H-%M-%S")))
os.makedirs(new_dir)
print(new_dir)

for z in range(numMic):
    # Open a mono WAV file for writing
    output_file = wave.open(new_dir + "\mic_{}.wav".format(z), "w")

    # Set the parameters for the WAV file
    output_file.setnchannels(1)  # Mono
    output_file.setsampwidth(2)  # 16-bit
    output_file.setframerate(48000)  # 48 kHz

    # Convert the array to bytes
    byte_array = array.array('h', converted[z]).tobytes()

    # Write the bytes to the WAV file
    output_file.writeframes(byte_array)

    # Close the WAV file
    output_file.close()

    """

import numpy as np
import matplotlib.pyplot as plt


# Create a single figure with subplots for all spectra
fig, axs = plt.subplots(2, 1, figsize=(20, 5), sharey=True)


# Plot signals in the time domain
for z in range(2):
    plt.subplot(2, 1, z+1)
    plt.plot(converted[z][10000:11000])
    plt.xlabel('Sample')
    plt.ylabel('Amplitude')
    plt.title('Signal {}'.format(z))

plt.tight_layout()
plt.suptitle('Signals in Time Domain')
plt.show()

"""