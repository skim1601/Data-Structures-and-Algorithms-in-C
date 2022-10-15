#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// x^y
double power(double x, int y){
    if (x == 0 && y == 0){
        return -1;
    } else if (x == 0){
        return 0;
    }

    if (y == 0){
        return 1.0;
    } else if (y < 0){
        return 1 / power(x, -1 * y);
    } else if (y > 0){
        // 2^2 = 2 * 2
        // 2^4 = 2^2 * 2^2

        // 2^3 = 2^1 * 2^1 * 2
        // 2^5 = 2^2 * 2^2 * 2
        if (y % 2 == 0){
            double temp = power(x, y/2);
            return temp * temp;
        } else{
            double temp = power (x, y/2);
            return temp * temp * x;
        }
    } 
}

int main(void){
    printf("%lf", power(2.0, 4));
    printf(" %lf", power(2.0, -6));
    printf(" %lf", power(0, 0));
}