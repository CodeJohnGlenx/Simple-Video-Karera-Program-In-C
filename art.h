#include "car.h"
#include "variables.h"

/*
car.h contains:
    struct car

variables.h contains:
    *car1, *car2, *car3, *car4, *car5
    distance_to_lap
*/

void print_video_karera(void)
{
    printf("%s\n", "  _   ___    __           __ __                     ");
    printf("%s\n", " | | / (_)__/ /__ ___    / //_/__ ________ _______ _");
    printf("%s\n", " | |/ / / _  / -_) _ \\  / ,< / _ `/ __/ -_) __/ _ `/");
    printf("%s\n", " |___/_/\\_,_/\\__/\\___/ /_/|_|\\_,_/_/  \\__/_/  \\_,_/ ");
    printf("%s\n", "                                                    ");
}

// the distance are the spaces
void print_distance(car *current_car)
{
    int i;
    for (i = 0; i <= current_car->distance; ++i)
        putchar(' ');
}

void print_car(car *current_car)
{
    printf("%s", current_car->paint);
    print_distance(current_car);
    printf("%s\n", "");
    print_distance(current_car);
    printf("%s\n", "__");
    print_distance(current_car);
    printf("%s\n", ".-'--`-._");
    print_distance(current_car);
    printf("%s", "'-O---O--'");
    printf("\033[0m");  // reset text color
}

void print_lap(car *current_car, int final_lap)
{
    printf("%s", current_car->paint);
    printf("%s car: %d/%d\n", current_car->color, current_car->lap, final_lap);
}

void print_interface(car *car1, car *car2, car *car3, car *car4, car *car5, int final_lap)
{
    system("cls");
    print_video_karera();
    print_lap(car1, final_lap);
    print_lap(car2, final_lap);
    print_lap(car3, final_lap);
    print_lap(car4, final_lap);
    print_lap(car5, final_lap);

    printf("\033[0m");  // reset text color

    // print racetrack markings and cars
    for (int i =0; i <= distance_to_lap + 10; ++i)
        putchar('=');
    putchar('\n');
    print_car(car1);
    print_car(car2);
    print_car(car3);
    print_car(car4);
    print_car(car5);
    putchar('\n');
    printf("\033[0m");  // reset text color
    for (int i =0; i <= distance_to_lap + 10; ++i)
        putchar('=');

    printf("\033[0m");  // reset text color
}
