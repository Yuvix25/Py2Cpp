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


template <typename T>
vector<T>& operator +=(vector<T>& vector1, const vector<T>& vector2) {
    vector1.insert(vector1.end(), vector2.begin(), vector2.end());
    return vector1;
}


template <typename T>
vector<T> operator+(vector<T> vector1, const vector<T>& vector2) {
    vector1 += vector2;
    return vector1;
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
    for (vector<double>::iterator division_pointer = divisions.begin(); division_pointer != divisions.end(); ++division_pointer){
        division = *division_pointer;
        double x = ((((b-a)*division)+a)+((double)(width)/(double)(2)));
        num += (sqrt((1-pow(x, 2)))*width);
        if (((index%1000)==0)){
            printf("%s %.10lf %s%s", " Calculating... ", (((double)(index)/(double)(divisions.size()))*100), "%", "\r");
            fflush(stdout);
        
        };
        index += 1;
    };
    printf("\n");
    return (2*num);
    ;

return double();
};
vector<int> quick_sort(vector<int> arr){
    int n = arr.size();
    if ((n<=1)){
        return arr;
        ;
    
    };
    int mid = arr[floor(((double)(n)/(double)(2)))];
    vector<int> lower;
    ;
    vector<int> higher;
    ;
    vector<int> same;
    ;
    int i = arr[0];
    for (vector<int>::iterator i_pointer = arr.begin(); i_pointer != arr.end(); ++i_pointer){
        i = *i_pointer;
        if ((i<mid)){
            lower.push_back(i);
        
        }
        else if ((i>mid)){
            higher.push_back(i);
        
        }
        else if ((i==mid)){
            same.push_back(i);
        
        };
    };
    return ((quick_sort((vector<int>)(lower))+same)+quick_sort((vector<int>)(higher)));
    ;

return vector<int>();
};
int binary_search(vector<int> arr, int key){
    int n = arr.size();
    int low = 0;
    int high = arr.size();
    while ((low<high)){
        auto mid = floor(((double)((low+high))/(double)(2)));
        if ((arr[mid]<key)){
            low = (mid+1);
        
        }
        else if ((arr[mid]>key)){
            high = (mid-1);
        
        }
        else {
        return mid;
        ;
        };
    };

return int();
};
int main(){
    printf("%s%s", "Pi:", "\n");
    printf("Pi approximation: %.30f%s", pi_approx_integral((int)(pow(2, 24))), "\n");
    printf("\n");
    printf("%s%s", "Array sorting using quick sort:", "\n");
    vector<int> x;
    x.push_back(2);
    x.push_back(4);
    x.push_back(5);
    x.push_back(3);
    x.push_back(7);
    x.push_back(2);
    x.push_back(4);
    x.push_back(2);
    x.push_back(1);
    x.push_back(6);
    x.push_back(4);
    printf("%s%s", "Orinal array:", "\n");
    int i = x[0];
    for (vector<int>::iterator i_pointer = x.begin(); i_pointer != x.end(); ++i_pointer){
        i = *i_pointer;
        printf("%d%s", i, ", ");
    };
    printf("\n");
    vector<int> new_arr = quick_sort((vector<int>)(x));
    printf("%s%s", "Sorted array:", "\n");
    i = new_arr[0];
    for (vector<int>::iterator i_pointer = new_arr.begin(); i_pointer != new_arr.end(); ++i_pointer){
        i = *i_pointer;
        printf("%d%s", i, ", ");
    };
    printf("\n");
    int index = binary_search((vector<int>)(new_arr), (int)(4));
    printf("%s %d%s", "The index of 4, found using binary search, is:", index, "\n");
    return 0;
    ;

return int();
};
