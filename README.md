BreadOS - Minimalist Operating System
-------------------------------------

BreadOS is a lightweight and open-source operating system designed for compact devices like headphone cases. It features a simple interactive menu and basic device management functions.

Features:
- ASCII bread logo at startup
- Signature: by NameSugar
- Interactive menu:
  1. Battery Status - shows battery level
  2. Device Info - shows device information
  3. Sleep Mode - enters sleep mode
- Works on x86 emulators (QEMU, Bochs)

Build and Run:
1. Clone the repository:
   git clone https://github.com/yourusername/BreadOS.git
   cd BreadOS

2. Build:
   make

3. Run in QEMU:
   qemu-system-i386 -fda breados.bin

License:
BreadOS is licensed under the MIT License.
Copyright (c) 2025 NameSugar

History:
Earlier experimental versions had limited functionality. This version is stable and interactive.
