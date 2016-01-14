#LinkedList

LinkList is a data type that holds the first and last element of a linked list. It also contain the number of elements in that list.


####LinkedList createList(void);

create an empty LinkedList structure.


####int add_to_list(LinkedList *,void *);

Given a reference to some data, add it to list. For now, add it to the end of the list. 


####void *get_first_element(LinkedList list);

This function returns the first element in the list. 


####void *get_last_element(LinkedList list);

This function returns the last element in the list. 


####void forEach(LinkedList, ElementProcessor e)

where ElementProessor is a function pointer type with the following signature: 
##### void (*ElementProcessor)(void *)

A generic traverse function that can go through a list and process each element.


#### int insert_in_begining(LinkedList *,void *);

Given a reference to some data, add it to begining of the list. 

#### void * getElementAt(LinkedList, int );

Given an index as an integer, return the data reference contained at that position in the list. 

#### int indexOf(LinkedList, void *);

Given an element, find the first index at which this element occurs in a list. Return -1 if not found.

#### void * deleteElementAt(LinkedList *, int);

Given an index, delete the element at that list. Return the data referenced by the node at that position. 

#### int asArray(LinkedList, void **, int);

Given a linked list and a reference to an array, this function will populate the array with all the elements of a list(or maxElements, whichever is smaller) and finally return the number of elements added to the array. Each element of the array will contain a reference to each piece of data in the linked list.


#### LinkedList  filter(LinkedList, MatchFunc, void * );

where the signature of the MatchFunc is:
##### int MatchFunc(void* hint, void* item);

#### LinkedList reverse(LinkedList src);

This function will take a LinkedList as an argument and return a LinkedList with the order of the elements of the source LinkedList reversed. It does not modify the existing LinkedList.

#### LinkedList map(LinkedList, ConvertFunc, void * );

where the signature of the ConvertFunc is:
#####void ConvertFunc(void* hint, void* sourceItem, void* destinationItem);

#### void * reduce(LinkedList, Reducer, void *hint, void *initialValue);

where the signature of Reducer is:
#####void* Reducer(void* hint, void* previousItem, void* item);
