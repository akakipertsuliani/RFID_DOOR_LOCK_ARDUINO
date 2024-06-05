# RFID Door Lock System using MFRC522

This Arduino code allows you to use an RFID module (model MFRC522) to create a door lock system. The code includes functionalities to write a code to a specific block on an RFID card and to read the code for controlling a door lock mechanism using a servo motor. Additionally, it includes options to use a buzzer and LEDs to indicate the status of the card read operation.

## Description

This code helps you:
- Write a specific code to block 5 on the RFID card.
- Read the code from block 5 on the RFID card.
- Control a servo motor to unlock/lock the door based on the card read.
- Optionally use a buzzer and LEDs to indicate different statuses.

## Hardware Requirements

- Arduino Uno, Mega, Nano, Leonardo/Micro, or Pro Micro
- MFRC522 RFID reader module
- Servo motor (connected to pin D5)
- Buzzer (optional, connected to pin D6)
- Three LEDs (optional)
  - Neutral light: connected to pin D4 (indicates no activity)
  - Success light: connected to pin D3 (indicates correct card)
  - Error light: connected to pin D2 (indicates incorrect card)

## Connections

Make the following connections between the MFRC522 reader/PCD and your Arduino board:

| Signal      | MFRC522 Pin | Arduino Uno/101 Pin | Arduino Mega Pin | Arduino Nano v3 Pin | Arduino Leonardo/Micro Pin | Arduino Pro Micro Pin |
|-------------|--------------|---------------------|------------------|---------------------|---------------------------|-----------------------|
| RST/Reset   | RST          | 9                   | 5                | D9                  | RESET/ICSP-5               | RST                   |
| SPI SS      | SDA(SS)      | 10                  | 53               | D10                 | 10                        | 10                    |
| SPI MOSI    | MOSI         | 11 / ICSP-4         | 51               | D11                 | ICSP-4                    | 16                    |
| SPI MISO    | MISO         | 12 / ICSP-1         | 50               | D12                 | ICSP-1                    | 14                    |
| SPI SCK     | SCK          | 13 / ICSP-3         | 52               | D13                 | ICSP-3                    | 15                    |

## Setup

1. Connect your RFID reader and other components as described in the connections table above.
2. Upload the provided Arduino code to your board.
3. Initially, call the `writeBlockData()` function to write the code `k9T2dQ5X1mB6rF7H` to block 5 of the RFID card.
4. After writing the code to the card, comment out or remove the `writeBlockData()` function call to prevent any issues during normal operation.****

## Notes

- The servo motor is connected to pin D5.
- The buzzer is connected to pin D6.
- The LEDs are connected as follows:
  - Neutral light: pin D4
  - Success light: pin D3
  - Error light: pin D2

## How to Use

1. Ensure your RFID reader and other components are connected correctly.
2. Upload the code to your Arduino.
3. Initially, call `writeBlockData()` function to write the code `k9T2dQ5X1mB6rF7H` to block 5 of the RFID card.
4. Comment out or remove the `writeBlockData()` function call after writing the code to avoid any issues.
5. The system will read the RFID card and control the servo motor based on the read data. It will also use the buzzer and LEDs to indicate the status of the card read operation.
