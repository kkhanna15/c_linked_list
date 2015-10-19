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
    void* data;
} node;

/*
 * module local data and functions
 */
static node* head = NULL;
static node* tail = NULL;
static display_node_fptr_type display_node_fptr;
static compare_node_fptr_type compare_node_fptr;
static node* _search(void* data);

/*
 * add_node
 */
int add_node(void* data)
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
void* remove_node(void* p_data)
{
    // Removing a node from the linked list
        
        node* temp;
        void* temp_data = NULL;
        temp = _search(p_data);
        
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
            temp_data = temp->data;
            free(temp);
            
        }

    return temp_data;  
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
            display_node_fptr(temp->data);
            temp = temp->next;
        }
    }
}

/*
 * initialize display function pointer
 */

int init_link_list( display_node_fptr_type _display_node_fptr,
        compare_node_fptr_type _compare_node_fptr)
{
    if(!_display_node_fptr || !_compare_node_fptr)
        return 0;
    
    display_node_fptr = _display_node_fptr;
    compare_node_fptr = _compare_node_fptr;
    return 1;
}

/*
 * search
 */
int search(void* p_data)
{
    return ( _search(p_data) && 1 );
}

/*
 * add_node_after
 */
int add_node_after(void* after, void* data)
{
    node* temp = _search(after);
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
node* _search(void* p_data)
{
    node* temp;
    temp = head;
    
    while(temp)
    {
        if(!compare_node_fptr(p_data,temp->data))
        { 
            break;
        }
        temp = temp->next;
    }
    
    return temp;
}

/*
 * remove head
 */
void* remove_head()
{
    void* data ;
    if(head == NULL)
    {
        printf("The linked list is empty.");
        data = NULL;
    }
    else if(head->next == NULL)
    {
        data = head->data;
        free(head);
    }
    else
    {
        node* temp;
        temp = head;
        head = temp->next;
        head->prev = NULL;
        data = temp->data;
        free(temp);
    }
    return data;
}

/*
 * remove tail
 */
void* remove_tail()
{
    void* data;
    if(head == NULL)
    {
        printf("The linked list is empty.");
        data = NULL;
    }
    else
    {
        node* temp;
        temp = tail;
        tail = temp->prev;
        tail->next = NULL;
        data = temp->data;
        free(temp);
    }
    return data;
}