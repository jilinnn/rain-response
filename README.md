# Rain-Sensing System for Automobiles

A brief Arduino program that samples the voltage outputted by a photoelectric liquid-level sensor.

## Description

The program begins by setting predetermined Arduino pins to inputs and outputs needed in the device. Two helper functions are used throughout the program, namely `countDrops`and `motorControl`, with the former sampling the amount of 'rain' detected on the photoelectric liquid-level sensor and the latter setting the speed and direction of a DC motor (behaves as windshield wipers). The loop function in the program continuously checks the number of 'drops of rain' on the photoelectric liquid-level sensor by calling the countDrops helper function, and changes the brightness of the LEDs, as well as the motor configuration via the motorControl helper function, accordingly.

## Usage

This program was used for the microcontroller in a hands-on project, namely a "Rain-Sensing System for Automobiles." At the top of the program, multiple variables are mapped to various components of the device: 
-`rainSensor`      maps to the photoelectric liquid-level sensor;
-`ledMOSFET`       maps to a MOSFET that controls the brightness of two LEDS;
-`motorMOSFET`     maps to a MOSFET that controls the speed of a DC motor;
-`relayControl`    controls the direction of a DC motor (by flipping the voltage polarity across the motor).

[The device in action can be found in the YouTube video here.](https://youtu.be/iX7MvlwBTv4)

[A full report of the project can be found here.](https://drive.google.com/file/d/1Iep5V_OFfq52zuf6BuwZ7WUe4qnY6N2o/view?usp=sharing)

Project Contributors:
Jilin Zheng,
Renad Alanazi,
Tong Wu,
Maryam Aliyeva

Timeline: May-June 2023
