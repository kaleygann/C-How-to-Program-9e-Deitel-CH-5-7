/* 7.26
 * This program will create a menu-driven program that allows the user
 * to choose whether to add, subtract, multiply, or divide two numbers
 * then display the result */

#include <stdio.h>

// function prototypes
void add(double value1, double value2);
void subtract(double value1, double value2);
void multiply(double value1, double value2);
void divide(double value1, double value2);

int main(void) {

    // initialize array of 3 pointers to functions that each take
    // two double arguments and return void
    void (*arr[4])(double, double) = {add, subtract, multiply, divide};

    // menu header
    printf("--------------MENU--------------\n");
    printf("0 Addition\n1 Subtraction\n"
           "2 Multiplication\n3 Division\n4 Quit\nEnter option: ");

    // variables to store choice and radius values
    int choice = 0;
    double num1 = 0.0;
    double num2 = 0.0;

    scanf_s("%d", &choice);  // get first choice from user

    // process user's choice
    while (choice >= 0 && choice < 4) {

        // prompt user to enter radius
        printf("\nEnter the first number: ");
        scanf_s("%lf", &num1);

        printf("Enter the second number: ");
        scanf_s("%lf", &num2);

        // invoke function at location choice in array f and pass
        // choice as an argument
        (*arr[choice])(num1, num2);

        // prompt user to enter another option
        printf("\n\n--------------MENU--------------\n");
        printf("0 Addition\n1 Subtraction\n"
               "2 Multiplication\n3 Division\n4 Quit\nEnter option: ");
        scanf_s("%d", &choice);
    }

    puts("\nProgram finished.");
    return 0;
}

// function to calculate the sum of the two numbers (addition)
void add(double value1, double value2) {

    double sum = value1 + value2;

    // display results
    printf("\nADDITION\n---------------------------");
    printf("\nSum of %.2lf and %.2lf: %.2lf", value1, value2, sum);
}

// function to calculate the difference between the two numbers (subtraction)
void subtract(double value1, double value2) {

    double difference  = value1 - value2;

    // display results
    printf("\nSUBTRACTION\n---------------------------------------");
    printf("\nDifference between %.2lf and %.2lf: %.2lf", value1, value2, difference);
}

// function to calculate the product of the two numbers (multiplication)
void multiply(double value1, double value2) {

    double product = value1 * value2;

    // display results
    printf("\nMULTIPLICATION\n------------------------");
    printf("\nProduct of %.2lf and %.2lf: %.2lf", value1, value2, product);

}
// function to calculate the quotient of the two numbers (division)
void divide(double value1, double value2) {

    double quotient = value1 / value2;

    // display results
    printf("\nDIVISION\n-------------------------------");
    printf("\nQuotient of %.2lf and %.2lf: %.2lf", value1, value2, quotient);

}
