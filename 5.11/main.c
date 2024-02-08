/* 5.11
 * This program will take a number input
 * by the user then display the value
 * rounded to the nearest integer, to
 * the nearest tenth, to the nearest hundredth,
 * and to the nearest thousandth then display
 * the original number and the results.
 */

#include <stdio.h>
#include <math.h>

//function prototypes
float roundToInteger(float);
float roundToTenths(float);
float roundToHundredths(float);
float roundToThousandths(float);

int main() { //main header

    float number; //local variable

    printf("Enter a number: "); //prompt user to enter a number
    scanf_s("%f", &number); //read number value from kb

    //output number and nearest integer, tenth, hundredth, and thousandth
    printf("\nNUMBER\t\tNEAREST INTEGER\t\tNEAREST 10TH\t\tNEAREST 100TH\t\tNEAREST 1000TH\n");
    printf("%f\t%7.0f\t\t\t%8.1f\t\t%8.2f\t\t%10.3f\n", number, roundToInteger(number), roundToTenths(number),
           roundToHundredths(number), roundToThousandths(number));

} //end main

//function roundToInteger -- returns number rounded to nearest integer
float roundToInteger(float number) {
    return floor(number * 1 + .5) / 1;
} //end roundToInteger

//function roundToTenths -- returns number rounded to nearest 10th
float roundToTenths(float number) {
    return floor(number * 10 + .5) / 10;
} //end roundToTenths

//function roundToHundredths -- returns number rounded to nearest 100th
float roundToHundredths(float number) {
    return floor(number * 100 + .5) / 100;
} //end roundToHundredths

//function roundToThousandths -- returns number rounded to nearest 1000th
float roundToThousandths(float number) {
    return floor(number * 1000 + .5) / 1000;
} //end roundToThousandths




