/**
 * @file ch5_pp8.c
 * @brief Figures out the closest depature time
 * @details A program that figures out the closest depature time
 * and its arrival time.
 * 
 * @author Kassidy Maberry
 * @date 2022/2/10
 * @bug None
 * @todo doxygenize
 */

#include <stdio.h>

int abs(int val);
int timecomp(int hour, int minute);
int closetime(int utime);
int input(void);
int flights(int time);

int main(void)
{
        int time;
        time = closetime(input());
        flights(time);
        return 0;
}

/**
 * Gathers the users input as a 24 hour clock and checks it is an 
 * allowed input.
 * @return the users input in total seconds passed.
 */
int input(void)
{
        int hour, min, ans;
        printf("Enter a 24 hour time: ");
        scanf("%d:%d", &hour, &min);
        ans = timecomp(hour, min);
        if (ans > 1439){
                printf("Any input at or above 24h can not exist.");
                ans = input();
        } else if (ans < 0){
                printf("Can not give a negative hour.");
                ans = input();
        }

        return ans;
}

/**
 * Converts a given hour:minute format into the total amount of
 * minutes passed throughout the entire day.
 * @param hour hour of the day.
 * @param minute minute of the day.
 * @return The total amount of minutes passed in the day.
 */
int timecomp(int hour, int minute)
{
        return (hour * 60) + minute;
}


/**
 * Gets the absolute value of a given number.
 * @param val a number to return an absolute value of.
 * @return the absolute value.
 */
int abs(int val)
{
        if (val < 0){
                val = val * -1;
        }
        return val;
}

/**
 * A function given a total amount of minutes that then compares
 * to the planetimes and finds the closest one.
 * @param utime time in total minutes passed in the day.
 * @return a senario to be given for another function.
 */
int closetime(int utime)
{
        int planetimes[8] = {480, 583, 679, 767, 840, 945, 1140, 1305};
        int i, tmp, cur;
        tmp = 1440;
        for (i = 0; i < 8; i++){
                if ((abs(utime - planetimes[i]) < tmp)){
                        tmp = utime - planetimes[i];
                        cur = i;
                }
        }
        return cur;
}

/**
 * A function that takes in various different senarios
 * printing out the given senario
 * @param time The senario the function is given
 * @return 0
 */
int flights(int time)
{
        switch (time){
        case 0:
                printf("Closest departure 8:00 a.m., arriving at 10:16 a.m.");
                break;
        case 1:
                printf("Closest departure 9:43 a.m., arriving at 11:52 a.m.");
                break;
        case 2:
                printf("Closest departure 11:19 a.m., arriving at 1:31 p.m.");
                break;
        case 3:
                printf("Closest departure 12:47 p.m., arriving at 3:00 p.m.");
                break;
        case 4:
                printf("Closest departure 2:00 p.m., arriving at 4:08 p.m.");
                break;
        case 5:
                printf("Closest departure 3:45 p.m., arriving at 5:55 p.m.");
                break;
        case 6:
                printf("Closest departure 7:00 p.m., arriving at 9:20 p.m.");
                break;
        case 7:
                printf("Closest departure 9:45 p.m., arriving at 11:58 p.m.");
                break;
        default:
                printf("This shouldn't show");
                break;
        }
        printf("\n");
        return 0;
}
