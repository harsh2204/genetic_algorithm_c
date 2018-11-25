#include <stdio.h>
#include <stdlib.h>
#include "a4.h"

PPM_IMAGE *read_ppm(const char *file_name)
{

    FILE *input;

    input = fopen(file_name, "r");

    if(!input){
        fprintf(stderr, "Unable to open file '%s'\n", file_name);
    exit(1);
    }
    int width, height, max;
    fscanf(input, "P3 %d %d %d\n", &width, &height, &max);

    PIXEL *data= malloc((width * height) * sizeof(PIXEL));

    for(int i = 0; i < width * height; i++){
        fscanf(input, "%hhu%hhu%hhu", &(data[i].r) , &(data[i].g), &(data[i].b));
    }
    PPM_IMAGE* image = malloc(sizeof(PPM_IMAGE));
    image->data = data;
    image->height = height;
    image->width = width;
    image->max_color = max;
    fclose(input);

    return image;
}
void write_ppm(const char *file_name, const PPM_IMAGE *image)
{
    FILE *output;

    output = fopen(file_name, "w");

    if (!output) {
        fprintf(stderr, "Unable to open file '%s'\n", file_name);
        exit(1);
    }

    fprintf(output, "P3\n");

    fprintf(output, "%d %d\n", image->width, image->height);

    fprintf(output, "%d\n", image->max_color);

    for(int i = 0; i < image->width * image->height; i++){
        fprintf(output, "%d %d %d ", image->data[i].r, image->data[i].g, image->data[i].b);
    }

    fclose(output);
}

// int main(int argc, char const *argv[])
// {
//     PPM_IMAGE *image = read_ppm("me.ppm");
//     write_ppm("output.ppm", image);
//     // for(int i = 0; i < (image->height*image->width); i++)
//     // {
//     //     printf("%d %d %d ", image->data[i].r, image->data[i].g, image->data[i].b);
//     //     /* code */
//     // }
    
//     return 0;
// }
