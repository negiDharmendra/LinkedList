#include <stdio.h>
#include <stdlib.h>

#ifndef __LINKLIST_H_
#define __LINKLIST_H_ 

typedef int(*MatchFunc)(void*,void*);
typedef void(*ElementProcessor)(void *);
typedef void(*ConvertFunc)(void*,void*,void*);
typedef void(*Reducer)(void* hint, void* previousItem, void* item);

typedef struct element{
	int index;
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
int insert_in_begining(LinkedList *,void *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void forEach(LinkedList, ElementProcessor e);
void * getElementAt(LinkedList, int );
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList *, int);
int asArray(LinkedList, void **, int);
LinkedList  filter(LinkedList, MatchFunc, void * );
LinkedList map(LinkedList, ConvertFunc, void * );
LinkedList reverse(LinkedList src);
void * reduce(LinkedList, Reducer, void *hint, void *initialValue);
#endif