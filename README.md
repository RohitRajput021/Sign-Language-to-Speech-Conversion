# Sign Language to Speech Conversion

![Project Status](https://img.shields.io/badge/Status-Completed-brightgreen) ![License](https://img.shields.io/badge/License-MIT-blue)

This project converts sign language gestures into audible speech and visual text output, providing an accessible communication solution for speech-impaired individuals. Utilizing flex sensors, an Arduino Nano, and a DF Mini Player, this system interprets hand gestures, producing audio feedback and displaying messages on an LCD, enabling seamless interaction with those unfamiliar with sign language.

## Table of Contents
- [Introduction](#introduction)
- [Problem Statement](#problem-statement)
- [Features](#features)
- [Components](#components)
- [Circuit Diagram](#circuit-diagram)
- [Setup and Usage](#setup-and-usage)
- [Project Demo](#project-demo)
- [Conclusion](#conclusion)
- [Future Improvements](#future-improvements)

---

## Introduction
Sign language, while effective within certain communities, is not widely understood, posing a communication barrier for speech-impaired individuals. This project provides a solution by converting hand gestures into audible speech, helping speech-impaired users interact easily. The system also displays the translated message on an LCD, making it accessible to those who cannot hear the audio output.

## Problem Statement
In India, many individuals face communication challenges due to speech impairments. Although sign language aids communication within specific groups, it’s not universally understood. This project addresses this barrier by offering a real-time assistive communication tool that benefits speech-impaired individuals and those with limited mobility, such as people with paralysis or other disabilities.

## Features
- **Real-time Gesture Recognition**: Flex sensors detect finger bending angles, translating them into messages.
- **Audio Feedback**: DF Mini Player provides audible feedback for each recognized gesture.
- **Text Display**: A 16x2 LCD visually displays the interpreted message, enhancing accessibility.

## Components

1. **Arduino Nano**: Microcontroller for sensor data processing and module control.
   - Operating Voltage: 5V
   - Analog Pins: 8 (A0–A7) to read sensor values.

2. **Flex Sensors**: Detects bending angles of fingers and translates gestures into variable resistance.
   - Operating Voltage: 0–5V
   - Flat Resistance: ~25 kΩ

3. **DF Mini Player**: Compact audio module for playing pre-recorded audio files based on gestures.
   - **Key Features**: MP3 playback from microSD, volume control, built-in amplifier.
   - **Connections**: 
     - VCC: 5V
     - RX (D10) and TX (D9) on Arduino.

4. **16x2 LCD Display**: Provides visual output for accessibility.
   - Connection: Standard 4-bit or I2C interface.

5. **Speaker**: Outputs audio from the DF Mini Player.
   - Specifications: 8-ohm, 0.25-watt speaker.

6. **Zero PCB**: Serves as a stable platform for mounting components.

### Circuit Diagram
The following connections enable the project setup:

- **Flex Sensors**: Connected to Arduino analog pins (A0-A4).
- **DF Mini Player**: Connected via TX (D9) and RX (D10).
- **Speaker**: Connected to the DF Mini Player’s output.

[![Circuit Diagram](assets/Circuit%20Diagram.pdf)](assets/Circuit%20Diagram.pdf)


## Setup and Usage

1. **Prepare Audio Files**:
   - Store audio files in MP3 format on a microSD card with predefined file names.
   - Insert the microSD card into the DF Mini Player.

2. **Connect Components**:
   - Assemble components on the Zero PCB according to the circuit diagram.
   - Connect the flex sensors, DF Mini Player, LCD, and speaker as specified.

3. **Upload Code**:
   - Upload the Arduino code to process sensor data, control audio playback, and update the LCD display.

## Project Demo
- **Assembly**: Components are soldered onto the Zero PCB for stability.
- **Testing**: Each gesture triggers corresponding audio and text output, ensuring real-time communication.

## Conclusion
The Sign Language to Speech Conversion project empowers speech-impaired individuals by translating hand gestures into audio and text, bridging communication gaps. By integrating flex sensors, an Arduino Nano, a DF Mini Player, a speaker, and a 16x2 LCD, this project facilitates interactions with those unfamiliar with sign language, fostering inclusivity.

## Future Improvements
- **Expanded Gesture Recognition**: Incorporate additional gestures for a broader vocabulary.
- **Enhanced Audio Quality**: Improve clarity and volume control for various environments.
- **Portable Design**: Optimize power consumption for a portable, wearable solution.

---

For more details and code, visit the [repository](https://github.com/RohitRajput021/Sign-Language-to-Speech-Conversion.git).

