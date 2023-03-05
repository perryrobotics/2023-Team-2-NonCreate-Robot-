#include <kipr/wombat.h>
#include "constants.h"

void forward(int speed,int ticks)
{
    msleep(100);
    cmpc(LM);
    cmpc(RM);
    msleep(100);
    mav(LM, speed);
    mav(RM, speed);
    while(gmpc(LM) <= ticks)
    {
    }
    mav(LM,0);
    mav(RM,0);
    msleep(100);
}


void backward(int speed,int ticks)
{
    msleep(100);
    cmpc(LM);
    cmpc(RM);
    msleep(100);
    mav(LM, -speed);
    mav(RM, -speed);
    while(gmpc(LM) >= -ticks)
    {
    }
    mav(LM,0);
    mav(RM,0);
    msleep(100);
}

void right(int speed,int ticks)
{
    msleep(100);
    cmpc(LM);
    cmpc(RM);
    msleep(100);
    mav(LM, speed);
    mav(RM, -speed);
    while(gmpc(LM) <= ticks)
    {
    }
    mav(LM,0);
    mav(RM,0);
    msleep(100);
}


void left(int speed,int ticks)
{
    msleep(100);
    cmpc(LM);
    cmpc(RM);
    msleep(100);
    mav(LM, -speed);
    mav(RM, speed);
    while(gmpc(LM) >= -ticks)
    {
    }
    mav(LM,0);
    mav(RM,0);
    msleep(100);
}