add_executable(mcu_thruster
        mcu_thruster.cpp
        )

# pull in common dependencies and additional pwm hardware support
target_link_libraries(mcu_thruster pico_stdlib hardware_pwm)

# create map/bin/hex file etc.
pico_add_extra_outputs(mcu_thruster)
pico_enable_stdio_usb(mcu_thruster 1)

# add url via pico_set_program_url
example_auto_set_url(mcu_thruster)

