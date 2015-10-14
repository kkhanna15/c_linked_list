/* 
 * File:   main.c
 * Author: kanvikhanna
 *
 * Created on September 26, 2015, 9:40 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include"linked_list.h"

/*
 * 
 */
int main(void) {
    
    // create a linked list
    printf("Creating a linked list\n");
    int add, i, found;
    for(i = 1; i <= 10; i++)
        add = add_node(i);
    
    // traverse and print the linked list
    printf("Traversing a linked list\n");
    traverse();
    printf("\n");
    
    // remove a node
    printf("Removing a node\n");
    remove_node(1);
    traverse();
    printf("\n");
    // remove a node
    printf("Removing a node\n");
    remove_node(1);
    traverse();
    printf("\n");

    
    // add node after a node
    printf("Adding a node after a node\n");
    add = add_node_after(4,5);
    if(add)
        printf("success\n");
    else
        printf("failure\n");
    
    printf("Adding a node after a node\n");
    add = add_node_after(12,5);
    if(add)
        printf("success\n");
    else
        printf("failure\n");
    
    traverse();
    printf("\n");
    
    // search for a node
    printf("Searching a linked list\n");
    found = search(8);
    if(found)
        printf("success\n");
    else
        printf("failure\n");
    

    return (EXIT_SUCCESS);
}

