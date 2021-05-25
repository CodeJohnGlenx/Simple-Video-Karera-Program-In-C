#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "car.h"
#include "art.h"
#include "colors.h"
#include "race.c"
#include "variables.h"

/*
art.h contains:
    print_interface()

car.h contains:
    struct car
    create_car()

colors.h contains:
    green, red, white, yellow, cyan

variables.h contains:
    *car1, *car2, *car3, *car4, *car5
    final_lap
*/

void main()
{
    srand(time(NULL));  // generate random seed to avoid repetition of result

    final_lap = rand() % 5 + 6;

    // allocate memory to cars
    car1 = (car *) malloc(sizeof(car));
    car2 = (car *) malloc(sizeof(car));
    car3 = (car *) malloc(sizeof(car));
    car4 = (car *) malloc(sizeof(car));
    car5 = (car *) malloc(sizeof(car));

    // initialization of values to cars
    create_car(car1, 0, 0, 0, "green", green);
    create_car(car2, 0, 0, 0, "red", red);
    create_car(car3, 0, 0, 0, "white", white);
    create_car(car4, 0, 0, 0, "yellow", yellow);
    create_car(car5, 0, 0, 0, "cyan", cyan);


    // continue racing until all cars are finished
    while ((car1->lap < final_lap) || (car2->lap < final_lap) ||
    (car3->lap < final_lap) || (car4->lap < final_lap) || (car5->lap < final_lap))
    {
        sleep(0.01);
        drive(car1);
        drive(car2);
        drive(car3);
        drive(car4);
        drive(car5);
        print_interface(car1, car2, car3, car4, car5, final_lap);
    }

    // just like the birds, you set the cars free!
    free_car(car1);
    free_car(car2);
    free_car(car3);
    free_car(car4);
    free_car(car5);
    printf("\033[0m");  // reset text color
}
