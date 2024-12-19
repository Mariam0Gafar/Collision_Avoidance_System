add_executable(${ProjectName}
    main.c
    IR.c 
    LDR.c 
    LED.c 
    Buzzer.c 
    Ultrasonic.c 
    DCMotor.c
)

target_include_directories(${ProjectName} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

pico_enable_stdio_uart(${ProjectName} 0)
pico_enable_stdio_usb(${ProjectName} 1)

target_link_libraries(${ProjectName} 
    pico_stdlib 
    FreeRTOS-Kernel-Heap4 
    hardware_pwm
    )

pico_add_extra_outputs(${ProjectName})