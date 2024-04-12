/* 7.18
 * What does this program do?
 * ANSWER:
 * This program accepts a string from the user then
 * uses a loop to go through the string, increment
 * x for each character, then return x, which represents
 * the number of characters in the string. */

#include <stdio.h>
#define SIZE 80

size_t mystery2(const char *s); // prototype

int main(void) {
char string[SIZE]; // create char array

puts("Enter a string: ");
scanf("%79s", string);
printf("%d\n", mystery2(string));
 }

 // What does this function do?
 size_t mystery2(const char *s) {
 size_t x;

 // loop through string
 for (x = 0; *s != '\0'; ++s) {
 ++x;
 }

 return x;
 }
