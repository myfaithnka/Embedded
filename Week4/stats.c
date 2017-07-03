/*
 * stats.c
 *
 * Embedded programming course, week 1 exercise. Calculate statistics of an array
 * of small integers.
 *
 * Author: Anthony Turvey
 * Date:   Sunday Jun 18, 2017
 *
 */


#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)


unsigned char mean; 
unsigned char median;
int i;


int main() {

    unsigned char my_array[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                    114, 88,   45,  76, 123,  87,  25,  23,
                                    200, 122, 150, 90,   92,  87, 177, 244,
                                    201,   6,  12,  60,   8,   2,   5,  67,
                                      7,  87, 250, 230,  99,   3, 100,  90};

    #ifdef VERBOSE
    print_array(my_array, SIZE);
    printf("  main: find_mean (before sort) returned: %d\n", find_mean(my_array, SIZE));
    printf("  main: sorting array...\n");
    #endif

    sort_array(my_array, SIZE);

    #ifdef VERBOSE
    print_array(my_array, SIZE);
    printf("  main: find_mean (after sort) returned: %d\n", find_mean(my_array, SIZE));
    printf("  main: find_median returned: %d\n", find_median(my_array, SIZE));
    printf("  main: find_min return: %d\n", find_min(my_array, SIZE));
    printf("  main: find_max return: %d\n", find_max(my_array, SIZE));
    #endif

    return 0;
}


// Function: find_min
unsigned char find_min(unsigned char *array, int length) {

    unsigned char min, i;

    min = array[0];
    for ( i=0; i<length; ++i)
        if ( array[i] < min ) min=array[i];

    return min;
}


// Function: find_max
unsigned char find_max(unsigned char *array, int length) {

    unsigned char max, i;

    max = array[0];
    for ( i=0; i<length; ++i)
        if ( array[i] > max ) max=array[i];

    return max;
}

// Function: find_mean
unsigned char find_mean(unsigned char *array, int length) { 
  
    // forget overflow  checking for today
    int sum = 0;
    float mean;

    for ( i=0; i<length; ++i) 
        sum += array[i];

    printf("  find_mean: max index finished at %d\n", i);
    printf("  find_mean: sum was %d\n", sum);

    mean = (float)sum / (float)i;

    printf("  find_mean: calculated mean was %f\n", mean);

    return( (unsigned char)(mean+0.5) );

}


// Function: find_median
unsigned char find_median(unsigned char *array, int length) {

    unsigned char test, median;

    // check to see if length is odd or even
    test = (length>>1)<<1;
    if ( test == length )  //even, median is average of middle two elements
        median = ( array[(length>>1)] + array[(length>>1)-1] ) / 2;
    else
        if (length==1) return (array[length-1]);
        else
            median = ( array[length>>1] );
    
    return median;
}


// Function: print_array
void print_array(unsigned char *array, int length) {

    int i;

    printf("\n");

    // forget about bounds checking... it is Sunday after all
    for ( i=0; i<length; ++i ) {
        printf("  Index: %03d    %03d\n", i, array[i]);
    }

    printf("Array Length: %03d\n\n", i);

}


// Function: sort_array
void sort_array(unsigned char *array, int length) {

    int i, p, q, temp;

    p = length;
    do {
        q = 0;
        for (i=0; i < (p-1); ++i) {
            if ( array[i] > array[i+1] ) {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                q = i+1;
            }
        } 
        p = q;
    } while ( p > 1 ); 
}
