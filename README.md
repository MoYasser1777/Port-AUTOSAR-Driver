# AUTOSAR Port Driver

![AUTOSAR Logo](autosar_logo.png)

This repository contains an AUTOSAR-compliant Port Driver implementation for embedded systems, designed to work with the Tiva-C microcontroller family. The Port Driver provides an interface for configuring and controlling GPIO pins, including setting pin directions, modes, and internal resistors.

## Features

- Initialization of GPIO pins with configurable settings such as direction, mode, and internal resistor settings.
- APIs for setting pin direction, mode, and refreshing port direction.
- Error detection and reporting functionality using the Development Error Detection (DET) mechanism.
- Compatibility with AUTOSAR version 4.0.3.
- Version information retrieval capability.

## Usage

To use the Port Driver in your project:

1. Clone or download the repository.
2. Include the necessary header files (`Port.h`, `Port_Cfg.h`) in your project.
3. Configure the Port Driver settings in `Port_Cfg.h` according to your application requirements.
4. Initialize the Port Driver using the `Port_Init()` function with a pointer to the configuration set.
5. Use the provided APIs to interact with GPIO pins as needed in your application.

## Compatibility

The Port Driver is designed to work with the Tiva-C microcontroller family. However, it can be adapted to work with other microcontroller families with minimal modifications to the configuration settings.
