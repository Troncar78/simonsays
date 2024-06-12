# Circuit Documentation

## Summary
The circuit in question appears to be a simple LED control circuit utilizing an ESP32 Wroom microcontroller to drive multiple LEDs. There are four LEDs of different colors (red, green, yellow, and blue) that are likely intended to be switched on or off by the ESP32 Wroom's GPIO pins. The common cathodes of the blue and yellow LEDs are connected together, while the red and green LEDs have their cathodes connected to the ground (GND) of the ESP32 Wroom. The anodes of each LED are individually connected to different GPIO pins on the ESP32 Wroom, allowing for independent control of each LED.

## Component List

### ESP32 Wroom
- **Description:** A powerful microcontroller with Wi-Fi and Bluetooth capabilities, suitable for a wide range of applications including IoT devices.
- **Pins:** 
  - 3V3
  - Reset
  - GPIO36
  - GPIO39
  - GPIO34
  - GPIO35
  - GPIO32
  - GPIO33
  - GPIO25
  - GPIO26
  - GPIO27
  - GPIO14
  - GPIO12
  - GND
  - GPIO13
  - GPIO9
  - GPIO10
  - GPIO11
  - 5V
  - GPIO23
  - GPIO22/SCL
  - GPIO1/TXD0
  - GPIO3/RXD0
  - GPIO21/SDA
  - GPIO19
  - GPIO18
  - GPIO5
  - GPIO17
  - GPIO16
  - GPIO4
  - GPIO0
  - GPIO2
  - GPIO15
  - GPIO8
  - GPIO7
  - GPIO6

### LED: Two Pin (Red)
- **Description:** A red LED used for indication purposes.
- **Pins:** cathode, anode.

### LED: Two Pin (Green)
- **Description:** A green LED used for indication purposes.
- **Pins:** cathode, anode.

### LED: Two Pin (Yellow)
- **Description:** A yellow LED used for indication purposes.
- **Pins:** cathode, anode.

### LED: Two Pin (Blue)
- **Description:** A blue LED used for indication purposes.
- **Pins:** cathode, anode.

## Wiring Details

### ESP32 Wroom
- **GND:** Connected to the cathodes of the red and green LEDs.
- **GPIO9 (Pin 17):** Connected to the anode of the red LED.
- **GPIO10 (Pin 18):** Connected to the anode of the green LED.

### LED: Two Pin (Red)
- **Cathode:** Connected to the GND of the ESP32 Wroom.
- **Anode:** Connected to GPIO9 (Pin 17) of the ESP32 Wroom.

### LED: Two Pin (Green)
- **Cathode:** Connected to the GND of the ESP32 Wroom.
- **Anode:** Connected to GPIO10 (Pin 18) of the ESP32 Wroom.

### LED: Two Pin (Yellow)
- **Cathode:** Connected to the cathode of the blue LED.
- **Anode:** No connection specified.

### LED: Two Pin (Blue)
- **Cathode:** Connected to the cathode of the yellow LED.
- **Anode:** No connection specified.
