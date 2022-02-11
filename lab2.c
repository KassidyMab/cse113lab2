/**
 * @file lab2.c
 *
 * @author Nicholas Crepeau
 *
 * @date 1/1/2019
 *
 * Assignment: Lab 2
 *
 * @brief A program that uses the function in functions.c
 *
 * @details
 *
 * @bugs none
 *
 * @todo none
 */

#include "functions.h"
#include <stdio.h>


int main(void) {
        int h = 2;
        int w = 3;
        int area;

        area = area_triangle(h, w);
        printf("A rectangle with height %d and width %d has an area of %d.\n", h, w, area);

        return 0;
}
