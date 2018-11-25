#include "a4.h"
#include <time.h>
#include <stdlib.h>


PIXEL *generate_random_image(int width, int height, int max_color)
{
    // srand(time(NULL));
    // srand((unsigned int)time(NULL));
    int len = width*height;
    PIXEL *random = malloc(len * sizeof(PIXEL));
    for(int i = 0; i < len; i++)
    {
        random[i].r =  rand()%(max_color+1);
        random[i].g =  rand()%(max_color+1);
        random[i].b =  rand()%(max_color+1);
    }
    return random;
}
Individual *generate_population(int population_size, int width, int height, int max_color)
{
    // srand(time(NULL));
    Individual *list = malloc(population_size * sizeof(Individual));
    for(int i = 0; i < population_size; i++)
    {
        PPM_IMAGE *image = malloc(sizeof(PPM_IMAGE));
        image->height = height;
        image->width = width;
        image->max_color = max_color;
        image->data = generate_random_image(width, height, max_color);
        list[i].image = *(image);
    }
    return list;
}