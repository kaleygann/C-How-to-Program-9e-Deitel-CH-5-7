/* 3.38
 * This program will ask the user to
 * input a 5 digit integer then determine
 * and print how many digits in the
 * integer are 7s.
 */

#include <stdio.h>

int main() { //main header
    //initialize variables
    int num = 0;
    int sum = 0;
    int count = 1;

    printf("%s", "Please enter a five digit integer: "); //prompt user for 5 digit integer
    scanf_s("%d", &num); //scan num value from kb

    while (count <= 5){ //while loop to iterate five times

        int temp = num % 10; //store remainder of num divided by 10 in temp value
        num = num / 10; //set num to num divided by 10
            if (temp == 7){ //if temp is equal to 7
                sum++; //increment sum
            } //end if
            count++; //increment count
    } //end while
    if (sum > 0) { //if sum is greater than 0
        printf("Number of 7s in the integer: %d", sum); //display amount of 7s
    } //end if

    else //else is no 7s were counted
        printf("%s", "There are no 7s in the integer."); //output

} //end main
