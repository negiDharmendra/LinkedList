LinkedList

is a data type that holds the first and last element of a linked list(head and tail). It may also contain the number of elements in that list.


LinkedList createList(void);

create an empty LinkedList structure.


int add_to_list(LinkedList *,void *);

Given a reference to some data, add it to list. For now, add it to the end of the list. 


void *get_first_element(LinkedList list);

This function returns the first element in the list. 


void *get_last_element(LinkedList list);

This function returns the first element in the list. 


void forEach(LinkedList, ElementProcessor e)

where ElementProessor is a function pointer type with the following signature: 


void (*ElementProcessor)(void *)

Write a generic traverse function that can go through a list and process each element.