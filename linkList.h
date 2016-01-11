#include <stdio.h>
#include <stdlib.h>

#ifndef __LINKLIST_H_
#define __LINKLIST_H_ 



typedef void (*ElementProcessor)(void *);

typedef struct element{
	void *data;
	struct element *next;
}Element;

typedef struct linklist{
	struct element *first;
	struct element *last;
	int length;
}LinkedList;

LinkedList createList(void);

int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void forEach(LinkedList, ElementProcessor e);

#endif