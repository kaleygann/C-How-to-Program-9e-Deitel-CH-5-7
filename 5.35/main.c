/* 5.35
 * This program will use a function
 * to calculate the nth Fibonacci
 * number then determine the largest
 * Fibonacci number that can be printed
 * on this system.
 */

#include <stdio.h>

unsigned long long int fibonacci(int);  //function prototype

int main() {  //main header

    //local variables
    int largest = 0;
    int count = 2;
    int fibNum = fibonacci(2);

    while (fibNum > largest) {  //while each term gets larger
        largest = fibNum;  //set current term to largest
        count++;  //increment count
        fibNum = fibonacci(count);  //calculate next term
    }  //end while

    //display largest value
    printf("The largest Fibonacci number that can be printed is %d", largest);

}  //end main


/* function fibonacci(int n)
 * calculates nth fibonacci term
 * by adding the two previous terms
 * then returning the result
 */
unsigned long long int fibonacci (int n) {
    //local variables
    int num1 = 0;
    int num2 = 1;
    int counter = 1;
    int sum = 0;

    while (counter <= n) {  //while loop to accumulate terms
        sum = num1 + num2;  //sum the two numbers
        num1 = num2;  //reset num1 value
        num2 = sum;  //set num2 value to current sum
        counter++;  //increment counter
    }
    return sum;  //return each fibonacci term

}  //end function
