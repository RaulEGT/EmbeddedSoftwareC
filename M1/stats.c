/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief C promgram to  calculate max, mean, median, min and sort an array
 *
 *
 * @author Raul Gomez
 * @date 29/09/2024
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char sortedArray = {};
  /* Statistics and Printing Functions Go Here */

  print_array(test, SIZE);
  print_statistics(test, SIZE);
  find_mean(test, SIZE);
  find_maximum(test, SIZE);
  find_minimum(test, SIZE);
  sort_array(test, SIZE);
  find_median(test, SIZE);
}

/* This function prints the given array*/
void print_array(unsigned char *array, int count)
{
  printf("The array is: ");
  for(int i=0; i<count; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

/* This function calculates the mean value (average) and returns it. Given the array and its size */
int find_mean(unsigned char *array, int count)
{
  long int sum = 0;
  for(int i=0; i<count; i++)
  {
    sum += array[i];
  }
  int mean = sum/count;

  return mean;
}

/* This function calculates the maximum value and returns it. Given the array and its size */
int find_maximum(unsigned char *array, int count)
{
  int max = 0;
  for(int i=0; i<count; i++)
  {
    if (array[i] > max)
    {
      max = array[i];
    }
  }
  return max;
}

/* This function calculates the minimum value and returns it. Given the array and its size */
int find_minimum(unsigned char *array, int count)
{
  int min = 255;
  for(int i=0; i<count; i++)
  {
    if (array[i] < min)
    {
      min = array[i];
    }
  }

  return min;
}

/* This function sorts the given array and prints it */
void  sort_array(unsigned char *array, int count)
{
  int max_idx = 0;
  unsigned char tempArr[count] = {};
  unsigned char newArr[count] = {};

  /* This was done in order to not delete the main array values*/
  for(int i = 0; i < count; i++)
  {
    tempArr[i] = array[i];
  }

  for(int i = 0; i < count; i++)
  {
  int max = 0;
    
    for(int j = 0; j < count; j++)
    {
      if(tempArr[j] > max)
      {
        max = tempArr[j];
        max_idx = j;
      }
    }
    newArr[i] = tempArr[max_idx];
    tempArr[max_idx] = 0; 
  }
  printf("The sorted array is: ");
  for(int i=0; i < count; i++)
  {
    printf("%d ", newArr[i]);
  }
  printf("\n");
}

/* This function calculates the median value and returns it. Given the array and its size */
int find_median(unsigned char *array, int count)
{
  int max_idx = 0;
  unsigned char tempArr[count] = {};
  unsigned char newArr[count] = {};

  /* This was done in order to not delete the main array values*/
  for(int i = 0; i < count; i++)
  {
    tempArr[i] = array[i];
  }

  for(int i = 0; i < count; i++)
  {
  int max = 0;
    
    for(int j = 0; j < count; j++)
    {
      if(tempArr[j] > max)
      {
        max = tempArr[j];
        max_idx = j;
      }
    }
    newArr[i] = tempArr[max_idx];
    tempArr[max_idx] = 0; 
  }

  int median = (newArr[count/2] + newArr[count/2 - 1])/2;

  return median;
}

/* This function calls the other functions to get the basic statistics of the array and print them. Given the array and its size */
void print_statistics(unsigned char *array, int count)
{
  int min = find_minimum(array, count);
  int mean = find_mean(array, count);
  int median = find_median(array, count);
  int max = find_maximum(array, count);

  printf("The minimun is: %d\nThe mean is: %d\nThe median is: %d\nThe maximum is: %d\n", min, mean, median, max);
}

/*
Final revision finished 
V3 Raul Gomez 29/09/2024
*/
