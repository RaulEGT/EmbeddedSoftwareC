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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
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
  find_mean(test, SIZE);
  find_maximum(test, SIZE);
  find_minimum(test, SIZE);
  sort_array(test, SIZE);
  find_median(test, SIZE);
}

void print_array(unsigned char *array, int count)
{
  printf("The array is: ");
  for(int i=0; i<count; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void find_mean(unsigned char *array, int count)
{
  long int sum = 0;
  for(int i=0; i<count; i++)
  {
    sum += array[i];
  }
  printf("The mean value is: %ld", sum/count);
  printf("\n");

}

void find_maximum(unsigned char *array, int count)
{
  int max = 0;
  for(int i=0; i<count; i++)
  {
    if (array[i] > max)
    {
      max = array[i];
    }
  }
  printf("The max value is: %d", max);
  printf("\n");
}

void find_minimum(unsigned char *array, int count)
{
  int min = 255;
  for(int i=0; i<count; i++)
  {
    if (array[i] < min)
    {
      min = array[i];
    }
  }
  printf("The min value is: %d", min);
  printf("\n");
}

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

void find_median(unsigned char *array, int count)
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
  printf("The median value is: %d", median);
  printf("\n");
}

/* Add other Implementation File Code Here */
