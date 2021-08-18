#include <stdio.h>
#include <time.h>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

clock_t __start_time__;
clock_t __stop_time__;

void start_timer(){
    /* Call to start timer which can be stopped with `stop_timer`, returns nothing.
    */
    __start_time__ = clock();
}

float stop_timer(){
    /* Call to stop timer started with `start_timer`, returns elapsed time in seconds.
    */
    __start_time__ = clock();
    return (__stop_time__ - __start_time__) / CLOCKS_PER_SEC;
}