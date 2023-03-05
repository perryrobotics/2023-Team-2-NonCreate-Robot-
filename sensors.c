#include <kipr/wombat.h>
#include "constants.h"
void forward_to_black(int speed,int port)
{

    mav(RM, speed);
    mav(LM, speed);

    while(analog(port) < BLACK)
    {
    }

    mav(RM, 0);
    mav(LM, 0);
}

void backward_to_black(int speed,int port)
{

    mav(RM, -speed);
    mav(LM, -speed);

    while(analog(port) < BLACK)
    {
    }

    mav(RM, 0);
    mav(LM, 0);
}

void right_to_black(int speed,int port)
{

    mav(RM, -speed);
    mav(LM, speed);

    while(analog(port) < BLACK)
    {
    }

    mav(RM, 0);
    mav(LM, 0);
}

void left_to_black(int speed,int port)
{

    mav(RM, speed);
    mav(LM, -speed);

    while(analog(port) < BLACK)
    {
    }

    mav(RM, 0);
    mav(LM, 0);
}

void line_follow_to_black(int speed, int port, int watch_port)
{

    while( analog(watch_port)< BLACK )
    {
        if (analog(port) < BLACK)
        {
            // over white
            printf("I SEE WHITE!!!!\n");
            mav(LM, speed);
            mav(RM, speed+50);
        }
        else
        {
            printf("I SEE BLACK!!!!\n");
            mav(LM, speed+600);
            mav(RM, speed);
        }
    }// end while
    
    mav(LM, 0);
    mav(RM, 0);
    
}

void line_follow_ticks(int speed, int port, int ticks)
{
        msleep(100);
    cmpc(LM);
    cmpc(RM);
    msleep(100);

    
    while( gmpc(LM) < ticks)
    {
        if (analog(port) < BLACK)
        {
            // over white
            printf("I SEE WHITE!!!!\n");
            mav(LM, speed);
            mav(RM, speed+50);
        }
        else
        {
            printf("I SEE BLACK!!!!\n");
            mav(LM, speed+600);
            mav(RM, speed);
        }
    }// end while
    
    mav(LM, 0);
    mav(RM, 0);
    
}







