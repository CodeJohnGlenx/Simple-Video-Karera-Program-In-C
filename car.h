#include <string.h>
#include <stdlib.h>
#ifndef CAR_H
#define CAR_H

typedef struct car {
    int gas;
    int distance;
    int lap;
    char *color;
    char *paint;
} car;


void create_car(car *new_car, int gas, int distance, int lap, char *color, char *paint)
{
    new_car->gas = gas;
    new_car->distance = distance;
    new_car->lap = lap;
    new_car->color = malloc(20 * sizeof(char));
    new_car->paint = malloc(20 * sizeof(char));
    strcpy(new_car->color, color);
    strcpy(new_car->paint, paint);
}

// you must always free all what you have allocated, else there will be a memory leak
void free_car(car *car_to_free)
{
    free(car_to_free->color);
    free(car_to_free->paint);
    free(car_to_free);
}

#endif
