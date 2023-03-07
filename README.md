# thruster_interface_board
Codebase for the MCU board, includes PWM, ADC etc.


### Get started
- Download the pico-sdk in your PC. For reference, follow Chapter 2 of the [Pico Setup Guide](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)
- `git clone https://github.com/tjsos/thruster_interface_board.git` into the pico-examples folder.
- Add `add_subdirectory(thruster_interface_board)` to the CMakeLists.txt in the pico-examples folder
- `cd build`
- `cmake ..`
- `cd thruster_interface_board`
- Change directory into the app you want to compile and `make -j4`.
- Drag and drop the .uf2 file into the memory of the pico.
