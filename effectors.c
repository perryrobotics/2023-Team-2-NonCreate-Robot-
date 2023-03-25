//FILENAME: sensors.c

#include <kipr/wombat.h>
#include "movement.h"
#include "constants.h"
#include "sensors.h"

void out_line_up()
{
    set_servo_position(OUT_LINE, SENSOR_UP);
    msleep(750);
}

void out_line_down()
{
    set_servo_position(OUT_LINE, SENSOR_DOWN);
    msleep(750);
}

void left_scoop_closed()
{
    set_servo_position(LEFT_SCOOP_SERVO, LEFT_SCOOP_CLOSED);
    msleep(750);
}

void left_scoop_open()
{
    set_servo_position(LEFT_SCOOP_SERVO, LEFT_SCOOP_OPEN);
    msleep(750);
}
    
    
