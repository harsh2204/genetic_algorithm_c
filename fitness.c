#include "a4.h"
#include <stdio.h>
#include <math.h>

float sqrt_fast(float x)
 {
    //reference https://bits.stephan-brumme.com/squareRoot.html
    unsigned int i = *(unsigned int*) &x; 
    // adjust bias
    i  += 127 << 23;
    // approximation of square root
    i >>= 1; 
    return *(float*) &i;
 }

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size)
{
    double fitness = 0.0;
    while(--image_size)
    {
        double r = (A[image_size].r-B[image_size].r);
        double g = (A[image_size].g-B[image_size].g);
        double b = (A[image_size].b-B[image_size].b);
        fitness += ((r*r)+(g*g)+(b*b));
    }
    // return fitness;
    // return sqrt_fast(fitness);
    return sqrt(fitness);
}

void comp_fitness_population(const PIXEL *image , Individual *individual ,int population_size)
{
    int image_size = individual->image.height * individual->image.width;
    for(int i = 0; i < population_size; i++)
    {
        individual[i].fitness = comp_distance(image, individual[i].image.data, image_size);
        // printf("Calculated fitness:%f\n", individual[i].fitness);
    }
}