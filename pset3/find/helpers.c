/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if (n <= 0)
    {
        return false;
    }

    int middle = n / 2;   
    // eprintf("n: %i\n", n);
    // eprintf("middle of n: %i\n", n/2);
    
    if (value == values[middle])
    {
        return true; 
    }
    if (middle == 0)
    {
        return false;
    }
    
    
    else if (value > values[middle])
    {
        int new_size = n - middle - 1;
        int new_values[new_size];
        for (int i = 0; i <= new_size; i++)
        {
            new_values[i] = values[middle+i+1];
            //eprintf("new_value[%i]: %i\n", i, new_values[i]);
        }
        // eprintf("new_size: %i\n", new_size);
        return search(value, new_values, new_size);
    }
    
    else if (value < values[middle])
    {
        int new_size = n - middle;

        int new_values[new_size];
        for (int i = 0; i <= new_size; i++)
        {
            new_values[i] = values[i];
            //eprintf("new_value[%i]: %i\n", i, new_values[i]);
        }
        // eprintf("new_size: %i\n", new_size);
        return search(value, new_values, new_size);
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int swap_value;
    int swap_counter;

    do
    {
        swap_counter = 0;
        for (int i = 0; i < n-1; i++)
        {
            if (values[i] > values[i+1])
            {
                swap_value = values[i];
                values[i] = values[i+1];
                values[i+1] = swap_value;
                swap_counter ++;
            }
        }

    }
    while (swap_counter > 0);    
    
    return;
}
