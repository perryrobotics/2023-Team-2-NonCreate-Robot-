#include <kipr/wombat.h>
#include <time.h>
#include "movement.h"
#include "constants.h"
#include "sensors.h"
#include "effectors.h"
void forward(int speed,int ticks);

int main2()
{
    int start_time;
    printf("Hello World\n");


    enable_servos();
    set_servo_position(LEFT_SCOOP_SERVO, LEFT_SCOOP_OPEN);
    out_line_up();

    wait_for_light(LIGHT);

    shut_down_in(119);
    start_time=time(NULL);


    //Start!!!!!!!
    forward(900, 300);
    right(900, 1100);
    forward(900, 6450);
    left(900, 600);
    forward(900, 1300);
    //wireshark_aquired
    left(900, 400);
    forward_to_black(1000,BACK_LINE);
    set_servo_position(LEFT_SCOOP_SERVO, 1050);
    left(200, 600);
    forward(900, 1000);
    left(800,500);
    forward(8000,3200);
    left(750,450);
    
    //DRIFT
    motor(LM,45);
    motor(RM,50);
    out_line_down();
    while (analog(OUT_LINE)<BLACK)
    {
    }
    motor(LM,0);
    motor(RM,0);
    out_line_up();
    msleep(100);
    right(750,600);
    forward_to_black(1000, FRONT_LINE); 
    
    // WE ARE AT THE CENTER BLACK LINE
    forward(1000, 1000);
    out_line_down();
    line_follow_ticks(750, OUT_LINE, 9000); 
    out_line_up();
    backward(500,150);
    left(500,600);
    forward(500,500);
    
    //WAIT FOR PONG DROP
    while ( time(NULL) - start_time < 61)
    {
    }

    left(1000,1200);
    forward(1000,5900);
    
    // ping pong balls scored time to get poms
    set_servo_position(LEFT_SCOOP_SERVO, LEFT_SCOOP_OPEN);
    msleep(1000);
    backward(1000,1000);
    left(1000,1000);
    forward_to_black(1000, FRONT_LINE);
    forward(1000,900);
    right(1000,750);
    
    //KNOCK RED POMS
    left_to_black(1000,FRONT_LINE);
    forward(2100,2600);
    right(350,530);
    forward(1000,700);
    
    //green poms delivered to Storage Room
    backward(1000,1680);
    left(1000,350);
    forward(1000,2500);
    left(1000,500);
    forward(1000,1000);
    left(1000,2250);
    forward_to_black(1000, FRONT_LINE);
    forward(1000,2000);
    
    //2 red poms delivered
    backward(1000,6250);
    left(1000,830);
    forward(1000,1486);
    
    //ON POM PILE
    set_servo_position(LEFT_SCOOP_SERVO, LEFT_SCOOP_CLOSED);
    forward(1000, 670);
    msleep(1000); 
    forward(1000,2000);
    right(1000,1200);
    forward_to_black(1000, FRONT_LINE);	
    forward(1500, 3200);
    
    //RED POMS DELIVERED
    backward(1500, 1875);
    set_servo_position(LEFT_SCOOP_SERVO, LEFT_SCOOP_OPEN);
    msleep(750);
    
    return 0;
}