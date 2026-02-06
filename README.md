# 🧹 Smart Floor Cleaning Robot

The **Smart Floor Cleaning Robot** is an automated embedded system designed to reduce human effort and improve cleaning efficiency in homes, hospitals, and offices. Built using an **ESP32 microcontroller**, the robot performs **wet floor cleaning** on flat surfaces using a predefined movement pattern. The project focuses on low cost, simplicity, and practical automation.

---

## 📌 Project Overview

Manual floor cleaning is time-consuming and often inconsistent due to human fatigue. This project addresses these challenges by offering an **automated, reliable, and efficient cleaning solution** with minimal human involvement.

The robot sprays water onto the floor and cleans it using a mop mechanism while moving forward in a controlled manner.

---

## 🏗️ System Architecture

The system integrates hardware and software components to ensure smooth operation.

### 🔧 Hardware Components

- **ESP32 Microcontroller**  
  Acts as the brain of the system, controlling motors and pump operations.

- **L298D Motor Driver**  
  Interfaces between the ESP32 and DC motors to control speed and direction.

- **DC Motors & Wheels**  
  Two DC motors drive the rear wheels, while a front castor wheel provides balance.

- **Water System**  
  - Water tank  
  - DC water pump  
  - Relay module for safe pump switching

- **Mop Mechanism**  
  A fixed mop beneath the chassis wipes the wet floor as the robot moves.

- **Power Supply**  
  - 12.8V rechargeable battery  
  - 7805 voltage regulator to provide stable 5V to electronics

---

### 💻 Software Design

- **Programming Environment:** Arduino IDE  
- **Language:** Embedded C/C++  
- **Control Logic:**  
  - ESP32 initializes GPIO pins  
  - Motors move forward  
  - Water pump activates simultaneously during cleaning cycle  

---

## ⚙️ Working Principle

1. On power-up, the ESP32 initializes all components.
2. Control signals are sent to the motor driver and relay module.
3. The robot moves forward while spraying water onto the floor.
4. The mop cleans the wet surface as the robot progresses.

Experimental results show **stable movement and effective cleaning** on tiled and cemented floors.

---

## 🏠 Applications

- **Residential:**  
  Daily floor cleaning for homes and apartments, especially useful for elderly or busy individuals.

- **Medical:**  
  Maintaining hygiene standards in hospitals and clinics.

- **Institutional:**  
  Efficient cleaning of large floor areas in schools, colleges, and offices.

---

## ✅ Advantages

- Reduces manual effort  
- Saves time  
- Low-cost design  
- Consistent cleaning performance  
- Simple and practical automation solution  

---

## ⚠️ Limitations

- No obstacle detection  
- No autonomous navigation  
- Limited cleaning coverage  
- Battery-dependent operation  

---

## 🚀 Future Enhancements

- **Obstacle Detection:** Ultrasonic or IR sensors  
- **Wireless Control:** Wi-Fi/Bluetooth control via mobile app or web interface  
- **Smart Features:** IoT and AI-based scheduling and path optimization  
- **Dry Cleaning Mode:** Vacuum or brush system for dual-mode cleaning  

---

## 👨‍💻 Project Credits

**Developers:**  
- Vedang Pathak  
- Sahil Parate  
