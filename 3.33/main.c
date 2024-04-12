/* 3.33
 * This program will read the side
 * of a square between numbers 1 and 20
 * then print a hollow square.
 * */

#include<stdio.h>

int main() { //main header
    //initialize variables
    int size = 0;

    printf("%s", "Enter a number 1 through 20 for the side of the square: "); //prompt user for size
    scanf_s("%d", &size); //read size value from kb

    if (size < 1 || size > 20){ //if size is outside of 1 and 20
        printf("%s", "Invalid number. Please enter a size between 1 and 20: "); //prompt user to re-enter number
        scanf_s("%d", &size); //read value of size from kb
    }
        for (int i = 0; i < size; i++) {
            //iterate columns
            for (int j = 0; j < size; j++) {
                //check current position
                if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
                    printf("*"); //output
                else
                    printf(" "); //iterate the "hollow" spaces
            } //end 2nd for
            printf("\n");
        } //end first four

} //end main









