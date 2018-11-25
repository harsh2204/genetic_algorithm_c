#include "a4.h"
#include <stdlib.h>
#include <stdio.h>

static int population_comp(const void *a,const void *b)
{
    Individual *ia = (Individual*)a;
    Individual *ib = (Individual*)b;
    return (int)(ia->fitness - ib->fitness);
}

PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate)
{
    Individual *population;
    population = generate_population(population_size, image->width, image->height, image->max_color);
    comp_fitness_population(image->data, population, population_size);
    qsort(population, population_size, sizeof(Individual), population_comp);
    for(int i = 0; i < num_generations; i++)
    {
        crossover(population, population_size);
        mutate_population(population, population_size, rate);
        comp_fitness_population(image->data, population, population_size);
        qsort(population, population_size, sizeof(Individual), population_comp);
        printf("Best Fitness:\t%f\t|Worst Fitness:\t%f\n", population[0].fitness,population[population_size-1].fitness);
    }
    return &(population[0].image);
}
void free_image(PPM_IMAGE *p)
{
    free(p->data);
    free(p);
}