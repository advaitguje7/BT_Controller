This is a program to play games via Bluetooth using an ESP-32. It is designed around Minecraft's default binds, but the controls can be changed as needed. Note that since this program uses the BleCombo library, you'll need to downgrade the ESP-32 version to 2.x.x. I used 2.0.17.

## To-Do
- [x] Basic motion: strafing (buttons), looking around (joystick 1)
- [x] Advanced Motion: Run linear and translational motion simultaneously (look around while walking)
- [ ] Hardware-based Changes: Replace buttons with a second joystick, implement ABXY control with buttons, add other buttons (LT, RT, LB, RB)
- [ ] Optimization: Improve deadzones, turn speeds, and implement device naming functionality
- [ ] Make README more detailed

## Overview
## Schematic
<img width="808" height="501" alt="image" src="https://github.com/user-attachments/assets/acdf3180-b2ea-4c29-97d9-1294470191ae" />
