import os
import glob
import matplotlib.pyplot as plt
import soundfile as sf

# Function to find the latest folder
def find_latest_folder(root_dir):
    folders = [folder for folder in os.listdir(root_dir) if os.path.isdir(os.path.join(root_dir, folder)) and folder.startswith('2024-')]
    if not folders:
        return None
    return max(folders)

# Function to plot WAV files in the specified format
def plot_wav_files(folder_path):
    wav_files = glob.glob(os.path.join(folder_path, '*.wav'))
    if not wav_files:
        print("No WAV files found in the folder.")
        return

    # Create a single figure with subplots for all spectra
    num_plots = len(wav_files)
    fig, axs = plt.subplots(num_plots, 1, figsize=(20, 5*num_plots), sharey=True)

    # Plot signals in the time domain
    for i, wav_file in enumerate(wav_files):
        data, samplerate = sf.read(wav_file)
        ax = axs[i] if num_plots > 1 else axs
        ax.plot(data[10000:13000])
        ax.set_xlabel('Sample')
        ax.set_ylabel('Amplitude')
        ax.set_title('Signal {}'.format(i))

    plt.tight_layout()
    plt.suptitle('Signals in Time Domain')
    plt.show()

# Main function
def main():
    root_dir = '.'  # Change this to your root directory
    latest_folder = find_latest_folder(root_dir)
    if latest_folder:
        latest_folder_path = os.path.join(root_dir, latest_folder)
        print("Latest folder found:", latest_folder_path)
        plot_wav_files(latest_folder_path)
    else:
        print("No folder found in the specified format.")

if __name__ == "__main__":
    main()
