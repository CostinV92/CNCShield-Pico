/* 
 * CNC Shield library for Raspberry Pi Pico
 * https://blog.protoneer.co.nz/arduino-cnc-shield
 *
 * Written by Victor Gabriel Costin.
 * Licensed under the MIT license.
 */

#ifndef __CNC_SHIELD_HPP__
#define __CNC_SHIELD_HPP__

typedef enum {
    COUNTER = 0,
    CLOCKWISE
} direction_t;

typedef enum {
    INVALID = -1,
    X_MOTOR,
    Y_MOTOR,
    Z_MOTOR,
    ALL_MOTORS
} motor_id_t;

class CNCShield;

class StepperMotor {
private:
    motor_id_t      _id;
    int             _stp_pin;
    int             _dir_pin;
    direction_t     _dir = COUNTER;
    int             _speed = 0; /* steps per second */
    double          _speed_delay = 0; /* ms between steps */

    StepperMotor(motor_id_t id = INVALID, int stp_pin = 0, int dir_pin = 0);

    void            _init(motor_id_t id);

    int             _get_stp_pin();
    void            _set_stp_pin(int stp_pin);

    int             _get_dir_pin();
    void            _set_dir_pin(int dir_pin);

    void            _step();

public:
    bool            step();
    bool            step(direction_t dir);
    bool            step(int nr_steps);
    bool            step(int nr_steps, direction_t dir);

    direction_t     get_dir();
    void            set_dir(direction_t _dir);

    double          get_speed();
    void            set_speed(double speed);

    motor_id_t      get_id();

    friend class CNCShield;
};

class CNCShield {
private:
    int             _en_pin;
    StepperMotor    _motors[3];

public:
    CNCShield(int x_stp, int x_dir,
              int y_stp, int y_dir,
              int z_stp, int z_dir,
              int en_pin);

    void            enable();
    void            disable();

    StepperMotor*   get_motor(motor_id_t motor_id);

    direction_t     get_dir(motor_id_t motor_id);
    void            set_dir(motor_id_t motor_id, direction_t dir);

    double          get_speed(motor_id_t motor_id);
    void            set_speed(motor_id_t motor_id, double speed);
};

#endif /* __CNC_SHIELD_HPP__ */
