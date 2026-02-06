# smart_floor_cleaning_robot
The Floor Cleaning Robot System is an automated solution designed to reduce human effort and improve cleaning efficiency in environments such as homes, hospitals, and offices. This project utilizes an ESP32 microcontroller to manage a wet cleaning process, offering a low-cost and practical application of embedded systems and automation.
Project Overview
Manual floor cleaning is labor-intensive and often inconsistent due to human fatigue. This system addresses these issues by providing an automated, reliable cleaning performance with minimal human involvement. The robot is specifically designed for wet cleaning on flat surfaces following a predefined movement pattern.
System Architecture
The hardware and software integration ensures the robot functions seamlessly:
• Hardware Components:
    ◦ ESP32 Microcontroller: Serves as the brain of the system, controlling motor movements and pump operations.
    ◦ L298D Motor Driver: Acts as the interface between the ESP32 and the motors to control speed and direction.
    ◦ DC Motors & Wheels: Two DC motors drive the rear wheels for movement, while a front castor wheel provides balance.
    ◦ Water System: Includes a water tank, a DC water pump for spraying, and a relay module that allows the ESP32 to safely switch the pump on and off.
    ◦ Mop Mechanism: A mop fixed beneath the chassis wipes the wet surface as the robot moves.
    ◦ Power Supply: The system is powered by 12.8V rechargeable batteries, with a 7805 voltage regulator providing a stable 5V to the electronic components.
• Software Design:
    ◦ Programming Environment: Developed using the Arduino Integrated Development Environment (IDE) using Embedded C/C++.
    ◦ Control Logic: The ESP32 initializes GPIO pins to drive motors forward and activate the water pump simultaneously during the cleaning cycle.
Working Principle
When the system is powered on, the ESP32 initializes all components and sends signals to the motor driver and relay module. The robot moves forward while the pump sprays water onto the floor; the attached mop then cleans the surface as the robot progresses. Experimental results confirm that the robot demonstrates stable movement and effective cleaning on tiled and cemented floors.
Applications
The robot is suitable for various settings, including:
• Residential: Daily cleaning for homes and apartments to assist the elderly or busy individuals.
• Medical: Maintaining hygiene standards in hospitals and clinics.
• Institutional: Efficiently cleaning large floor areas in schools, colleges, and offices.
Advantages and Limitations
• Advantages: Significant reduction in manual effort, time efficiency, low-cost design, and consistent cleaning performance.
• Limitations: The current prototype lacks obstacle detection and autonomous navigation, has a limited coverage area, and is dependent on battery capacity.
Future Enhancements
Future iterations of the project may include:
• Obstacle Detection: Adding ultrasonic or infrared sensors to prevent collisions.
• Wireless Control: Utilizing the ESP32’s built-in Wi-Fi and Bluetooth for mobile app or web monitoring.
• Smart Features: Implementing IoT and AI for scheduling and optimized path planning.
• Dry Cleaning: Integrating a vacuum or brush system to support both dry and wet cleaning modes.
Project Credits
• Developers: Vedang Pathak, Sahil Parate