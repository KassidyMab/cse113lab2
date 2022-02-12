/**
 * @file lab2.c
 * @brief A calculator for various geometric shapes.
 * @details A program that calculates the perimeter or area for varoius
 * shapes. It can do it for triangles, regular polygons, circles, and
 * rectangles.
 * 
 * @author Kassidy Maberry
 * @date 2022/2/11
 * @bugs None
 * @todo comments
 */

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

char input(void);
int funcinp(void);
int regplop(void);
int circop(void);
int rectop(void);
int triop(void);

int main(void) 
{
        funcinp();

        return 0;
}


int funcinp(void)
{
        char op;
        printf("Select a geometry calculation \nC. Circles\nP. " 
        "Regular Polygon\nR. Rectangles\nT. Right Triangles\n"
        "Q. Exit \nEnter your choice: ");
        op = input();

        switch (op){
        case 'P':
                regplop();
                break;
        case 'C':
                circop();
                break;
        case 'R':
                rectop();
                break;
        case 'T':
                triop();
                break;
        case 'Q':
                exit(0);
                break;
        default:
                printf("Unaccepted input.");
                funcinp();
                break;
        }


        return 0;
}


char input(void)
{
        int op;
        char tmp;
	while ((tmp = getchar()) != '\n')
		if (tmp > 94){
                op = tmp - 32;
		} else {
		op = tmp;
		}
        return op;
}


int regplop(void)
{
        float ans;
        char op;
        printf("Select a regular polygon calculation \nI. Interior angles\nE."
        " Exterior angles\nA. Area\nB. Back \nEnter your choice: ");

        op = input();

        switch (op){
        case 'I':
                ans = interior_angle(prompt(6));
                printf("Each interior angle is %f degrees.\n", ans);
                break;
        case 'E':
                ans = exterior_angle(prompt(6));
                printf("Each exterior angle is %f degrees.\n", ans);
                break;
        case 'A':
                ans = area_regular_polygon(prompt(1), prompt(6));
                printf("The area of the polygon is %f.\n", ans);
                break;
        case 'Q':
                funcinp();
                break;
        default:
                printf("Unaccepted input.");
                regplop();
                break;
        }



        return 0;
}


int circop(void)
{
        float ans;
        char op;
        printf("Select a circle calculation \nC. Circumference" 
        "\nA. Area\nB. Back \nEnter your choice: ");

        op = input();

        switch (op){
        case 'C':
                ans = circumference(prompt(5));
                printf("The circumference of the circle is %f.\n", ans);
                break;
        case 'A':
                ans = area_circle(prompt(5));
                printf("The area of the circle is %f.\n", ans);
                break;
        case 'B':
                funcinp();
                break;
        
        default:
                printf("Unaccepted input.\n");
                circop();
                break;
        }

        return 0;
}


int rectop(void)
{
        int ans;
        float rans;
        char op;
        printf("Select a rectangle calculation \nP. Perimeter" 
        "\nA. Area\nR. Diagonal\nB. Back \nEnter your choice: ");

        op = input();

        switch (op){
        case 'P':
                ans = perimeter_rectangle(prompt(1), prompt(2));
                printf("The perimeter of the rectangle is %d.\n", ans);
                break;
        case 'A':
                ans = area_rectangle(prompt(1), prompt(2));
                printf("The area of the rectangle is %d.\n", ans);
                break;
        case 'R':
                rans = diagonal_rectangle(prompt(4), prompt(2));
                printf("The length of the rectangle is %lf.\n", rans);
                break; 
        case 'B':
                funcinp();
                break; 
        default:
                printf("Unnaccepted input.\n");
                rectop();
                break;
        }

        return 0;
}

int triop(void)
{
        float ans;
        char op;
        printf("Select a triangle calculation \nP. Perimeter" 
        "\nA. Area\nH. hypotenuse\nB. Back \nEnter your choice: ");

        op = input();

        switch (op){
                case 'A':
                        ans = area_triangle(prompt(3), prompt(4));
                        printf("The area of the triangle is %lf.\n", ans);
                        break;
                case 'P':
                        ans = perimeter_triangle(prompt(3), prompt(4));
                        printf("The area of the triangle is %lf.\n", ans);
                        break; 
                case 'H':
                        ans = hypotenuse(prompt(3), prompt(4));
                        printf("The hypotenuse is %lf.\n", ans);
                        break;
                case 'B':
                        funcinp();
                        break;
                default:
                        printf("Unaccepted input.\n");
                        break;
        }



        return 0;
}