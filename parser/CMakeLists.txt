add_executable(parser
        parser.cpp
        )

# pull in common dependencies
target_link_libraries(parser pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(parser)

# add url via pico_set_program_url
example_auto_set_url(parser)

# enable usb port
pico_enable_stdio_usb(parser 1)
