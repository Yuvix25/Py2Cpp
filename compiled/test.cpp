#include <stdio.h>
#include <time.h>
#include <math.h>

clock_t __timer_start_time__;
clock_t __timer_end_time__;

void start_timer(){
    /* Call to start HOST timer which can be stopped with `stop_host_timer`, returns nothing.
    */
    __timer_start_time__ = clock();
}

float stop_timer(){
    /* Call to stop HOST timer started with `start_host_timer`, returns elapsed time in seconds.
    */
    __timer_start_time__ = clock();
    return (__timer_end_time__ - __timer_start_time__) / CLOCKS_PER_SEC;
}


int main(){
    double num[1] = {0};

    printf("%.10lf%s", num[0], "\n");
    
    return 0;
};
