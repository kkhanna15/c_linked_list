/* 
 * File:   main.c
 * Author: kanvikhanna
 * Version 1.0
 * Created on September 26, 2015, 9:40 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"linked_list.h"

/*
 * 
 */
typedef struct _student_type
{
    char* name;
    int marks;
}student_type;

student_type student_db[] = {
    {.name = "John",.marks = 65},
    {.name = "Kevin",.marks = 55},
    {.name = "Penny",.marks = 35},
    {.name = "Mark",.marks = 89},
    {.name = "Rose",.marks = 47},
    {.name = "Uma",.marks = 95},
    {.name = "Tom",.marks = 77},
    {.name = "Pam",.marks = 21},
    {.name = "Lara",.marks = 76},
    {.name = "Bob",.marks = 35},         
};


void display_node(void* data)
{
    printf("%s\t",((student_type*)data)->name);
    printf("%d\n",((student_type*)data)->marks);
}

int compare(void* x, void* y)
{
    return(strcmp(((student_type*)x)->name,((student_type*)y)->name));
}

int main(void) {
    // initialize linked list
    int init = init_link_list(display_node, compare);
    if(init)
    {
        // create a linked list
        printf("Creating a linked list\n");
        int add, i, found, j;
        student_type* p_new_data;
        student_type* p_after;
        student_type* status;
    
        for(i = 0; i < 10; i++)
        {
            add = add_node(&student_db[i]);
        }


        // traverse and print the linked list
        printf("Traversing a linked list\n");
        traverse();
        printf("\n");
        
       
        // remove a node
        printf("Removing a node\n");
        status = remove_node(&student_db[1]);
        if(status != NULL)
        {
            //free(status);
            traverse(); 
        }
        else
            printf("The node does not exist.");
        
        printf("\n");
       
        // remove a node
        printf("Removing a node\n");
        status = remove_node(&student_db[1]);
        if(status != NULL)
        {
            free(status);
            traverse(); 
        }
        else
            printf("The node does not exist.");
        
        printf("\n");
        
        // add node after a node
        p_new_data = (student_type*)malloc(sizeof(student_type));
        p_new_data->name = "Dan";
        p_new_data->marks = 62;

        printf("Adding a node after a given node\n");
        add = add_node_after(&student_db[3],p_new_data);
        if(add)
        {
             printf("Success!\n");
             traverse();            
        }
        else
        {
            printf("Failure!\n");
            printf("The given node does not exist.");
            free(p_new_data);
        }
        printf("\n");
       
       
        printf("Adding a node after a given node\n");
        p_after = (student_type*)malloc(sizeof(student_type));
        p_after->name = "Markst";
        p_new_data = (student_type*)malloc(sizeof(student_type));
        p_new_data->name = "Jojo";
        p_new_data->marks = 22;
        add = add_node_after(p_after, p_new_data);
        if(add)
        {
             printf("Success!\n");
             traverse();            
        }
        else
        {
            printf("Failure!\n");
            printf("The given node does not exist.\n");
            free(p_new_data);
        }
        free(p_after);
        printf("\n");
        
        // search for a node
        student_type* p_find_data;
        p_find_data = (student_type*)malloc(sizeof(student_type));
        p_find_data->name = "Rosei";
        printf("Searching a linked list\n");
        found = search(p_find_data);
        if(found)
            printf("Success!\nNode exists.\n");
        else
            printf("Failure!\nNode not found.\n");
        free(p_find_data);
        printf("\n");
        
        student_type* rh = remove_head();
        if(rh != NULL)
            printf("The head was removed. The value is %s\n",rh->name);
        printf("\n");
        
        student_type* rt = remove_tail();
        if(rt != NULL)
            printf("The tail was removed. The value is %s\n",rt->name);
        printf("\n");
        
        traverse();
        printf("\n");
       
    }
    return (EXIT_SUCCESS);
}

