# 🎬 Projector Screen Control using ESP32, Arduino & Blynk

This project allows you to **control a motorized projector screen remotely** using an ESP32 and Arduino setup. It uses the **Blynk IoT app** to trigger **4 relays**, which control the direction and movement of a **DC geared motor** that rolls the screen up or down.

---

## 🔧 Features

- 📱 Remote control through the Blynk mobile app
- ⚙️ Controls a 4-relay module to drive the DC motor
- 🌐 Uses WiFi-enabled ESP32 for communication
- 🧠 Arduino processes control logic based on inputs from ESP32
- 🎛️ Two virtual buttons in Blynk trigger screen up/down

---

## 🧰 Components Used

| Component         | Quantity | Function                        |
|-------------------|----------|---------------------------------|
| ESP32 Dev Board   | 1        | Connects to WiFi + Blynk app    |
| Arduino Uno/Nano  | 1        | Drives relay control logic      |
| 4-Channel Relay   | 1        | Controls direction of motor     |
| DC Geared Motor   | 1        | Moves the screen                |
| Smartphone        | 1        | Runs the Blynk app              |
| Jumper Wires      | —        | For circuit connections         |
| Power Source      | 1        | For motor and microcontrollers  |

---

## 🗂️ How It Works

1. **Blynk App** has 2 buttons:
   - Button 1 (Virtual Pin V0) — Screen Up
   - Button 2 (Virtual Pin V1) — Screen Down

2. When a button is pressed:
   - ESP32 sends a HIGH signal to a digital pin (GPIO18 or GPIO19).
   - These pins are connected to Arduino’s analog pins A0 and A1 (used as digital inputs).
   - Based on the input received, Arduino activates 2 of the 4 relays to run the motor in the appropriate direction.
   - When no button is pressed, all relays turn OFF to stop the motor.

---

## 📲 Blynk Setup Guide

1. Open the Blynk app.
2. Create a new project and link your **BLYNK_TEMPLATE_ID**, **BLYNK_AUTH_TOKEN**, and **WiFi credentials** in the ESP32 code.
3. Add 2 buttons:
   - Button 1: Virtual Pin V0 (Screen UP)
   - Button 2: Virtual Pin V1 (Screen DOWN)
4. Set both buttons to **Switch mode** (toggle behavior).

---

## 🧾 Code Summary

### ESP32 Code:
- Connects to WiFi and Blynk server.
- Monitors virtual pins V0 and V1.
- Sends HIGH/LOW signals to GPIO18 and GPIO19.

### Arduino Code:
- Reads ESP32 signals on A0 and A1.
- Controls relays:
  - A0 HIGH → Activate Relay1 & Relay2 (Motor Forward)
  - A1 HIGH → Activate Relay3 & Relay4 (Motor Reverse)
  - Both LOW → All Relays OFF

---

## 🔌 Pin Mapping

### ESP32 to Arduino

| ESP32 Pin | Arduino Pin | Purpose        |
|-----------|-------------|----------------|
| GPIO18    | A0          | Screen UP      |
| GPIO19    | A1          | Screen DOWN    |

### Arduino Relay Pins

| Arduino Pin | Connected Relay | Action             |
|-------------|------------------|-------------------|
| 4           | Relay 1          | Motor Forward     |
| 5           | Relay 2          | Motor Forward     |
| 6           | Relay 3          | Motor Reverse     |
| 7           | Relay 4          | Motor Reverse     |

---

⚠️ Notes

- Ensure relays are capable of handling motor voltage/current.
- Avoid switching motor direction rapidly without delay.
- Add physical **limit switches** to prevent over-rolling.
- Secure all connections to avoid shorts.
