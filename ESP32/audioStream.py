import serial
import wave
import struct

# Serial port configuration
COM_PORT = '/dev/ttyUSB0'  # Adjust this to your setup
BAUD_RATE = 2000000        # Adjust baud rate to match your serial configuration

# Audio configuration
CHANNELS = 1
SAMPLE_RATE = 12000
SAMPLE_BITS = 32  # Storing as 32-bit for this example, could be converted to 16-bit
DURATION_SECONDS = 10

# Output WAV file configuration
OUTPUT_WAV_FILE = "recorded_audio.wav"

def capture_audio_to_wav(port, baud_rate, output_file, duration):
    # Open serial port
    with serial.Serial(port, baud_rate, timeout=1) as ser, \
            wave.open(output_file, 'w') as wf:
        wf.setnchannels(CHANNELS)
        wf.setsampwidth(SAMPLE_BITS // 8)
        wf.setframerate(SAMPLE_RATE)

        max_samples = SAMPLE_RATE * duration
        sample_count = 0

        print("Capturing audio samples...")
        while sample_count < max_samples:
            line = ser.readline().decode('ascii').strip()
            if line:
                try:
                    # Parse the integer value from the line
                    sample = int(line)
                    # Pack the sample into bytes and write to the WAV file
                    wf.writeframes(struct.pack('<i', sample))
                    sample_count += 1
                except ValueError:
                    print(f"Invalid data: {line}")

        print("Capture complete.")

def main():
    capture_audio_to_wav(COM_PORT, BAUD_RATE, OUTPUT_WAV_FILE, DURATION_SECONDS)
    print(f"Saved audio to {OUTPUT_WAV_FILE}")

if __name__ == "__main__":
    main()
