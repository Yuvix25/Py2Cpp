#include <stdio.h>
#include <time.h>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

clock_t __host_start_time__;
clock_t __host_end_time__;

void start_host_timer(){
    /* Call to start HOST timer which can be stopped with `stop_host_timer`, returns nothing.
    */
    __host_start_time__ = clock();
}

float stop_host_timer(){
    /* Call to stop HOST timer started with `start_host_timer`, returns elapsed time in seconds.
    */
    __host_start_time__ = clock();
    return (__host_end_time__ - __host_start_time__) / CLOCKS_PER_SEC;
}