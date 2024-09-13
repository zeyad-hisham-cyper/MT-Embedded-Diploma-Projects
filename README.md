# Embedded Systems Diploma Projects 🎓

## Overview 🌟

These projects were completed under the supervision of Eng. Mohamed Tarek at Edges Academy. They showcase proficiency in C programming and embedded systems using ATmega32 microcontrollers.

---

## Project 1: Student Management System 📚

### Description
A C language project designed to manage student data using a linked list data structure. This system demonstrates the ability to perform various operations on a dynamic list of students.

### Key Functions
- **Add Student** ➕: Add a new student to the linked list.
- **Display All Students** 🖥️: Show details of all students in the list.
- **Search Student by ID** 🔍: Find a student by their unique ID.
- **Update Student Data by ID** ✏️: Modify information for a specific student.
- **Calculate Average GPA** 📊: Compute the average GPA of all students.
- **Search for Highest GPA** 🏆: Identify the student with the highest GPA.
- **Delete Student** ❌: Remove a student from the list.

### Implementation
- Utilizes a linked list data structure to manage student records efficiently.
- Functions are implemented to handle typical student management operations.

---

## Project 2: Stopwatch Using ATmega32 Microcontroller ⏱️

### Description
A dual-mode stopwatch built with the ATmega32 microcontroller, featuring six multiplexed seven-segment displays. The stopwatch supports both increment and countdown modes.

### Key Features
- **Increment Mode** ⏫: Counts upwards, displaying hours, minutes, and seconds.
- **Countdown Mode** ⏳: Allows users to set a countdown timer with an alarm buzzer that sounds when the timer reaches zero.

### Control Functions
- **Reset Button (INT0)** 🔄: Resets the time in both modes.
- **Pause Button (INT1)** ⏸️: Pauses the stopwatch.
- **Resume Button (INT2)** ▶️: Resumes from the paused state.
- **Mode Toggle** 🔁: Switches between increment and countdown modes, with LED indicators (Red for Increment, Yellow for Countdown).

### Time Adjustment
- **Hours**:
  - Increase (PB1) ⏫: Increments hours, resetting to 0 after 99.
  - Decrease (PB0) ⏬: Decrements hours, wrapping back to 99 after 0.
- **Minutes**:
  - Increase (PB4) ⏫: Increments minutes, resetting after 59.
  - Decrease (PB3) ⏬: Decrements minutes, wrapping around to 59 after 0.
- **Seconds**:
  - Increase (PB6) ⏫: Increments seconds, resetting after 59.
  - Decrease (PB5) ⏬: Decrements seconds, wrapping around to 59 after 0.

### Hardware
- **Microcontroller**: ATmega32 running at 16MHz.
- **Display**: Six multiplexed seven-segment displays controlled by a 7447 BCD decoder and NPN transistors.
- **Input**: 10 push buttons for various functions including reset, pause, resume, and time adjustments.
- **Alarm/Buzzer** 🔔: Sounds when the countdown timer reaches zero.
- **LED Indicators**: Red LED (PD4) for Increment Mode, Yellow LED (PD5) for Countdown Mode.

### Technical Highlights
- **Multiplexing**: Efficiently controls six seven-segment displays using PORTA pins and a 7447 decoder.
- **External Interrupts**: Configured on INT0, INT1, and INT2 for accurate handling of reset, pause, and resume actions.
- **Timer1 in CTC Mode**: Ensures precise timing functionality for the stopwatch.

---
