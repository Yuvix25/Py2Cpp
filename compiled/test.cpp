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

auto perfect_numbers(){
    int num = 2;
    while (true){
        float num_sqrt = sqrt(num);
        int sum = 1;
        for (int i = 2; i<ceil((double)(num_sqrt)); i++){
            if ((i==num_sqrt)){
                sum += i;
            }
            else if (((num%i)==0)){
                sum += (i+((double)(num)/(double)(i)));
            };
        };
        if ((sum==num)){
            printf("%d%s", num, "\n");
        };
        num += 1;
    };
};
float pi_approx_integral(int iters){
    int a = -1;
    int b = 1;
    vector<float> divisions;
    ;
    for (int i = 0; i<(iters+1); i++){
        divisions.push_back(((double)(i)/(double)((iters+1))));
    };
    float num = 0.0;
    float width = (divisions[1]*(b-a));
    float division = divisions[0];
    for (auto division_pointer = divisions.begin(); division_pointer != divisions.end(); ++division_pointer){
        division = *division_pointer;
        float x = ((((b-a)*division)+a)+((double)(width)/(double)(2)));
        num += (sqrt((1-pow(x, 2)))*width);
    };
    return (2*num);
};
int main(){
    printf("%.10f%s", pi_approx_integral((int)(pow(2, 20))), "\n");
    return 0;
};
