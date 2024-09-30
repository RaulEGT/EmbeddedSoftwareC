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
 * @file stats.h
 * @brief Header file for stats.c

 *
 * @author Raul Gomez
 * @date 29/09/2024
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

void print_array(unsigned char *array, int count);
int find_mean(unsigned char *array, int count);
int find_maximum(unsigned char *array, int count);
int find_minimum(unsigned char *array, int count);
int find_median(unsigned char *array, int count);
void sort_array(unsigned char *array, int count);
void print_statistics(unsigned char *array, int count);

#endif /* __STATS_H__ */

/*
Final revision finished 
V3 Raul Gomez 29/09/2024
*/