/* 3.44
 * This program will read three nonzero
 * integer values then determine whether
 * each value can represent a side of a
 * right triangle.
 */

#include <stdio.h>
#include <math.h>

int main() { //main header
    //initialize variables
    int a, b, c = 0;
    int count = 0;

    printf("%s", "Enter first nonzero integer: "); //prompt user for first integer
    scanf_s("%d", &a); //read a value from kb

    printf("%s", "Enter second nonzero integer: "); //prompt user for second integer
    scanf_s("%d", &b); //read b value from kb

    printf("%s", "Enter third nonzero integer: "); //prompt user for third integer
    scanf_s("%d", &c); //read c value from kb

    if (a == 0) { //if a equals 0
        printf("%s", "Number must be nonzero. Please re-enter first integer: "); //prompt user to re-enter a
        scanf_s("%d", &a); //read new a value from kb
    }//end if
        if (b == 0) { //if b equals 0
            printf("%s", "Number must be nonzero. Please re-enter second integer: "); //prompt user to re-enter b
            scanf_s("%d", &b); //read new b value from kb
        } //end if
            if (c == 0) { //if c equals 0
                printf("%s", "Number must be nonzero. Please re-enter third integer: "); //prompt user to re-enter c
                scanf_s("%d", &c); //read new c value from kb
            }

      double sum1 = pow(a,2) + pow(b,2);
      double sum2 = pow(b, 2) + pow(c, 2);
      double sum3 = pow(a,2) + pow(c,2);

      
    while (count >= 0){ //allows loop to iterate at least once
        if (sum1 == pow(c,2) || sum2 == pow(a,2) || sum3 == pow(b,2)) { //if sum of any two sides is greater than third side
            printf("%s", "\nThe integer values can represent sides of a right triangle.\n"); //integer values can be sides of triangle
        } //end if
        else { //else statement
            printf("%s", "\nThe integer values cannot represent sides of a right triangle.\n"); //integer values cannot be sides of triangle
        } //end else
        count--; //decrement count so loop iterates only once
    } //end while
} //end main

