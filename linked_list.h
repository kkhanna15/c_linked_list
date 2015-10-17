/* 
 * File:   linked_list.h
 * Author: kanvikhanna
 * Version 1.0
 * Created on September 26, 2015, 9:41 AM
 * 
 * Implements a basic linked-list and provides standard operations such as
 * adding, removing a node.
 */

#ifndef LINKED_LIST_H
#define	LINKED_LIST_H

/*
 * The add_node function is used to add a new node to the end of the 
 * linked list. It takes the data as input and provides the status as output.
 * The status is 1, if the node was added successfully and 0, otherwise.
 */

int add_node(int data);

/*
 * The remove_node function is used to remove a node to the linked list.
 * It take the data as input and provides the status as output. The 
 * status is 1, if the node was removed successfully and 0, otherwise.
 */

int remove_node(int data);

/*
 * The traverse function is used to traverse the linked list and print it.
 */

void traverse(void);

/*
 * The search function is used to search a node in the linked list.
 * It take the data as input and provides the status as output. The 
 * status is 1, if the node was found and 0, otherwise.
 */

int search(int data);

/*
 * The add_node_after function is used to add a node to the linked list 
 * after a given node. It takes the data and after as input and provides 
 * the status as output. The status is 1, if the node was added successfully 
 * and 0, otherwise.
 */

int add_node_after(int after, int data);

/**
 * The remove_head function is used to remove the head node of the linked list
 * and assign the next node as the head. It returns the data as output, if the
 *  head was removed and 0, otherwise.
 */

int remove_head();

/**
 * The remove_tail function is used to remove the head node of the linked list
 * and assign the previous node as the tail. It returns the data as output, if 
 * the tail was removed and 0, otherwise.
 */

int remove_tail();

#endif	/* LINKED_LIST_H */

