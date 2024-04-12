/* 7.24
 * This program will modify the program in Fig 6_17 to use a menu-driven
 * interface. The program will offer the following options:
    Enter a choice:
    0 Print the array of grades
    1 Find the minimum grade
    2 Find the maximum grade
    3 Print the average on all tests for each student
    4 End program
 */

// fig06_17.c
// Two-dimensional array manipulations.
#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

// function prototypes
void minimum();
void maximum();
void average();
void printGrades();

// array to store student grades
int studentGrades[STUDENTS][EXAMS] =
        {{77, 68, 86, 73},
         {96, 87, 89, 78},
         {70, 90, 86, 81}};


// function main begins program execution
int main(void) {

    // processGrades is an array of functions that each take an int as an argument and returns void
    void (*processGrades[4])(int) = {printGrades, minimum, maximum, average};

    // menu layout
    printf("\n-------------MENU-------------\n    0 Print all grades\n"
           "    1 Display minimum grade\n"
           "    2 Display maximum grade\n"
           "    3 Display average test grade\n"
           "    4 Quit program\n"
           "\nEnter option: ");

    // initialize choice
    int choice = 0;
    scanf("%d", &choice);

    // while choice is between 0 and 4
    while (choice >= 0 && choice < 4) {

        // dereference pointer to call function, passing choice as the argument
        (*processGrades[choice])(choice);

        // menu layout
        printf("\n\n-------------MENU-------------\n    0 Print all grades\n"
               "    1 Display minimum grade\n"
               "    2 Display maximum grade\n"
               "    3 Display average test grades\n"
               "    4 Quit program\n"
               "\nEnter option: ");

        scanf_s("%d", &choice);
    }

    printf("\nProgram finished.");

    return 0;
}

// Find the minimum grade
void minimum() {
    printf("\nMINIMUM GRADE\n----------------");
    int lowGrade = 100; // initialize to highest possible grade

    // loop through rows of grades
    for (size_t row = 0; row < STUDENTS; ++row) {
        // loop through columns of grades
        for (size_t column = 0; column < EXAMS; ++column) {
            if (studentGrades[row][column] < lowGrade) {
                lowGrade = studentGrades[row][column];
            }
        }
    }

    printf("\nLowest grade: %d", lowGrade);  // print minimum grade
}

// Find the maximum grade
void maximum() {
    printf("\nMAXIMUM GRADE\n-----------------");
    int highGrade = 0; // initialize to lowest possible grade

    // loop through rows of grades
    for (size_t row = 0; row < STUDENTS; ++row) {
        // loop through columns of grades
        for (size_t column = 0; column < EXAMS; ++column) {
            if (studentGrades[row][column] > highGrade) {
                highGrade = studentGrades[row][column];

            }
        }
    }

    printf("\nHighest grade: %d", highGrade); // print maximum grade
}

// Determine the average grade for each student
void average() {
    printf("\nAVERAGE TEST GRADES\n--------------------");

    // loop through students
    for (size_t row = 0; row < STUDENTS; ++row) {
        double average = 0;
        double total = 0;
        // loop through exams
        for (size_t column = 0; column < EXAMS; ++column) {
            total += studentGrades[row][column];  // total all grades for one student
            average = (double)(total / 4);  // calculate average test grade for student

        }
        printf("\nStudent %zu: %.2f", row + 1, average);  // print average
    }
}

// Print the array
void printGrades() {

    printf("\nALL GRADES\n-----------------------------------------------------");
    // output column heads
    printf("\n%-10s", "                Test 1     Test 2    Test 3    Test 4");

    // output grades in tabular format
    for (size_t row = 0; row < STUDENTS; ++row) {
        // output label for row
        printf("\nStudent %-10zu", row + 1);

        // output grades for one student
        for (size_t column = 0; column < EXAMS; ++column) {
            printf("%-10d", studentGrades[row][column]);
        }
    }
}
