# Welcome Robot 🤖

A simple Arduino-based Welcome Robot that detects a person using an HC-SR04 Ultrasonic Sensor, moves a Servo Motor, and plays a welcome message through a DFPlayer Mini and Speaker.

## 🔧 Components Used

- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- Servo Motor
- DFPlayer Mini MP3 Module
- Speaker
- MicroSD Card

## ⚙️ Working

1. The HC-SR04 Ultrasonic Sensor continuously measures the distance.
2. When a person comes within 20 cm, the robot detects the person.
3. The Servo Motor moves to the open position.
4. The DFPlayer Mini plays the welcome audio through the speaker.
5. While the person remains within 20 cm, the welcome audio continues playing.
6. When the person moves away, the audio stops.
7. The Servo Motor returns to its normal position.

## 📌 Pin Configuration

| Component | Arduino UNO |
|---|---|
| HC-SR04 TRIG | D7 |
| HC-SR04 ECHO | D6 |
| Servo Signal | D9 |
| DFPlayer TX | D10 |
| DFPlayer RX | D11 |

## 💻 Technologies Used

- Arduino UNO
- Embedded C/C++
- HC-SR04 Ultrasonic Sensor
- Servo Motor
- DFPlayer Mini
- Serial Communication

## 🎯 Project Objective

To demonstrate how sensors, actuators, and audio modules can be integrated with a microcontroller to create a simple interactive Welcome Robot.


## 🎥 Project Demo

[Click here to watch the Project Demo]

( https://drive.google.com/file/d/1WpMvU7dqkQfgI64vJcE6LyMCWJaG2aCu/view?usp=drivesdk )
