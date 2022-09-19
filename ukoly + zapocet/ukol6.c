#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Point {
    float x;
    float y;
};

struct Circle {
    struct Point point;
    float r;
};

float circle_perimeter( const struct Circle * self ){
    float circleResult = 2 * M_PI * (*self).r;

    return circleResult;
}

int main(){
    int n = 3;
    float *circleData = NULL;
    
    circleData = malloc(n*sizeof(float));
    for (int i = 0; i < n; i++){
        scanf("%f", &circleData[i]);
    }

    struct Point b1 = {};
    b1.x = circleData[0];
    b1.y = circleData[1];

    struct Circle a1 = {};
    a1.r = circleData[2];
    a1.point = b1;

    float circleResult;
    circleResult = circle_perimeter( &a1 );

    printf("%.2f \n", circleResult);

    free(circleData);

    return 0;
}