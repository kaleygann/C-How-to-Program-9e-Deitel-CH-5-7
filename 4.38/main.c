/* 4.38
 * This program will use iteration
 * and switch statements to print
 * the song "Twelve Days of Christmas"
 */

#include <stdio.h>

int main() { //main header
    for (int i = 1; i <= 12; i++) { //for loop to iterate days

            printf("\nOn the "); //print first two words of first line

            switch(i) { //switch nested in outer for
                case 1: printf("first"); //output when i = 1
                break; //exit switch
                case 2: printf("second"); //output when i = 2
                break; //exit switch
                case 3: printf("third"); //output when i = 3
                break; //exit switch
                case 4: printf("fourth"); //output when i = 4
                break; //exit switch
                case 5: printf("fifth"); //output when i = 5
                break; //exit switch
                case 6: printf("sixth"); //output when i = 6
                break; //exit switch
                case 7: printf("seventh"); //output when i = 7
                break; //exit switch
                case 8: printf("eighth"); //output when i = 8
                break; //exit switch
                case 9: printf("ninth"); //output when i = 9
                break; //exit switch
                case 10: printf("tenth"); //output when i = 10
                break; //exit switch
                case 11: printf("eleventh"); //output when i = 11
                break; //exit switch
                case 12: printf("twelfth"); //output when i = 12
                break; //exit switch
            } //end switch

            printf(" day of Christmas, my true love gave to me\n"); //print first line of each stanza

    for (int j = i; j >= 1; --j) { //for loop to iterate gifts

        switch(j) { //switch nested in inner for
            case 1: printf("A partridge in a pear tree\n"); //output when j = 1
                break; //exit switch
            case 2: printf("Two turtle doves, and\n"); //output when j = 2
                break; //exit switch
            case 3: printf("Three French hens,\n"); //output when j = 3
                break; //exit switch
            case 4: printf("Four calling birds,\n"); //output when j = 4
                break; //exit switch
            case 5: printf("Five golden rings,\n"); //output when j = 5
                break; //exit switch
            case 6: printf("Six geese-a-laying,\n"); //output when j = 6
                break; //exit switch
            case 7: printf("Seven swans-a-swimming,\n"); //output when j = 7
                break; //exit switch
            case 8: printf("Eight maids-a-milking,\n"); //output when j = 8
                break; //exit switch
            case 9: printf("Nine ladies dancing,\n"); //output when j = 9
                break; //exit switch
            case 10: printf("Ten lords-a-leaping,\n"); //output when j = 10
                break; //exit switch
            case 11: printf("Eleven pipers piping,\n"); //output when j = 11
                break; //exit switch
            case 12: printf("Twelve drummers drumming,\n"); //output when j = 12
                break; //exit switch
        } //end switch

        } //end inner for
    } //end outer for
} //end main

