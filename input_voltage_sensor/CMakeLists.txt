add_executable(input_voltage_sense
        input_voltage_sense.cpp
        )

target_link_libraries(input_voltage_sense pico_stdlib hardware_adc)

pico_enable_stdio_usb(input_voltage_sense 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(input_voltage_sense)

# add url via pico_set_program_url
example_auto_set_url(input_voltage_sense)
