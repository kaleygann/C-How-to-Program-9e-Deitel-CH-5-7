/* 5.38
 * This program will modify the factorial function
 * from Fig. 5.9 to print its local variable and
 * recursive call parameter.
 */

// fig05_09.c
// Recursive factorial function.
#include <stdio.h>

unsigned long long int factorial(int number);  //function prototype

int main(void) {
     //for loop to calculate factorial(i) then display results
     for (int i = 0; i <= 21; ++i) {
         printf("%d! = %llu\n", i, factorial(i));
     }  //end for
}  //end main

 // recursive definition of function factorial
 unsigned long long int factorial(int number) {
     if (number <= 1) {  //base case
         return 1;
     }  //end if
     else {  //recursive portion
         printf("Factorial(%d)\n\t", number);
         return (number * factorial(number - 1));
     }  //end else
 }  //end function