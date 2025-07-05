# Embedded Systems Diploma Projects

## Overview
These projects were developed under the supervision of Eng. Mohamed Tarek at Edges Academy. They demonstrate applied knowledge in C programming and embedded systems using the ATmega32 microcontroller. Each project integrates hardware and software design principles to solve real-world problems.

---

## Project 1: Student Management System

### Abstract
A console-based student management application developed in C, utilizing dynamic memory allocation and linked lists to manage student records efficiently.

### System Design and Architecture
- Dynamic data structure implementation using singly linked lists.
- Operations include adding, deleting, updating, and searching for records.

### Peripherals Used
- None (PC-based console program)

### Protocol Used
- Standard console I/O

### Conclusion
This project builds a strong foundation in structured programming and data structure management, which is essential for efficient resource handling in embedded systems.

---

## Project 2: Stopwatch (Mini Project 2)

### Abstract
A digital stopwatch system with two operational modes: increment (count-up) and countdown. The design includes user interaction through push buttons and visual feedback through multiplexed seven-segment displays and indicators.

### System Design and Architecture
- Six multiplexed seven-segment displays show time in HH:MM:SS format.
- Controlled via external interrupts for reset, pause, resume, and mode switching.
- Separate input buttons allow manual time adjustment for countdown mode.

### Peripherals Used
- ATmega32 microcontroller
- 6 seven-segment displays (common anode)
- 7447 BCD to seven-segment decoder
- 10 push buttons
- LEDs (mode indicators)
- Buzzer (countdown alert)

### Protocol Used
- External Interrupts: INT0 (Reset), INT1 (Pause), INT2 (Resume)

### Conclusion
This project demonstrates timer configuration, display multiplexing, and responsive user interaction through interrupts in embedded systems.

---

## Project 3: Smart Home Automation System (Mini Project 3)

### Abstract
A smart home automation system designed to control lighting and fan speed based on environmental conditions, with safety features for fire detection.

### System Design and Architecture
- LDR sensor controls three LEDs based on light intensity.
- LM35 temperature sensor regulates fan speed via PWM.
- Flame sensor triggers alerts and updates on LCD.
- Real-time system status displayed on a 16x2 LCD.

### Peripherals Used
- ATmega32 microcontroller
- LM35 temperature sensor
- LDR (light sensor)
- Flame sensor
- 16x2 character LCD
- 3 LEDs (red, green, blue)
- DC motor with H-bridge driver
- Buzzer

### Protocol Used
- ADC for sensor inputs
- PWM for fan control
- Polling for flame sensor

### Conclusion
This project showcases the integration of multiple environmental sensors and actuators for real-time control and monitoring, providing a practical foundation in home automation systems.

---

## Project 4: Car Parking System

### Abstract
A proximity alert system for car parking, using ultrasonic sensing to measure and display the distance from nearby obstacles, and provide visual and audible warnings.

### System Design and Architecture
- HC-SR04 ultrasonic sensor measures distance in centimeters.
- Output is shown on an LCD and alerts are generated via LED and buzzer when proximity is too close.

### Peripherals Used
- ATmega32 microcontroller
- HC-SR04 ultrasonic sensor
- 16x2 LCD
- LED and buzzer

### Protocol Used
- Timing via Input Capture Unit (ICU) for echo pulse width

### Conclusion
A practical system for vehicle safety, demonstrating distance measurement using ultrasonic sensors and alert systems in embedded designs.

---

## Final Project: Dual Microcontroller Door Locker Security System

### Abstract
A secure, password-protected door access system implemented using two ATmega32 microcontrollers. One microcontroller (HMI_ECU) handles user interaction, while the other (Control_ECU) processes authentication, controls door mechanisms, and handles alarms.

### System Design and Architecture
- HMI_ECU interfaces with LCD and keypad for password entry.
- Control_ECU validates the password, manages EEPROM, controls the DC motor and buzzer, and monitors PIR motion sensor.
- A three-attempt lockout system is implemented for added security.

### Peripherals Used
- 2 ATmega32 microcontrollers
- 16x2 LCD (HMI side)
- 4x4 Keypad (HMI side)
- External EEPROM (I2C)
- H-bridge motor driver and DC motor
- PIR motion sensor
- Buzzer

### Protocol Used
- UART for communication between HMI_ECU and Control_ECU
- I2C for EEPROM interface

### Conclusion
A complete access control system demonstrating secure communication between multiple microcontrollers, real-time user interaction, and embedded security protocols. Suitable for smart home and industrial access control applications.

---
