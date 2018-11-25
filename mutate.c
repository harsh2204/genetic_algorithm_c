#include "a4.h"
#include <time.h>
#include <stdlib.h>

void mutate(Individual *individual, double rate)
{
    // srand(time(NULL));
    // srand((unsigned int)time(NULL));
    int img_size = individual->image.height * individual->image.width;
    // printf("image size : %d", img_size);
    int selects = (int) ((rate/100)*img_size);
    int upperBound = individual->image.max_color + 1;
    // printf("Mutating %d pixels\n", selects);
    while(selects!=0)
    {
        int index = rand() %(img_size);
        individual->image.data[index].r = rand() % upperBound; // <- Mutate this
        individual->image.data[index].g = rand() % upperBound; // <- Mutate this
        individual->image.data[index].g = rand() % upperBound; // <- Mutate this
        selects--;
    }
}
void mutate_population(Individual *individual, int population_size, double rate)
{
    // srand(time(NULL));
    while((individual+(population_size/4))!= NULL)
    {
        mutate(individual, rate);
        individual++;
    }
    // for(int i = population_size/4; i < population_size; i++)
    // {
    //     mutate(&(individual[i]), rate);
    // }
}