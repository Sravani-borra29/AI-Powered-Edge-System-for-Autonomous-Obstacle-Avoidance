# AI-Powered Edge System for Autonomous Obstacle Avoidance and Real-Time Object Recognition

## Overview

This project presents an AI-powered autonomous robotic system capable of real-time obstacle avoidance and object recognition using edge computing technologies.

The system combines embedded hardware, computer vision, and machine learning to create an intelligent mobile robot that can sense its environment, detect obstacles, recognize objects, and make autonomous decisions.

The main processing unit of the system is a Raspberry Pi, which performs AI-based object detection using YOLOv8 and OpenCV, while an Arduino Uno handles sensor-based obstacle detection and motor control.

---

## Features

- Real-time obstacle detection and avoidance
- AI-based object recognition using YOLOv8
- Computer vision processing using OpenCV
- Edge AI implementation using Raspberry Pi
- Ultrasonic sensor-based distance measurement
- Autonomous navigation capability
- Flask-based monitoring dashboard
- Real-time camera feed processing
- Hardware and software integration

---

## System Architecture

The system is divided into three major modules:

### 1. Sensor and Control Unit (Arduino Uno)

The Arduino Uno acts as the low-level controller responsible for:

- Reading ultrasonic sensor data
- Measuring distance from obstacles
- Controlling motor driver signals
- Performing basic movement decisions

### 2. AI Processing Unit (Raspberry Pi)

The Raspberry Pi works as the main intelligence module.

Responsibilities:

- Capturing images using a camera module
- Processing images using OpenCV
- Detecting objects using YOLOv8 deep learning model
- Sending control commands based on environmental conditions
- Running Python-based AI applications

### 3. Monitoring Interface (Flask Dashboard)

A Flask web dashboard is developed for monitoring and visualization.

It provides:

- Live system information
- Camera feed display
- Object detection results
- Robot status monitoring

---

# Hardware Components

| Component | Purpose |
|----------|---------|
| Raspberry Pi 3B+ | Main AI processing unit |
| Arduino Uno | Sensor and motor control |
| HC-SR04 Ultrasonic Sensor | Obstacle distance measurement |
| Camera Module | Image acquisition |
| TB6612FNG Motor Driver | Motor control |
| BO Motors | Robot movement |
| Li-ion Battery Pack | Power supply |
| 4-Wheel Robot Chassis | Mechanical platform |

---

# Software Technologies

## Programming Languages

- Python 3.11
- Embedded C++

## AI and Computer Vision

- YOLOv8
- OpenCV
- Ultralytics

## Web Framework

- Flask

## Embedded Platforms

- Raspberry Pi OS
- Arduino IDE

---

# AI and Machine Learning Implementation

The project uses YOLOv8 deep learning model for real-time object detection.

The camera captures environmental images, which are processed by the YOLO model running on Raspberry Pi.

The model identifies objects and provides:

- Object classification
- Detection confidence
- Object location information

OpenCV is used for image processing operations and integration with the camera system.

This approach enables the robot to perform intelligent decision-making directly on the edge device without depending completely on cloud processing.

---

# Project Workflow
Camera Input
|
↓
OpenCV Image Processing
|
↓
YOLOv8 Object Detection
|
↓
Decision Making
|
↓
Arduino Motor Control
|
↓
Autonomous Robot Movement

---

# Project Directory Structure
│
├── Arduino_Code
│ └── Obstacle_detection.ino
│
├── RaspberryPi_Code
│ └── main.py
│
├── Flask_Dashboard
│
├── Images
│
├── Videos
│

---

# Results

The developed prototype successfully demonstrates:

- Real-time obstacle detection
- Autonomous movement
- Object recognition using AI
- Communication between embedded systems
- Edge-based machine learning execution

The system achieved reliable obstacle sensing and AI-based recognition performance suitable for autonomous robotic applications.

---

# Future Improvements

Future enhancements planned for this system include:

- GPS-based autonomous navigation
- Improved path planning algorithms
- SLAM-based mapping
- Voice interaction capability
- More optimized AI models for faster inference
- Cloud-based remote monitoring

---

# Applications

This project can be extended for:

- Autonomous delivery robots
- Smart surveillance systems
- Industrial automation
- Assistive robots
- Smart mobility solutions

---

# Author

**Borra Sravani**

B.Tech Electronics and Communication Engineering

Interested in:
- Artificial Intelligence
- Machine Learning
- Python Development
- Embedded Systems
- Robotics

 ## 🎥 Demo Video

Watch the project demonstration here:

https://youtu.be/https://youtube.com/shorts/JBxZgq9sEeM?feature=share

