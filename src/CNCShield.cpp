/* 
 * CNC Shield library for Raspberry Pi Pico
 * https://blog.protoneer.co.nz/arduino-cnc-shield
 *
 * Written by Victor Gabriel Costin.
 * Licensed under the MIT license.
 */

#include "CNCShield.h"
#include "pico/stdlib.h"
#include <stdio.h>

CNCShield::CNCShield(int x_stp, int x_dir,
                     int y_stp, int y_dir,
                     int z_stp, int z_dir,
                     int en_pin)
{
    _en_pin = en_pin;

    gpio_init(_en_pin);
    gpio_set_dir(_en_pin, GPIO_OUT);

    _motors[0]._set_stp_pin(x_stp);
    _motors[0]._set_dir_pin(x_dir);

    _motors[1]._set_stp_pin(y_stp);
    _motors[1]._set_dir_pin(y_dir);

    _motors[2]._set_stp_pin(z_stp);
    _motors[2]._set_dir_pin(z_dir);

    for (int i = X_MOTOR; i < ALL_MOTORS; ++i)
        _motors[i]._init(static_cast<motor_id_t>(i));

#ifdef DEBUG
    stdio_init_all();
#endif /* DEBUG */
}

void CNCShield::enable()
{
    gpio_put(_en_pin, 0);

#ifdef DEBUG
    printf("CNCShield::enable()\n");
#endif /* DEBUG */
}

void CNCShield::disable()
{
    gpio_put(_en_pin, 1);

#ifdef DEBUG
    printf("CNCShield::disable()\n");
#endif /* DEBUG */
}

StepperMotor* CNCShield::get_motor(motor_id_t motor_id)
{
    if (motor_id == INVALID || motor_id > Z_MOTOR)
        return &_motors[Z_MOTOR];

    return &_motors[motor_id];
}

direction_t CNCShield::get_dir(motor_id_t motor_id)
{
    if (motor_id == INVALID || motor_id > Z_MOTOR)
        motor_id = Z_MOTOR;

    return _motors[motor_id].get_dir();
}

void CNCShield::set_dir(motor_id_t motor_id, direction_t dir)
{
    if (motor_id == INVALID || motor_id > ALL_MOTORS)
        motor_id = ALL_MOTORS;

    if (motor_id == ALL_MOTORS) {
        for (int i = 0; i < motor_id; i++)
            _motors[i].set_dir(dir);
    } else {
        _motors[motor_id].set_dir(dir);
    }
}

double CNCShield::get_speed(motor_id_t motor_id)
{
    if (motor_id == INVALID || motor_id > Z_MOTOR)
        motor_id = Z_MOTOR;

    return _motors[motor_id].get_speed();
}

void CNCShield::set_speed(motor_id_t motor_id, double speed)
{
    if (motor_id == INVALID || motor_id > ALL_MOTORS)
        motor_id = ALL_MOTORS;

    if (motor_id == ALL_MOTORS) {
        for (int i = 0; i < motor_id; i++)
            _motors[i].set_speed(speed);
    } else {
        _motors[motor_id].set_speed(speed);
    }
}
