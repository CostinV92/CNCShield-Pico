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

StepperMotor::StepperMotor(motor_id_t id, int stp_pin, int dir_pin):
    _id(id), _stp_pin(stp_pin), _dir_pin(dir_pin) {}

void StepperMotor::_init(motor_id_t id)
{
    _id = id;

    gpio_init(_stp_pin);
    gpio_set_dir(_stp_pin, GPIO_OUT);
    gpio_put(_stp_pin, 0);

    gpio_init(_dir_pin);
    gpio_set_dir(_dir_pin, GPIO_OUT);
    gpio_put(_dir_pin, 0);
}

int StepperMotor::_get_stp_pin()
{
    return _stp_pin;
}

void StepperMotor::_set_stp_pin(int stp_pin)
{
    _stp_pin = stp_pin;
}

int StepperMotor::_get_dir_pin()
{
    return _dir_pin;
}

void StepperMotor::_set_dir_pin(int dir_pin)
{
    _dir_pin = dir_pin;
}

void StepperMotor::_step()
{
    gpio_put(_stp_pin, 1);
    sleep_us(1);
    gpio_put(_stp_pin, 0);
}

bool StepperMotor::step()
{
    _step();

    return true;
}

bool StepperMotor::step(direction_t dir)
{
    if (_dir != dir)
        set_dir(dir);

    return step();
}

bool StepperMotor::step(int nr_steps)
{
    if (_speed == 0)
        return false;

#ifdef DEBUG
    printf("StepperMotor::step_n()\n");
#endif /* DEBUG */

    for (int i = 0; i < nr_steps; i++) {
        _step();
        sleep_ms(_speed_delay);
    }
}

bool StepperMotor::step(int nr_steps, direction_t dir)
{
    if (_dir != dir)
        set_dir(dir);

    return step(nr_steps);
}

direction_t StepperMotor::get_dir()
{
#ifdef DEBUG
    printf("StepperMotor::get_dir(): dir: %d\n", _dir);
#endif /* DEBUG */

    return _dir;
}

void StepperMotor::set_dir(direction_t dir)
{
    if (_dir != dir) {
#ifdef DEBUG
        printf("StepperMotor::set_dir(): dir changed from %d to %d\n", dir, _dir);
#endif /* DEBUG */
        _dir = dir;

        gpio_put(_dir_pin, _dir);
    }
}

double StepperMotor::get_speed()
{
    return _speed;
}

void StepperMotor::set_speed(double speed)
{
    _speed = speed;
    _speed_delay = 1000 / _speed;
}

motor_id_t StepperMotor::get_id()
{
    return _id;
}