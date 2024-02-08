/* 5.21
 * This program will use functions to
 * print a variety of shapes composed
 * of asterisks and pound signs.
 */

#include <stdio.h>
#include <math.h>

//function prototypes
void printCircle(void);
void printTriangle(void);
void printStar(void);
void printHeart(void);

int main() {  //main header

    //function calls
    printCircle();
    printTriangle();
    printStar();
    printHeart();
}

void printCircle(void) {

    int radius;  //declare local variable radius

    printf("Enter circle radius: ");  //prompt user to enter circle's radius
    scanf_s("%d", &radius);  //read radius value from kb

    int diameter = 2 * radius;

    for (int i = 0; i <= diameter; ++i) {  //iterate rows

        for (int j = 0; j <= diameter; ++j) {  //iterate columns

            int x = radius - i;  //subtract row value from radius, set value to x
            int y = radius - j;  //subtract column value from radius, set value to y

            int point = pow(x, 2) + pow(y, 2);  //set point to x^2 + y^2

            if (point <= pow(radius, 2) + 1)  //test circle equation -- print asterisk if case is true

                printf("* ");

            else
                printf(" ");  //print space
        }  //end inner for

        printf("\n");  //newline
    }  //end outer for
}  //end function


void printTriangle(void) {

    int rows;  //declare local variable rows

    printf("\nEnter triangle rows: ");  //prompt user to enter number of triangle rows
    scanf_s("%d", &rows);  //read rows value from kb

    for (int i = 1; i <= rows; ++i) {  //for loop to iterate rows

        for (int j = 1; j <= rows - i; ++j) {  //for loop to iterate columns and print spaces

            printf(" ");  //print space

        }  //end first inner for

            for (int k = 1; k <= ((i * 2)- 1); ++k) {  //for loop to print characters

                printf("#");

            }  //end second inner for

        printf("\n");  //newline

    }  //end outer for
}  //end function

void printStar(void)
{
    int height;  //declare local variable height

    //prompt user to input height of star
    printf("\nEnter star height: ");
    scanf_s("%d", &height);  //read star value from kb

    //initialize local variables
    int pointOne = height + (height / 2);
    int pointTwo = pointOne;
    int pointThree = height + height + (height / 2) + 2;
    int pointFour = (height / 2 - 2);

    //loop to iterate rows
    for (int i = 0; i < height; ++i)
    {
        //if statement to increment and decrement third and fourth points
        if (i >= (height + 1) / 3)
        {
            pointThree -= 3;
            pointFour += 3;
        }
        //loop to iterate columns
        for (int j = 0; j < (height * 3); j++)
        {

            //if statement print first point with specified height when j is value of first two points
            if (j == pointOne || j == pointTwo)
            {
                printf("*");

            }  //end if

            //else if to print and connect remaining points
            else if ((i == ((height) / 3) && (j + 1 != pointOne) && (j - 1 != pointOne)
            && (j + 1 != pointTwo) && (j - 1 != pointTwo) && (j % 2 == 0) && (j > pointFour && j < pointThree))
            || (i >= ((height) / 3)) && ((j == pointThree || j == pointFour))) {

                printf("*");

            }  //end else if

            else  //print spaces between asterisks
            {
                printf(" ");

            }  //end else
        }  //end inner for

        printf("\n");  //newline

        pointOne--;  //decrement first point value
        pointTwo++;  //increment second point value

    }  //end outer for
}  //end function

void printHeart(void) {

    int size;  //declare local variable size

    printf("\nEnter heart size: ");  //prompt user to enter size of heart
    scanf_s("%d", &size);  //read size value from kb

    //iterate top part (split into two parts) of heart
    for (int i = 1; i <= size; ++i) {  //iterate rows
        for (int j = 1; j <= 4 * size; ++j) {  //iterate columns

            //initialize top two parts of heart
            double topLeft = sqrt(pow(i-size, 2) + pow(j - size, 2));
            double topRight = sqrt(pow(i - size, 2) + pow(j - 3 * size, 2));

            if (topLeft < size + 0.5 || topRight < size + 0.5) {  //test condition to print asterisks
                printf("*");
            }  //end if

            else {//else, print space
                printf(" ");
            }  //end else

        }  //end inner for

        printf("\n");  //newline
    }  //end outer for

    //iterate bottom part of heart (upside down triangle)
    for (int i = 1; i <= 2 * size; ++i)  //iterate rows
    {
        for (int j = 0; j < i; ++j) {  //iterate to print spaces

            printf(" ");

        }  //end first inner four
        for (int j = 0; j < 4 * size + 1 - 2 * i; ++j) {  //iterate loop to print asterisks

            printf("*");

        }  //end second inner for
        printf("\n");  //newline
    }  //end outer for

}  //end function
