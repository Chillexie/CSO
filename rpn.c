//computing ID: dkt4kr 
//HW8: Postfix Calculator 
#include <stdio.h>
#include <ctype.h>
#include "linkedlist.c"
#include <string.h>
//check if token in an integer
// int is_number(const char *token) {
//     int i = 0;
//     if (strcmp(token, "-") == 0) { token++; // Allow negative numbers
//     while (*token) {
//         if (!isdigit(*token)) {
//             return 0; // Not a valid number
//         }
//         token++; 
//     }
//     return 1; // Valid number
// }

int is_number(const char *token) {
    if (*token == '-' || *token == '+') {
        token++; // Skip leading sign if present
    }
    if (!isdigit(*token)) {
        return 0; // If no digits follow, it's not a number
    }
    while (*token) {
        if (!isdigit(*token)) {
            return 0; // If any non-digit character is found, it's not a number
        }
        token++;
    }
    return 1; // It's a valid number
}

//push value to the stack (only int)
cll_node *push(cll_node *head, int value) {
    if (head == NULL) {
        // If the list is empty, the new node becomes the head
        head = cll_insert(value, NULL, 1);
    } else {
        // Insert after the tail to maintain the order of pushing (FIFO)
        cll_node *tail = head->prev; // Find the current tail
        cll_insert(value, tail, 0);  // Insert after the current tail
    }
    return head; // Return the head since it hasn't changed

}

//pop values from the stack 
cll_node *pop(cll_node *head, int *popped_val){
    //if stack is empty, return error message 
    if (head == NULL){
        fprintf(stderr, "stack underflow\n");
        return NULL; 
    }

    cll_node *tail = head->prev;

    if (tail == head) {
        // Only one node in the stack
        *popped_val = head->value;
        free(head);
        return NULL;  // Stack is now empty
    } else {
        // More than one node
        *popped_val = tail->value;
        // Update the previous element to be the new tail
        cll_node *new_tail = tail->prev;
        new_tail->next = head;
        head->prev = new_tail;

        free(tail);
        return head;  // Return the updated head
    } 
}

//to print stack 
void print_stack(cll_node *head) {
    if (head == NULL) {
        printf("[]\n");
        return;
    }

    cll_node *ptr = head; 

    // Start printing the stack with a clear format
    printf("[ ");
    // Traverse the circular linked list
    do {
        printf("%d ", ptr->value);
        ptr = ptr->next;
        if (ptr != head){
            printf(", "); 
        }
    } while (ptr != head);
    printf(" ]\n");
}


//prints an array-based stack
int main(void){
    char input[1000000];//init number of input 
    cll_node *head = NULL; //init empty stack

    //read input 
    while (fgets(input, sizeof(input), stdin)){ 
        // Skip blank lines and spaces 
        if (strlen(input) == 0 || strspn(input, " \n") == strlen(input)) {
            continue; // Skip empty or whitespace-only lines
        }

        char *token = strtok(input, " \n"); //split input by space and store each in token 
        while (token){
            //if number, push to stack
            if(is_number(token)){
                int num = atoi(token); 
                head = push(head, num); 
            } 
            else if(strlen(token) == 1 && strchr("+-*%", token[0])){ //if char, perform operation
                //check there's at least two items on stack 
                if (cll_length(head) < 2){ 
                    token = strtok(NULL, " \n");
                    continue; //skip this operator 
                }
                //pop operands from the stack
                int b, a;  
                head = pop(head, &b); //first item on stack, which is the second operand
                head = pop(head, &a); //second item on stack, which is the first operand 
                int result; //init result

                //perform the operation
                switch(token[0]){
                    case '+': 
                        result = a + b; break; 
                    case '-':
                        result = a - b; break;
                    case '*': 
                        result = a * b; break;
                    case '%':
                        if (b == 0) {
                            token = strtok(NULL, " \n");
                            continue; // Exit on division by zero
                        }
                        result = a % b; 
                        break;
                }
                head = push(head, result); //push result back to stack 
            }else{
                //if token is invalid
                token = strtok(NULL, " \n");
                continue; 
            }
            token = strtok(NULL, " \n");//get the next char or int
        }
    }
    print_stack(head); 
}
