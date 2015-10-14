/* 
 * File:   linked_list.c
 * Author: kanvikhanna
 * Version 1.0
 * Created on September 26, 2015, 9:40 AM
 */
#include <stdio.h> /* for printf support */
#include <stdlib.h> /* for malloc support */
#include "linked_list.h"

/*
 * node definition
 */

typedef struct _node
{
    struct _node* prev;
    struct _node* next;
    int data;
} node;

/*
 * module local data and functions
 */
static node* head = NULL;
static node* tail = NULL;

static node* _search(int data);

/*
 * add_node
 */
int add_node(int data)
{
    node* new_node = malloc(sizeof(node));
    
    // Adding the first node to the linked list
    if(head == NULL)
    {
        new_node->prev = NULL;
        new_node->data = data;
        new_node->next = NULL;
        head = new_node;
        tail = new_node;
        return 1;
    }
    
    // Adding a new node at the end of the linked list
    else
    {
        node* temp;
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = temp;
        
        tail = new_node;
        return 1;
    }
    
    return 0;
    
}


/*
 * remove_node
 */
int remove_node(int data)
{
    // Removing a node from the linked list
    
        node* temp;
        temp = _search(data);
        
        if(temp)
        {
            //checking for last node
            if(temp->next == NULL)
            {
                (temp->prev)->next = NULL;
                tail = temp;
            }
            //checking for first node
            else if(temp->prev == NULL)
            {
                (temp->next)->prev = NULL;
                head = temp->next;
            }
            else
            {
                (temp->prev)->next = temp->next;
                (temp->next)->prev = temp->prev;
            }
            free(temp);
            return 1;
        }

    return 0;  
}


/*
 * traverse
 */
void traverse(void)
{
    if(head == NULL)
    {
        printf("The linked list is empty");
    }
    else
    {
        printf("The linked is:\n");
        node* temp = head;
        while(temp != NULL)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
    }
}

/*
 * search
 */
int search(int data)
{
    return ( _search(data) && 1 );
}

/*
 * add_node_after
 */
int add_node_after(int after, int data)
{
    node* temp = _search(data);
    if(temp)
    {
        node* new_node = malloc(sizeof(node));
        new_node->data = data;
        new_node->prev = temp;
        new_node->next = temp->next;
        (temp->next)->prev = new_node;
        temp->next = new_node;
        return 1;
    }
    else
        return 0;
   
}

/*
 * _search
 */
node* _search(int data)
{
    node* temp;
    temp = head;
    while(temp)
    {
        if(temp->data == data)
        {
            break;
        }
        temp = temp->next;
    }
    
    return temp;
}
