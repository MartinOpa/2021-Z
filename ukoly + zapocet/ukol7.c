#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

struct Point {
    float x;
    float y;
};

typedef struct Point Point;

struct Circle {
    Point point;
    float r;
};

typedef struct Circle Circle;

bool circle_contains_circle( const Circle * self, const Circle * other ){

    int offset = sqrt(((self->point.x - other->point.x) * (self->point.x - other->point.x)) + ((self->point.y - other->point.y) * (self->point.y - other->point.y)));
    bool ccc;
    
    if (offset + other->r < self->r)
        ccc = true;
        else
            ccc = false;

    return ccc;

}

int main(){

    int n = 3;

    float *circle1 = NULL;
    float *circle2 = NULL;

    circle1 = malloc(n*sizeof(float));

    for (int i = 0; i < n; i++){
        scanf("%f", &circle1[i]);
    }
    
    circle2 = malloc(n*sizeof(float));

    for (int i = 0; i < n; i++){
        scanf("%f", &circle2[i]);
    }

    Point b1 = {};
    b1.x = circle1[0];
    b1.y = circle1[1];
    
    Point b2 = {};
    b2.x = circle2[0];
    b2.y = circle2[1];

    Circle a1 = {};
    a1.r = circle1[2];
    a1.point = b1;

    Circle a2 = {};
    a2.r = circle2[2];
    a2.point = b2;

    bool ccc = circle_contains_circle( &a1, &a2 );

    if ( ccc == true )
        printf("True\n");
        else printf("False\n");

    free( circle1 );
    free( circle2 );

    return 0;
}