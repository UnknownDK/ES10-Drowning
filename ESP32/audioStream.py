import serial
import wave
import struct

# Serial port configuration
COM_PORT = 'COM4'  # Adjust this to your setup
BAUD_RATE = 3000000  # Adjust baud rate to match your serial configuration

# Audio configuration
CHANNELS = 1  # Stereo
SAMPLE_RATE = 40000
SAMPLE_BITS = 16  # Storing as 16-bit
DURATION_SECONDS = 5

data = []

# Output WAV file configuration
OUTPUT_WAV_FILE = "recorded_audio.wav"

def hex_to_int(hex_str):
    # Convert hex string to int
    value = int(hex_str, 16)
    return -(value & 0x8000) | (value & 0x7fff)

def capture_audio_to_wav(port, baud_rate, output_file, duration):
    # Open serial port
    with serial.Serial(port, baud_rate, timeout=1) as ser:


        max_samples = (SAMPLE_RATE * duration) / 256
        print(max_samples)
        sample_count = 0

        print("Capturing audio samples...")
        while sample_count < max_samples:
            line = ser.readline().decode('ascii').strip()
            if line:
                data.append(line)
                #if sample_count % 10000 == 0:
                #    print(f"Captured {sample_count} samples")


                sample_count += 1

    with wave.open(output_file, 'w') as wf:
        wf.setnchannels(CHANNELS)
        wf.setsampwidth(SAMPLE_BITS // 8)
        wf.setframerate(SAMPLE_RATE)
        print("Capture complete.")


        for line in data:

            # Extract left and right channel data
            #left_channel_data = [hex_to_int(hex_values[i]) for i in range(len(hex_values))]
            left_channel_data = [hex_to_int(line[i:i+4]) for i in range(0, len(line), 4)]
            
            #right_channel_data = [hex_to_int(hex_values[i]) for i in range(len(hex_values)) if i % 2 == 0]

            # Pack left and right samples into WAV file
            for left_sample in left_channel_data:
                wf.writeframes(struct.pack('<h', left_sample))


def main():
    capture_audio_to_wav(COM_PORT, BAUD_RATE, OUTPUT_WAV_FILE, DURATION_SECONDS)
    print(f"Saved audio to {OUTPUT_WAV_FILE}")

if __name__ == "__main__":
    main()



