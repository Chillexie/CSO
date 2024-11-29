/**
 * CSO1 HW8 Circularly Linked List Implementation
 *
 * Your Computing ID: dkt4kr 
 */

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

cll_node *cll_head(cll_node *list){
    cll_node *ptr = list;
    if (ptr) {
        do {
            if (ptr->is_head) 
                return ptr; // return node if it is the head node
            ptr = ptr->next; // next pointer
        } while (ptr != list);
    }
    return NULL; // empty list OR list set up wrong
}

cll_node *cll_tail(cll_node *list) {
    cll_node *ptr = list;
    if (ptr) {
        do {
            if (ptr->is_head) 
                return ptr->prev; // return previous node (tail) if we are at the head node
            ptr = ptr->next; // next pointer
        } while (ptr != list);
    }
    return NULL; // empty list OR list set up wrong
}


unsigned long cll_length(cll_node *list) {
    cll_node *ptr = list;
    int count = 0;
    if (ptr) {
        do {
            count+=1; 
            ptr = ptr->next; // next pointer
        } while (ptr != list);
    }
    return count;
}

cll_node *cll_find(cll_node *list, int value) {
    cll_node *ptr = list;
    if (ptr) {
        do {
            if (ptr->value == value) // check if we have found our value
                return ptr;
            ptr = ptr->next; // next pointer
        } while (ptr != list);
    }
    if(ptr->value == value) // check final value
        return ptr;
    return NULL; // empty list or value not in list
}

/**
 * Given a pointer to a node in a list, remove that node from the list,
 * `free`ing its memory in the process. Returns a pointer to the node that now
 * occupies the same position in the list that the removed node used to occupy.
 * 
 * If given `NULL`, this function does nothing and returns `NULL`.
 */
cll_node *cll_remove(cll_node *list) {
    //handle empty list situation
    if(list == NULL){
        return NULL;
    }

    //if list only has one element
    if(list->next == list){ //in a circular linkedlist, if there's one element, then head's next is tail 
        free(list); 
        return NULL; 
    }
    
    //adjust location of the prev & next to remove the node 
    list->prev->next = list->next; 
    list->next->prev = list->prev; 

    //the next node that occupies the removed address, we create a node and return it
    cll_node *next_node = list->next; 
    free(list); 
    return next_node;
}

/**
 * Extend a list by one by adding `value` next to `list`. If `before` is 0,
 * inserts `value` immediately following the node pointed to by `list`;
 * otherwise inserts `value` immediately before that node. If `list` is NULL,
 * the newly inserted node is the entire list and the `is_head` value is set
 * to 1 for this node. If `list` is not NULL, be sure to initialize all
 * fields of the node. In all cases, the new node is allocated using `malloc` 
 * and returned by the function.
 */
cll_node *cll_insert(int value, cll_node *list, int before) {  
    //init the new node
    cll_node *new_node = (cll_node *)malloc(sizeof(cll_node));

    //if new node is null 
    if (new_node == NULL){
        return NULL;
    }
    
    //init all fields of a new node
    new_node->value = value; 
    new_node->prev = new_node; 
    new_node->next = new_node; 
    new_node->is_head = 0; 

    //if list is empty, set prev and next to node itself 
    if (list == NULL){
        new_node->is_head = 1; 
        new_node->next = new_node; 
        new_node->prev = new_node; 
        return new_node; 
    }

    //if before is 0, insert after pointer
    if(before == 0){
        new_node->prev = list; 
        new_node->next = list->next;
        list->next->prev = new_node; 
        list->next = new_node; 
    }else{ //else insert before pointer
        new_node->next = list; 
        new_node->prev = list->prev; 
        list->prev->next = new_node; 
        list->prev = new_node; 
    }
    return new_node; 
}


/**
 * Displays the contents of the list separated by commas and surrounded by
 * brackets, with the pointed-to node highlighted with asterisks.
 *
 * Reference solution provided with assignment description
 */
void cll_show(cll_node *list) {
    // Find the head of the linked list
    cll_node *head = cll_head(list);
    cll_node *ptr = head;
    // Print opening [
    putchar('[');
    // Loop through list printing values
    if (ptr) {
        do {
            if (!ptr->is_head) 
                printf(", "); // include a comma if not the first element
            if (ptr == list) 
                putchar('*'); // include * surrounding parameter element
            printf("%d", ptr->value);
            if (ptr == list) 
                putchar('*');
            ptr = ptr->next; // next pointer
        } while (ptr != head);
    }
    // Print closing ]
    puts("]");
}


int main(int argc, const char *argv[]) {

    // Example debugging code.  You should write other
    // tests, including testing corner cases.
    cll_node *x = NULL;
    putchar('A'); cll_show(x);
    x = cll_insert(25, x, 1);
    putchar('B'); cll_show(x);
    x = cll_insert(1, x, 0);
    putchar('C'); cll_show(x);
    x = cll_insert(98, x, 1);
    putchar('D'); cll_show(x);
    x = cll_insert(0, x, 1);
    putchar('E'); cll_show(x);
    x = cll_insert(-8, cll_tail(x), 0);
    putchar('F'); cll_show(x);
    cll_node *y = cll_head(x);
    putchar('G'); cll_show(y);
    printf("Length: %lu (or %lu)\n", cll_length(y), cll_length(x));
    x = cll_remove(x);
    putchar('H'); cll_show(x);
    putchar('I'); cll_show(y);
    x = cll_remove(cll_find(y, 98));
    putchar('J'); cll_show(x);
    putchar('K'); cll_show(y);

    return 0;
}
