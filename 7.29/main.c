/* 7.29
 * This program will provide a software-based simulation of the Simpletron
 * computer. */

#include <stdio.h>

// operation codes
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

#define LIMIT 100
#define STOP 50

// function prototypes
void load(int memory[]);
void execute(int memory[], int *accumulator, int *instructionCounter, int *instructionRegister,
             int *operationCode, int *operand);
void dump(int memory[], int accumulator, int instructionCounter, int instructionRegister, int operationCode, int operand);
void intro();

int main() {

    // initialize variables
    int memory[LIMIT] = {0};
    int operand = 0;
    int operationCode = 0;
    int instructionRegister = 0;
    int instructionCounter = 0;
    int accumulator = 0;

    // function calls
    intro();
    load(memory);
    execute(memory, &accumulator, &instructionCounter, &instructionRegister, &operationCode, &operand);
}

// function load will load values into memory
void load(int memory[]) {

    int i = 0;
    int j = 0;

    // while i and j are within bounds
    while (i <= LIMIT && j != -99999) {

        printf("\n\n");

        // while j is between -9999 and 9999 and does not equal -99999
        while ((j >= -9999 || j <= 9999) && (j != -99999)) {

            // prompt user to enter codes for each memory location
            if (i < 10) {
                printf("%02d ? +", i);
            }
            else {
                printf("%d ? +", i);
            }
            scanf_s("%d", &j);

            // notify user of invalid input and decrement i for user to re-enter
            if ((j < -9999 || j > 9999) && j != -99999) {
                printf("\n*** Error: invalid input ***");
                --i;
            }

            // store value into memory if value does not equal -9999
            if (j != -99999) {
                memory[i] = j;
            }
            ++i;  // increment i
        }

    }
    // once user enters -99999, program finished loading
    printf("\n*** Program loading completed ***\n*** Program execution begins ***\n\n");
}

void execute(int memory[], int *accumulator, int *instructionCounter, int *instructionRegister,
             int *operationCode, int *operand) {

    while (*instructionCounter < LIMIT) {

        // fetch the data
        *instructionRegister = memory[*instructionCounter];
        *operationCode = *instructionRegister / 100;
        *operand = *instructionRegister % 100;

        // perform commands
        switch (*operationCode) {

            case READ:  // read value from keyboard into memory
                printf("READ: ");
                scanf_s("%d", &memory[*operand]);
                break;

            case WRITE:  // write value from specific location in memory
                printf("WRITE: %d\n", memory[*operand]);
                break;

            case LOAD:  // load value from specific location in memory into accumulator
                printf("LOAD: %d\n", memory[*operand]);
                *accumulator = memory[*operand];
                break;

            case STORE:  // store a value from the accumulator into a specific location in memory
                printf("STORE: %d\n", *accumulator);
                memory[*operand] = *accumulator;
                break;

            case ADD:  // add value from specific location in memory to value in accumulator
                printf("ADD: %d\n", memory[*operand]);
                *accumulator += memory[*operand];
                break;

            case SUBTRACT:  // subtract value from specific location in memory from value in accumulator
                printf("SUBTRACT: %d\n", memory[*operand]);
                *accumulator -= memory[*operand];
                break;

            case DIVIDE:  // divide a value from a specific location in memory into the value in accumulator
                printf("DIVIDE: %d\n", memory[*operand]);
                if (memory[*operand] == 0) {
                    printf("\n*** Attempt to divide by zero ***\n");
                    printf("\n*** Simpletron execution abnormally terminated ***\n");
                    *operationCode = STOP;
                } else {
                    *accumulator /= memory[*operand];
                }
                break;

            case MULTIPLY:  // multiply a value from specific location in memory by the value in accumulator
                printf("MULTIPLY: %d\n", memory[*operand]);
                *accumulator *= memory[*operand];
                break;

            case BRANCH:  // branch to a specific location in memory
                printf("BRANCH TO %d\n", *operand);
                *instructionCounter = *operand;
                break;

            case BRANCHNEG:  // branch to a specific location in memory if accumulator is negative
                printf("BRANCHNEG TO %d\n", *operand);
                if (*accumulator < 0)
                    *instructionCounter = *operand;
                break;

            case BRANCHZERO:  // branch to a specific location in memory if accumulator is zero
                printf("BRANCHZERO TO %d\n", *operand);
                if (*accumulator == 0)
                    *instructionCounter = *operand;
                break;

            default:  // default case, terminates program if user enters invalid operation
                if (*operationCode != HALT) {
                    printf("\n\n*** Error: attempt to execute invalid operation ***\n");
                    *operationCode = STOP;
                }
        }

        // accumulator overflow error if accumulator is out of bounds
        if (*accumulator > 9999 || *accumulator < -9999) {
            printf("\n\n*** Error: accumulator overflows ***\n");
            *operationCode = STOP;
        }
        // if user halts program, dump data
        if (*operationCode == HALT) {
            printf("\n\n*** Simpletron execution terminated ***\n");
            dump(memory, *accumulator, *instructionCounter, *instructionRegister, *operationCode, *operand);
            break;
        }

        // when operationCode is STOP, dump data
        else if (*operationCode == STOP) {
            printf("\n\n*** Simpletron execution abnormally terminated ***\n");
            dump(memory, *accumulator, *instructionCounter, *instructionRegister, *operationCode, *operand);
            break;
        }

    }
}

// function dump prints the results
void dump(int memory[], int accumulator, int instructionCounter, int instructionRegister, int operationCode, int operand) {

    int i, j = 0;

    // print header and current values
    printf("\nREGISTERS:\naccumulator\t\t%+05d\ninstructionCounter\t   %02d\ninstructionRegister\t%+05d"
           "\noperationCode\t\t   %02d\noperand\t\t\t   %02d", accumulator, instructionCounter, instructionRegister, operationCode, operand);
    printf("\nMEMORY:\n");

    // print column numbers
    for(i = 0; i < 10; ++i) {
        printf("%7d", i );
    }
    printf("\n");

    // print row numbers
    for(i = 0; i < LIMIT; i += 10) {

        if (i == 0) {
            printf("%d ", i);
        }
        else {
            printf("%d", i);
        }

        // print current values in memory locations
        for(j = i; j < i + 10; ++j) {

            if (memory[j] == 0) {
                printf("  +0000");
            }
            else
                printf("  %+d", memory[j]);
        }
        printf("\n");
    }
}

// function intro prints the introduction to the Simpletron
void intro() {
    printf("\n         *** Welcome to Simpletron ***\n"
           "***                                           ***\n"
           "*** Please enter your program one instruction ***\n"
           "*** (or data word) at a time. I will type the ***\n"
           "*** location number and a question mark (?).  ***\n"
           "*** You then type the word for that location. ***\n"
           "*** Type the sentinel -99999 to stop entering ***\n"
           "*** your program.                             ***");
}


