#include "car.h"
#include "variables.h"

/*
car.h contains:
    struct car

variables.h contains:
    final_lap
    distance_to_lap
*/

void drive(car *current_car)
{
    // car moves if gas is at least 100
    if (current_car->lap < final_lap)
    {
        current_car->gas += rand() % 100;

        if (current_car->gas >= 100)
        {
            current_car->gas -= 100;
            current_car->distance++;
        }

        if (current_car->distance == distance_to_lap)
        {
            current_car->distance = 0;
            current_car->lap++;
            srand(time(NULL));
        }
    }
}
