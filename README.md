# FreeRTOS Real-Time Systems on ESP32

A multi-part embedded systems project implementing real-time scheduling concepts using FreeRTOS on an ESP32 microcontroller. Each phase aligns with foundational theories in real-time systems and is tested on physical hardware with GPIO LEDs, an SSD1306 display, and button inputs.

## Project Modules

1. **Chatterbox App**
   - Periodic task scheduling with visual LED feedback
   - Task control using FreeRTOS delay functions

2. **Time-Demand Analysis App**
   - Implements:
     - Utilization Bound Test
     - Worst Case Response Time Analysis
     - Time-Demand Analysis
   - Output visualized on SSD1306 OLED display

3. **EDF + Deferrable Server**
   - Earliest Deadline First scheduler
   - Supports aperiodic tasks via Deferrable Server
   - Implements system density test
   - Button-press triggered task animations on display

4. **Immediate Ceiling Priority Protocol (ICPP)**
   - Prevents priority inversion
   - Transparent priority elevation using FreeRTOS Task API
   - Shared resource access control across tasks

## Technologies
- C / Embedded C
- FreeRTOS + ESP-IDF
- I2C (SSD1306 OLED)
- GPIO, Interrupts
- Task Scheduling Theory (UBT, EDF, TDA, ICPP)

> Developed as part of real-time concepts for embedded system coursework in 2025.
