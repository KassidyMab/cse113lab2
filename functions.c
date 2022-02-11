/**
 * @file lab1.c
 * @brief A simple geometry calculator
 * @details A calculator which will determine the area and perimeter of a
 * triangle, rectangle. The area of a regular polygon and circle. The 
 * Circumference of a circle and the hytopneuse of a triangle. Lastly the
 * exterior and interior angles of a given polygon based upon its total
 * amount of sides.
 * 
 * @author Kassidy Maberry
 * @date 1/31/22
 * @bug None currently known
 * @todo Finished
 */


#include <stdio.h>
#include <math.h>
#include "functions.h"


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




/**
 *Calculates the area of a rectangle.
 * @param wid the width of a rectangle.
 * @param len the length of a rectangle.
 * @return The area of a rectangle.
 */
int area_rectangle(int len, int wid)
{
        return len * wid;
}


/**
 *Calculates the perimeter of a rectangle.
 * @param wid the width of a rectangle.
 * @param len the length of a rectangle.
 * @return The perimeter of a rectangle.
 */
int perimeter_rectangle(int len, int wid)
{
        return 2 * len + 2 * wid;
}

/**
 * Figures out the hypotenuse of a given right angle.
 * @param opp The opposite angle of said triangle.
 * @param adj The adjacent side length of said triangle.
 * @return
 */
float hypotenuse (int opp, int adj)
{
        return sqrt(pow(opp, 2) + pow(adj, 2));
}

/**
 * Calculates the perimeter of a given triangle with a given height and base.
 * @param base The base of a given triangle.
 * @param hei The height of a given triangle.
 * @return The perimeter of a given triangle
 */
float perimeter_triangle(int hei, int base)
{
        return hypotenuse(hei,base) + hei + base;
}

/**
 * Calculates the area of a given triangle.
 * @param base The base of a triangle.
 * @param hei The height of a triangle.
 * @return The area of a given triangle.
 */
float area_triangle(int hei, int base)
{
        return (hei*base)*.5;
}

/**
 * Calculates the area of a given circle.
 * @param radi the radius of the circle.
 * @return The area of the given circle.
 */
float area_circle(int radi)
{
        return M_PI * pow(radi, 2);
}

/**
 *Calculates the circumference of a requested circle.
 * @param radi the radius of the circle.
 * @return the circumference of the requested circle.
 */
float circumference(int radi)
{
        return 2 * M_PI * radi;
}

/**
 * calculates the length of a diagonal rectangle.
 * @param len the height of the diagonal rectangle.
 * @param wid the width of the diagonal rectangle.
 * @return The length of the diagonal rectangle.
 */
float diagonal_rectangle(int len , int wid)
{
        return hypotenuse(len, wid);
}

/**
 * Calculate total amount of degrees along all of the exterior angles.
 * @param angles The amount of sides/angles the shape has.
 * @return the total amount of degrees along all exterior angles.
 */
float exterior_angle(int angles)
{
        return 360/angles;
}

/**
 * Tells the user the total amount of degrees for all of the angles.
 * @param angles The amount of angles/sides the shape has.
 * @return The total amount of degrees in the shape.
 */
float interior_angle(int angles)
{
        float ans = 180 * (angles-2);
        printf("The sum of %d angles is: %f\n", angles, ans);
        return ans/angles;
}

/**
 * Finds the length of a regular polygon.
 * @param side the length of each side for the polygon.
 * @param angles The amount of angles/sides on the polygon.
 * @return The length of the regular polygon.
 */
float area_regular_polygon(int side, int angles)
{
        return (pow(side, 2) * angles / (4 * tan(M_PI / angles)));
}


/**
 * Asks the user for a specifified type of input based upon the request.
 * @param request The case for the request.
 * @return the requested value that user provides.
 */
int prompt(int request)
{
        int val;
        switch (request) {
                case (1):
                        printf("Please enter the length: ");
                        break;

                case(2):
                        printf("Please enter the width: ");
                        break;

                case(3):
                        printf("Please enter the  base: ");
                        break;
                case(4):
                        printf("Please enter the height: ");
                        break;
                case(5):
                        printf("Please enter the radius: ");
                        break;
                case(6):
                        printf("Please enter the amount of angles: ");
                        break;
                default:
                        printf("This shouldn't appear");
                        break;
                }
        scanf("%d", &val);
        if (val < 0){
                printf("Error| negatives do not mathematically work in "
                "shapes.\n");
        }
        return val;
}