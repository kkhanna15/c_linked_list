/* 
 * File:   linked_list.h
 * Author: kanvikhanna
 *
 * Created on September 26, 2015, 9:41 AM
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



#endif	/* LINKED_LIST_H */

