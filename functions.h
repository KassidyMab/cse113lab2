/**
 * @file functions.h
 *
 * @author Kassidy Maberry
 *
 * @date 2/10/2022
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
float area_regular_polygon(float side, float angles);
int prompt(int request);

#endif
