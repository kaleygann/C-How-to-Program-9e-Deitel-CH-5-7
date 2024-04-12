/* 3.45 pt. 3
 * This program will computer the value of
 * e^x.
 */

#include<stdio.h>
int main(void) { //main header

    //initialize variables
    float num = 10;
    float fact = 0;
    float constant = 0;
    float count = 10;
    float var = 0;
    float e = 0;

    while(count > 1) //while count is greater than one
    {
        var = num; //set variable to 10
        fact = 1; //set factorial to 1;

        while(num > 1) //while num is greater than 1
        {
            fact = fact * num; //set the factorial to 1 * num
            num--; //decrement num all the way to 1
        } //end inner loop

        constant += (1 / fact); //accumulate constant, adding 1 divided by factorial each iteration
        var -= 1; //subtract 1 from variable each iteration
        num = var; //set num to current variable value
        count--; //decrement count
    } //end outer loop

    e = constant + 1 + (var / 1.f); //set e to constant plus one plus variable/1! from original
    printf("Estimated value of e^x: %f\n", e); //print value of e
} //end main
