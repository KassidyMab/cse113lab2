/**
 * @file ch5_pp11.c
 * @brief Prints out a two digit number as a word
 * @details A program that prints out a given two digit number
 * into the word of it.
 * 
 * @author Kassidy Maberry
 * @date 2022/2/10
 * @bug None
 * @todo None
 */

#include <stdio.h>


int input(void);
int teens(int num);
int tens(int num);
int ones(int num);

int main(void)
{
        
        int num = input();
        printf("You entered the number ");


        if (num < 20){
                teens(num);
        } else{
                tens(num);
                ones(num);
        }
        printf(".\n");
        return 0;
}

/**
 * A function that gathers a user's input and checks if it is acceptable
 * @return The users input.
 */
int input(void)
{
        int num;
        printf("Enter a two digit number: ");
        scanf("%d", &num);

        if (num > 99){
                printf("Number is too big.\n");
                num = input();
        } else if (num < 10){
                printf("Number is too small\n");
                num = input();
        }
        return num;

}

/**
 * If the number is 10-19 it will print out said number. Otherwise it states
 * you arent supposed to see this message. Uses the place to print out
 * the first part
 * @param num the number the function uses to find its spelling.
 */
int teens(int num)
{
        switch (num)
        {
        case 10:
                printf("ten");
                break;
        case 11:
                printf("eleven");
                break;
        case 12:
                printf("twelve");
                break;
        case 13:
                printf("thirteen");
                break;
        case 14:
                printf("fourteen");
                break;
        case 15:
                printf("fifteen");
                break;
        case 16:
                printf("sixteen");
                break;
        case 17:
                printf("seventeen");
                break;
        case 18:
                printf("eighteen");
                break;
        case 19:
                printf("nineteen");
                break;
        default:
                printf("This shouldn't appear.");
                break;
        }
}


/**
 * figures out the tens place number if it is above 19. Prints out the
 * tens place spelling of the digit
 * @param num the total number the function is given.
 */
int tens(int num)
{
        int tens = num/10;
        switch (tens)
        {
        case 2:
                printf("twenty");
                break;
        case 3:
                printf("thirty");
                break;
        case 4:
                printf("forty");
                break;
        case 5:
                printf("fifty");
                break;
        case 6:
                printf("sixty");
                break;
        case 7:
                printf("seventy");
                break;
        case 8:
                printf("eighty");
                break;
        case 9:
                printf("ninety");
                break;
        default:
                break;
        }

        return 0;
}

/**
 * Figures out the ones place by modulating by 10 and using the reminader
 * to find which switch statement to activate. If there is a 0 it wont
 * print out anything however anything else prints out the letter
 * and a "-".
 * @param num The number the user gives to find the ones place of.
 */
int ones(int num)
{
        int one = num % 10;

        switch (one)
        {
        case 0:
                break;
        case 1:
                printf("-one");
                break;
        case 2:
                printf("-two");
                break;
        case 3:
                printf("-three");
                break;
        case 4:
                printf("-four");
                break;
        case 5:
                printf("-five");
                break;
        case 6:
                printf("-six");
                break;
        case 7:
                printf("-seven");
                break;
        case 8:
                printf("-eight");
                break;
        case 9:
                printf("-nine");
                break;
        
        default:
                break;
        }
        return 0;
}