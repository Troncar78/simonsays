# Circuit Documentation

## Summary
This circuit is designed to interface an ESP32 Wroom microcontroller with four LEDs of different colors (red, yellow, blue, and green). The ESP32 Wroom controls the LEDs, which are connected to specific GPIO pins. Each LED has an anode and a cathode, with the cathodes of all LEDs connected to the ground (GND) of the ESP32 Wroom, and the anodes connected to different GPIO pins for individual control.

## Component List

### ESP32 Wroom
- **Description:** A powerful microcontroller with Wi-Fi and Bluetooth capabilities, suitable for a variety of IoT applications.
- **Pins:**
  - 2 (3V3)
  - 3 (Reset)
  - 4 (GPIO36)
  - 5 (GPIO39)
  - 6 (GPIO34)
  - 7 (GPIO35)
  - 8 (GPIO32)
  - 9 (GPIO33)
  - 10 (GPIO25)
  - 11 (GPIO26)
  - 12 (GPIO27)
  - 13 (GPIO14)
  - 14 (GPIO12)
  - GND
  - 16 (GPIO13)
  - 17 (GPIO9)
  - 18 (GPIO10)
  - 19 (GPIO11)
  - 5V
  - 37 (GPIO23)
  - 36 (GPIO22/SCL)
  - 35 (GPIO1/TXD0)
  - 34 (GPIO3/RXD0)
  - 33 (GPIO21/SDA)
  - 31 (GPIO19)
  - 30 (GPIO18)
  - 29 (GPIO5)
  - 28 (GPIO17)
  - 27 (GPIO16)
  - 26 (GPIO4)
  - 25 (GPIO0)
  - 24 (GPIO2)
  - 23 (GPIO15)
  - 22 (GPIO8)
  - 21 (GPIO7)
  - 20 (GPIO6)

### LED: Two Pin (red)
- **Pins:**
  - cathode
  - anode

### LED: Two Pin (yellow)
- **Pins:**
  - cathode
  - anode

### LED: Two Pin (blue)
- **Pins:**
  - cathode
  - anode

### LED: Two Pin (green)
- **Pins:**
  - cathode
  - anode

## Wiring Details

### ESP32 Wroom
- **GND:** Connected to the cathodes of the blue, yellow, green, and red LEDs.
- **31 (GPIO19):** Connected to the anode of the yellow LED.
- **30 (GPIO18):** Connected to the anode of the blue LED.
- **13 (GPIO14):** Connected to the anode of the green LED.
- **12 (GPIO27):** Connected to the anode of the red LED.

### LED: Two Pin (red)
- **Cathode:** Connected to GND of ESP32 Wroom.
- **Anode:** Connected to GPIO27 of ESP32 Wroom.

### LED: Two Pin (yellow)
- **Cathode:** Connected to GND of ESP32 Wroom.
- **Anode:** Connected to GPIO19 of ESP32 Wroom.

### LED: Two Pin (blue)
- **Cathode:** Connected to GND of ESP32 Wroom.
- **Anode:** Connected to GPIO18 of ESP32 Wroom.

### LED: Two Pin (green)
- **Cathode:** Connected to GND of ESP32 Wroom.
- **Anode:** Connected to GPIO14 of ESP32 Wroom.

## Documented Code
No code has been provided for the microcontroller. The expected behavior would be to initialize the GPIO pins connected to the anodes of the LEDs as output and to control them by setting the pins high or low to turn the LEDs on or off, respectively. However, without the actual code, we cannot provide further documentation on the software aspect of this circuit.
