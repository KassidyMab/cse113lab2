/**
 * @file functions.h
 *
 * @author Nicholas Crepeau
 *
 * @date 1/1/2019
 *
 * Assignment: Lab 2
 *
 * @brief header file for functions.c
 *
 * @details see functions.c for details
 *
 * @bugs none
 *
 * @todo none
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* You may need #include <> statements here */

/* Function prototyes go here */
int area_rectangle(int len, int wid);
int perimeter_rectangle(int len, int wid);
float perimeter_triangle(int len, int wid);
float hypotenuse(int opp, int adj);
float area_triangle(int hei, int base);
float area_circle(int radi);
float circumference(int radi);
float diagonal_rectangle(int len, int wid);
float exterior_angle(int angles);
float interior_angle(int angles);
float area_regular_polygon(int side, int angles);
int prompt(int request);

#endif
