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

auto perfect_numbers(){
    int num = 2;
    while (true){
        double num_sqrt = sqrt(num);
        double sum = 1;
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
double pi_approx_integral(int iters){
    int a = -1;
    int b = 1;
    vector<double> divisions;
    ;
    for (int i = 0; i<(iters+1); i++){
        divisions.push_back(((double)(i)/(double)((iters+1))));
    };
    double num = 0;
    double width = (divisions[1]*(b-a));
    int index = 0;
    double division = divisions[0];
    for (auto division_pointer = divisions.begin(); division_pointer != divisions.end(); ++division_pointer){
        division = *division_pointer;
        double x = ((((b-a)*division)+a)+((double)(width)/(double)(2)));
        num += (sqrt((1-pow(x, 2)))*width);
        if (((index%1000)==0)){
            printf("%.10lf %s%s", (((double)(index)/(double)(divisions.size()))*100), "%", "\n");
        };
        index += 1;
    };
    return (2*num);
};
int main(){
    printf("%.30f%s", pi_approx_integral((int)(pow(2, 20))), "\n");
    return 0;
};
