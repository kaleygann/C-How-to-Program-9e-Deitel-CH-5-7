/* 5.45
 * This program will test the
 * math library functions shown in
 * section 5.3's table. A table displaying
 * the values returned from each function
 * will be printed.
 */

#include <stdio.h>
#include <math.h>

//function prototypes
float getSqrt(float );
float getCbrt(float );
float getExponential(float );
float getNatLog(float);
float getLogBaseTen(float);
float getAbsValue(float);
float getRoundUp(float);
float getRoundDown(float);
float getPower(float, float);
float getRemainder(float, float);
float getSine(float);
float getCosine(float);
float getTangent(float);

int main() {  //main header

    //local variables
    float number = 0;
    float exponent = 0;
    float divisor = 0;

    printf("Please enter a number (-1 to quit): ");  //prompt user to enter number
    scanf_s("%f", &number);  //read number value from kb


        while (number != EOF) {  //while number is not -1

            printf("\nEnter the exponent: ");  //prompt user to enter exponent value
            scanf_s("%f", &exponent);  //read exponent value from kb

            printf("\nEnter the divisor: ");  //prompt user to enter divisor value
            scanf_s("%f", &divisor);  //read divisor value from kb

            //display results
            printf("\nORIGINAL NUMBER: %f", number);
            printf("\nSquare root: %.3f", getSqrt(number));
            printf("\nCube root: %.3f", getCbrt(number));
            printf("\nExponential function: %.3f", getExponential(number));
            printf("\nNatural logarithm: %.3f", getNatLog(number));
            printf("\nLogarithm with base 10: %.3f", getLogBaseTen(number));
            printf("\nAbsolute value: %.3f", getAbsValue(number));
            printf("\nRounded up: %.1f", getRoundUp(number));
            printf("\nRounded down: %.1f", getRoundDown(number));
            printf("\nRaised to power %.2f: %.3f", exponent, getPower(number, exponent));
            printf("\nRemainder divided by %.2f: %.3f", divisor, getRemainder(number, divisor));
            printf("\nSine: %.3f", getSine(number));
            printf("\nCosine: %.3f", getCosine(number));
            printf("\nTangent: %.3f", getTangent(number));

            printf("\n\nPlease enter a number (-1 to quit): ");  //prompt user to enter a new number
            scanf_s("%f", &number);  //read new number value from kb

        }  //end while
}  //end main

//get square root of number
float getSqrt(float number) {
    return sqrt(number);
}  //end function

//get cube root of number
float getCbrt(float number) {
    return cbrt(number);
}  //end function

//get exponential function e^x of number
float getExponential(float number) {
    return exp(number);
}  //end function

//get natural logarithm of number
float getNatLog(float number) {
    return log(number);
}  //end function

//get logarithm of number w/ base 10
float getLogBaseTen(float number) {
    return log10(number);
}  //end function

//get absolute value of number
float getAbsValue(float number) {
    return fabs(number);
}  //end function

//get number rounded up
float getRoundUp(float number) {
    return ceil(number);
}  //end function

//get number rounded down
float getRoundDown(float number) {
    return floor(number);
}  //end function

//get number raised to chosen exponent value
float getPower(float number, float exponent) {
    return pow(number, exponent);
}  //end function

//get remainder of number divided by chosen divisor
float getRemainder(float number, float divisor) {
    return fmod(number, divisor);
}  //end function

//get sine of number
float getSine(float number) {
    return sin(number);
}  //end function

//get cosine of number
float getCosine(float number) {
    return cos(number);
}  //end function

//get tangent of number
float getTangent(float number) {
    return tan(number);
}  //end function






