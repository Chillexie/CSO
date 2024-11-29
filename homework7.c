/*************************************************
 * CS 2130 Homework 7
 * Fall 2024 - Writing C
 *
 * Computing ID: dkt4kr
 ************************************************/

// ===============================================
// Write your functions here:
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>   // For strdup, strcpy



//this function converts any lower-case letters preceded
// by a space in s into upper-case letters
void titlecase(char *s){
    //check for null
    if (s == 0){
        return;
    }
    // Always capitalize the first letter if it is a lowercase letter
    if (*s >= 'a' && *s <= 'z') {
        *s = *s - ('a' - 'A'); // Convert to uppercase
    }

   // Capitalize letters after spaces, quotes, or other delimiters
    for (char *p = s + 1; *p != '\0'; p++) {
        if ((*(p - 1) == ' ' || *(p - 1) == '\"') && *p >= 'a' && *p <= 'z') {
            *p -= ('a' - 'A'); // Convert to uppercase
        }
    }
}

void fibarray(unsigned short *dest, unsigned num){
    //Null check if any operation is needed
    if (num == 0){
        return; 
    }

    //sets the first element in the array the first fib #(1)
    dest[0] = 1; 

    //check if we need more than one fib num
    if (num >1){
        dest[1] = 1; 
    }

    //calculates fib # up to the num-th term
    for (unsigned i = 2; i < num; i++){
        dest[i] = (dest[i-1] + dest[i-2]) % 65536; 
    }
}

//computes and returns x^e
long recpow(long x, unsigned char e){
    //base case: if e = 0, answer is 1
    if (e==0){
        return 1; 
    }
    //recursive loop 
    return x * recpow(x, e-1); 
}

//returns the smallest prime number larger than x
unsigned long nextprime(unsigned long x){
    //if x <= 1, the smallest next prime is 2
    if (x <= 1){
        return 2; 
    }

    x += 1; //since x itself is not included, increment x to check for the next num 

    //while loop stays true until found a value to return 
    while (true){
        bool is_prime = true; 
        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) { // If x is divisible by j, then it's not a prime
                is_prime = false;
                break; // Exit the loop once a divisor is found
            }
        }

        //if num passed the for loop, means it's a prime, then return it
        if (is_prime){
            return x; 
        }

        //if x didn't pass the loop = it's not a prime, increment x to check the next num
        x++; 
    }
}

//this function Rearrange the first length values of arr in place, such that 
//all of its zero values appear first, followed by its non-zero values in their original order.
void pull0(int *arr, unsigned length){

    int nonZeroIndex = length - 1;  // Start from the end for non-zero elements
    int zeroIndex = length - 1;     // Start from the end to fill zeros

    // First pass: Move non-zero elements to their correct positions
    for (int i = length - 1; i >= 0; i--) {
        if (arr[i] != 0) {
            arr[nonZeroIndex--] = arr[i];  // Place non-zero element and decrement
        }
    }

    // Second pass: Fill the remaining positions with zeros
    for (int i = nonZeroIndex; i >= 0; i--) {
        arr[i] = 0;  // Fill zeros at the start of the array
    }
}







// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Update the followng main function to test your
// code.  You should test normal input values as
// well as edge cases.  Do NOT rely only on the
// Gradescope submission site, as submissions are
// limited.
// Note: You must leave this comment block to ensure
// proper grading of your submission.


int main() {
    // //test titlecase()   WORKS!
    // char *s = strdup(" the book \"the C programming language.\"");
    // printf("before: %s\n", s);
    // titlecase(s);
    // printf("after:  %s\n", s);
    // free(s);

    // //fibarray() test;      WORKS!
    // unsigned short a[64];
    // fibarray(a, 64);
    // for (int row=0; row<8; row+=1) {
    //     for (int col=0; col<8; col+=1) {
    //         printf(" %04hx", a[row*8 + col]);
    //     }
    //     printf("\n");
    // }

    // //check nextprime() WORKS!
    // long x = 100;
    // for (int i=0; i<10; i+=1) {
    //     x = nextprime(x);
    //     printf("%ld\n", x);
    // }
    // printf("%ld\n", nextprime(1000000000000));

    // //test recpow(); WORKS
    // long x = -21;
    // unsigned char e = 13;
    // long ans = recpow(x, e);
    // printf("%ld\n", ans);
    // printf("%ld\n", recpow(11, 0));

//test pull0() WORKS
// int x[] = {1, 7, 3, 2, 0, 5, 0, 8, 0, 7, 5, 6, 8, 8, 7, 7, 2, 9};
// for (int i=0; i<18; i+=1) printf("%d ", x[i]); printf("\n");
// pull0(x, 15);
// for (int i=0; i<18; i+=1) printf("%d ", x[i]); printf("\n");
}
