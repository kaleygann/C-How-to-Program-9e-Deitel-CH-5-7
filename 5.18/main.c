/* 5.18
 * This program will use a function to
 * determine whether a series of integers
 * is even or odd.
 */

int isEven(int);  //function prototype

#include <stdio.h>

int main() {  //main header

    int num = 0;  //initialize local variable

    while (num >= 0) {  //while loop

        printf("Enter a number (-1 to quit): ");  //prompt user to enter a number
        scanf_s("%d", &num);  //read num value from kb

        if (num == EOF) {  //if number is -1
            break;  //terminate loop
        }  //end if

        if (isEven(num)) {  //if isEven() returns true
            printf("%d is even\n", num);  //display even number
        }  //end if

        else {  //if isEven() returns false
            printf("%d is odd\n", num);  //display odd number
        }  //end else

    }  //end while

}  //end main

/* function isEven()
 * determines whether
 * the number is even.
 * returns true if even,
 * returns false if odd. */

int isEven(int num) {  //function header

   if (num % 2 == 0) {  //if number is even
       return 1;  //return true
   }  //end if

   else  //else if number is odd
       return 0;  //return false
}  //end function
