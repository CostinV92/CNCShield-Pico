#include <stdio.h>
#include "CNCShield.h"
#include "pico/stdlib.h"

#define NO_OF_STEPS               200
#define SLEEP_BETWEEN_STEPS_MS    10
#define SPEED_STEPS_PER_SECOND    100

#define X_STP       28
#define X_DIR       22

#define Y_STP       27
#define Y_DIR       21

#define Z_STP       26
#define Z_DIR       20

#define ENABLE      19       

int main()
{
    int state = 1;
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    gpio_put(PICO_DEFAULT_LED_PIN, state);

    /*
     * Create a CNCShield object and get a pointer to motor 0 (X axis).
     */
    CNCShield cnc_shield(X_STP, X_DIR,
                         Y_STP, Y_DIR,
                         Z_STP, Z_DIR,
                         ENABLE);

    StepperMotor *motor = cnc_shield.get_motor(X_MOTOR);
    /*
     * Enable the shield (set enable pin to LOW).
     */
    cnc_shield.enable();

    /*
     * Step in a previously set direction.
     */
    cnc_shield.set_dir(X_MOTOR, CLOCKWISE);
    for (int i = 0; i < NO_OF_STEPS; i++) {
        motor->step();
        sleep_ms(SLEEP_BETWEEN_STEPS_MS);
    }
    cnc_shield.set_dir(X_MOTOR, COUNTER);
    for (int i = 0; i < NO_OF_STEPS; i++) {
      motor->step();
      sleep_ms(SLEEP_BETWEEN_STEPS_MS);
    }

    /*
     * Step in a direction.
     */
    for (int i = 0; i < NO_OF_STEPS; i++) {
      motor->step(CLOCKWISE);
      sleep_ms(SLEEP_BETWEEN_STEPS_MS);
    }

    for (int i = 0; i < NO_OF_STEPS; i++) {
      motor->step(COUNTER);
      sleep_ms(SLEEP_BETWEEN_STEPS_MS);
    }

    /*
     *  Step a number of steps in a previously set direction
     *   with a previously set speed.
     */
    motor->set_speed(SPEED_STEPS_PER_SECOND);
    motor->set_dir(CLOCKWISE);
    motor->step(200);

    motor->set_dir(COUNTER);
    motor->step(200);

    /*
     *  Step a number of steps in a direction
     *   with a previously set speed.
     */
    motor->set_speed(SPEED_STEPS_PER_SECOND);
    motor->step(200, CLOCKWISE);
    motor->step(200, COUNTER);
 
    cnc_shield.disable();
}
