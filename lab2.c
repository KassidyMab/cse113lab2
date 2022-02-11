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

char input(void);

int main(void) 
{
        int area = area_regular_polygon(prompt(1), prompt(1));
        int h = 2;
        int w = 3;

        printf("A rectangle with height %d and width %d has an area of %d.\n", h, w, area);

        return 0;
}


int funcinp(void)
{
        char op;
        printf("Select a geometry calculation \nC. Circles\nP. " 
        "Regular Polygon\nR. Rectangles\n T. Right Triangles\n"
        "Q. Exit \nEnter your choice: ");
        op = input();

        switch (op)
        {
        case 'P':
                regpolop();
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
        int tmp, op;
        while(tmp = getchar() != "\n"){
                op = tmp;
                if (op > 94){
                        op = op - 32;
                }
        }
        return op;
}


int regpolop(void)
{
        float ans;
        char op;
        printf("Select a Regular polygon calculation \nI. Interior angles\nE."
        " Exterior angles\nA. Area\nB. Back \nEnter your choice: ");

        op = input();

        switch (op)
        {
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
                printf("The area of the function is %f.\n", ans);
                break;
        case 'Q':
                funcinp();
                break;
        default:
                printf("Unaccepted input.");
                regpolop();
                break;
        }



        return 0;
}


int circop(void)
{
        float ans;
        char op;
        printf("Select a geometry calculation \nC. Circumference" 
        "\nA. Area\nB. Back \nEnter your choice: ");

        op = input();

        switch (op)
        {
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
                printf("Unaccepted input.");
                circop();
                break;
        }

        return 0;
}


int rectop(void)
{
        int ans;
        char op;
        printf("Select a geometry calculation \nP. Perimeter" 
        "\nA. Area\nB. Back \nEnter your choice: ");

        op = input();

        switch (op)
        {
        case 'P':
                ans = perimeter_rectangle(prompt(1), prompt(2));
                printf("The perimeter is %d", ans);
                break;
        case 'A':
                ans = area_rectangle(prompt(1), prompt(2));
                printf("The area is %d", ans);
                break;
        case 'B':
                funcinp();
                break; 
        default:
                printf("Unnaccepted input");
                rectop();
                break;
        }

        return 0;
}

int triop(void)
{
        float ans;
        char op;
        printf("Select a geometry calculation \nP. Perimeter" 
        "\nA. Area\nH. hypotenuse\nB. Back \nEnter your choice: ");

        op = input();

        switch (op){
                case 'A':
                        ans = area_triangle(prompt(3), prompt(4));
                        printf("The area of the triangle is %d", ans);
                        break;
                case 'P':
                        ans = perimeter_triangle(prompt(3), prompt(4));
                        printf("The area of the triangle is %d", ans);
                        break; 
                case 'H':
                        ans = hypotenuse(prompt(3), prompt(4));
                        printf("The hypotenuse is %d", ans);
                        break;
                case 'B':
                        funcinp();
                        break;
                default:
                        printf("Unaccepted input.");
                        break;
        }



        return 0;
}