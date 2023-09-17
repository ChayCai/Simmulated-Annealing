#include "../include/dstfunc.h"

// dst function
double E(double x){
    if(x <= 10){
        return x * x;
    }
    return (x - 10) * (x - 10) - 10;
}