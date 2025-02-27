# Smart Farming with Weather Prediction Using ESP32

This repository contains the Arduino code, configuration, and assembly instructions for building a smart farming system using the ESP32 microcontroller. The system automates irrigation by monitoring soil moisture and integrating weather data to predict water requirements <button class="citation-flag" data-index="1">. This project is ideal for optimizing water usage, improving crop yield, and reducing manual labor in agriculture.

---

## Table of Contents
1. [Overview](#overview)
2. [Components Used](#components-used)
3. [System Dimensions](#system-dimensions)
4. [Assembly Instructions](#assembly-instructions)
5. [Arduino Code Explanation](#arduino-code-explanation)
6. [Contributing](#contributing)
7. [License](#license)

---

## Overview
The smart farming system uses the ESP32 to collect soil moisture data and integrate weather predictions from an API like OpenWeatherMap <button class="citation-flag" data-index="5">. Based on this data, the system determines whether irrigation is needed and activates a water pump accordingly <button class="citation-flag" data-index="4">. This ensures efficient water usage and optimal plant growth.

---

## Components Used
To build this smart farming system, you will need the following components:
- **ESP32 Development Board**
- **Capacitive Soil Moisture Sensor**
- **DC Water Pump**
- **5V Relay Module**
- **Red LED**
- **Green LED**
- **Jumper Wires**
- **Breadboard (Optional)**

---

## System Dimensions
For an ideal smart farming system:
- **Height**: 20–25 cm
- **Width**: 15–20 cm
- **Length**: 15–20 cm

These dimensions ensure that the system is compact yet spacious enough to house all components.

---

## Assembly Instructions
Follow these detailed steps to assemble your smart farming system:
1. Connect the soil moisture sensor to monitor soil moisture levels.
2. Connect the water pump and relay module to automate irrigation.
3. Connect the LEDs to provide visual feedback on system status.
4. Power the system using a USB cable.
5. Secure all components inside a protective enclosure.

---

## Arduino Code Explanation
The provided Arduino code reads soil moisture data and fetches weather predictions from the OpenWeatherMap API <button class="citation-flag" data-index="5">. If the soil is dry and no significant rainfall is predicted, the system activates the water pump to irrigate the plants <button class="citation-flag" data-index="4">. The LEDs indicate whether irrigation is in progress or not.

---

## Contributing
Feel free to fork this repository and contribute improvements or new features. If you have suggestions or find bugs, please open an issue.

---

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

By following this guide, you should be able to build and test your own smart farming system using the ESP32. Happy tinkering! 🚀
