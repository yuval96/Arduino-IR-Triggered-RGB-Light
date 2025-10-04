# Arduino IR-Triggered RGB Light

A simple Arduino Uno project: an RGB LED turns on when an **IR proximity sensor** detects movement (e.g. under a desk), stays on for a few seconds, and then turns off automatically.  
The microcontroller is put into **low-power sleep mode** and wakes up only on sensor trigger, saving energy.

---

## Features
- ✅ IR sensor input (active LOW)  
- ✅ RGB LED output with PWM control  
- ✅ Interrupt-driven event handling (no busy loop)  
- ✅ Low-power mode using [LowPower library](https://github.com/rocketscream/Low-Power)  
- ✅ Configurable light-on duration (default: 5 seconds)

---

## Hardware
- Arduino Uno (ATmega328P)  
- IR sensor module (digital output)  
- RGB LED module (common cathode or common anode – adjust `analogWrite` logic accordingly)  
- Resistors (if using bare LEDs)  
- Jumper wires & breadboard  

---

## Wiring
| Arduino Pin | Component  |
|-------------|------------|
| D2          | IR Sensor OUT |
| GND         | IR Sensor GND |
| 5V          | IR Sensor VCC |
| D3          | RGB LED Red (R) |
| D5          | RGB LED Green (G) |
| D6          | RGB LED Blue (B) |
| GND         | RGB LED Common (Cathode) |

*(If your RGB is **Common Anode**, connect common to 5V and invert the logic in code)*

---

## Code
See [`main.ino`](main.ino) for the full implementation.  
Core idea:
```cpp
attachInterrupt(digitalPinToInterrupt(IR), IR_ISR, FALLING);
// Sleep until interrupt wakes Arduino
LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
