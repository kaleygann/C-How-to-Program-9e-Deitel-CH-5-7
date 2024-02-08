/* 5.3
 * This program will use the table of
 * library functions from 5.3 and test
 * to see if the examples give the indicated
 * results.
 */

#include <stdio.h>
#include <math.h>

int main() { //main header

    //square root function
    printf("The square root of 900.0 is: %.1f\n", sqrt(900.0));
    printf("The square root of 9.0 is: %.1f\n\n", sqrt(9.0));

    //cube root function
    printf("The cube root of 27.0 is: %.1f\n", cbrt(27.0));
    printf("The cube root of -8.0 is: %.1f\n\n", cbrt(-8.0));

    //exponential function e^x
    printf("The value of the exponential function e^1.0 is: %f\n", exp(1.0));
    printf("The value of the exponential function e^2.0 is %f\n\n", exp(2.0));

    //natural logarithm with base e
    printf("The value of the natural logarithm of 2.718282 (base e) is: %.1f\n", log(2.718282));
    printf("The value of the natural logarithm of 7.389056 (base e) is: %.1f\n\n", log(7.389056));

    //logarithm with base 10
    printf("The logarithm of 1.0 with base 10 is: %.1f\n", log10(1.0));
    printf("The logarithm of 10.0 with base 10 is: %.1f\n", log10(10.0));
    printf("The logarithm of 100.0 with base 10 is %.1f\n\n", log10(100.0));

    //absolute value as floating-point
    printf("The absolute value of 13.5 as floating-point number is: %.1f\n", fabs(13.5));
    printf("The absolute value of 0.0 as a floating-point number is: %.1f\n", fabs(0.0));
    printf("The absolute value of -13.5 as a floating-point number is: %.1f\n\n", fabs(-13.5));

    //rounding to smallest integer no less than x (rounding up)
    printf("The value 9.2 rounded to the smallest integer no less than 9.2 is: %.1f\n", ceil(9.2));
    printf("The value -9.8 rounded to the smallest integer no less than -9.8 is: %.1f\n\n", ceil(-9.8));

    //rounding to largest integer no less than x (rounding down)
    printf("The value 9.2 rounded to the largest integer no greater than 9.2 is: %.1f\n", floor(9.2));
    printf("The value -9.8 rounded to the largest integer no greater than -9.8 is: %.1f\n\n", floor(-9.8));

    //power function
    printf("The value of 2 raised to the power of 7 is: %.1f\n", pow(2,7));
    printf("The value of 9 raised to the power of 0.5 is: %.1f\n\n", pow(9, .5));

    //remainder function for x/y
    printf("The remainder of 13.657/2.333 as a floating-point number is: %.3f\n\n", fmod(13.657, 2.333));

    //sine, cosine, and tangent functions
    printf("The sine of 0.0 in radians is: %.1f\n", sin(0.0));
    printf("The cosine of 0.0 in radians is: %.1f\n", cos(0.0));
    printf("The tangent of 0.0 in radians is: %.1f\n", tan(0.0));


} //end main
