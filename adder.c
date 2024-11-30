#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {
    const char* flag = NULL; // Store the flag
    
    // handle no flag situation
    if (argc <= 1) {
        char type[3] = ""; // use to store the datatype of users' input 
        printf("Enter a datatype(i for int, f for float, s for string): ");

        if (fgets(type, sizeof(type), stdin) == NULL || type[0] == '\n') {
            flag = "-i"; // Default to int
        } else {
            // Remove newline character if present
            type[strcspn(type, "\n")] = 0;

            if (strcmp(type, "I") == 0) {
                flag = "-i";
            } else if (strcmp(type, "F") == 0) {
                flag = "-f";
            } else if (strcmp(type, "S") == 0) {
                flag = "-s";
            } else {
                printf("Invalid datatype.\n");
                return 1;
            }
        }
    }else {
        flag = argv[1]; // Use the provided flag
    }

    // handle flag-based situations
    if (strcmp(flag, "-i") == 0) { // datatype is integer 
        int int1, int2; // init inputs
        printf("Enter your first value: "); 
        scanf("%d", &int1); // reads and stores to int1 f

        printf("Enter your second value: ");
        scanf("%d", &int2); // reads and stores to int2

        int result = int1 + int2; 
        printf("%d\n", result);
    } else if (strcmp(flag, "-f") == 0) { // datatype is float 
        float float1, float2; // init floats 

        printf("Enter your first value: "); 
        scanf("%f", &float1); // reads and stores to float1 

        printf("Enter your second value: ");
        scanf("%f", &float2); // reads and stores to float2

        float result = float1 + float2; // sum of floats
        printf("%g\n", result); 
    } else if (strcmp(flag, "-s") == 0) { // if datatype is string
        // make sure that the string has enough space for concatenation 
        char string1[21]; 
        char string2[11]; 

        // prompts user to enter a string
        printf("Enter First String: "); 
        // only reads at most 10 characters the string 
        scanf("%10s", string1); 

        // same for second string
        printf("Enter Second String: ");
        scanf("%10s", string2);

        // concatenates two strings 
        strcat(string1, string2);
        printf("%s\n", string1);
    } else { // if invalid flag was set 
        printf("Invalid flag supplied"); 
        return 1; 
    }
    return 0;
}