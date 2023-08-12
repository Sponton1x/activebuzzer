<h1>Arduino Ultrasonic Distance Sensor with Buzzer and LED Control</h1>

![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)

<p>This project involves using an Arduino to measure distances using an ultrasonic sensor and controlling a buzzer and LED based on the measured distance.</p>

<h2>Components Used</h2>

- Arduino board
- Ultrasonic Distance Sensor (HC-SR04)
- Buzzer
- LED

<h2>Wiring Instructions</h2>

1. Connect the Trigger (Trig) pin of the ultrasonic sensor to digital pin 2 on the Arduino.
2. Connect the Echo pin of the ultrasonic sensor to digital pin 3 on the Arduino.
3. Connect the positive (anode) leg of the buzzer to digital pin 8 on the Arduino.
4. Connect the positive (anode) leg of the LED to digital pin 13 on the Arduino.
5. Connect the ground (GND) of the ultrasonic sensor, buzzer, and LED to the ground (GND) of the Arduino.
6. Connect the VCC of the ultrasonic sensor to the 5V pin on the Arduino.

<h2>Code Explanation</h2>

The provided Arduino code performs the following actions:

- Initializes pins and serial communication.
- Measures the distance using the ultrasonic sensor and calculates the distance in centimeters.
- Controls the buzzer and LED based on the measured distance:
  - If distance <= 30 cm, the buzzer beeps rapidly and the LED remains on for 3 seconds.
  - If 30 cm < distance < 50 cm, the buzzer beeps slowly and the LED remains on for 2 seconds.
  - If 50 cm < distance < 70 cm, the buzzer beeps briefly and the LED remains on for 1 second.
  - If none of the above conditions are met, the buzzer and LED are turned off.
  
<h2>Usage</h2>

1. Upload the provided code to your Arduino board using the Arduino IDE.
2. Make sure your components are correctly wired as per the wiring instructions.
3. Open the serial monitor in the Arduino IDE to view the measured distances.

Remember to adjust the threshold distances and timing as needed for your project's requirements.

<h2>License</h2>
This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.

<h2>Support</h2>
If you are have problem with this repository, you can contact me od Discord: Sponton#4170
