idf_component_register(
    SRCS
        "main.c"

        "drivers/dht11.c"
        "drivers/light_sensor.c"
        "drivers/oled.c"
        "drivers/rgb_led.c"
        "drivers/buzzer.c"
        "drivers/pir.c"

        "system/system_state.c"

        "tasks/sensor_task.c"
        "tasks/display_task.c"
        "tasks/control_task.c"
        "tasks/event_task.c"

    INCLUDE_DIRS "."
)