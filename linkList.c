#include "linkList.h"

LinkedList createList(void){
	LinkedList list;
	list.first = NULL;
	list.last = NULL;
	list.length = 0;
return list;
}

int is_empty(LinkedList *list){
	return (list->length==0);
}

int add_to_list(LinkedList *list,void *data){
	Element *e = (Element *)malloc(sizeof(Element));
	e->data = data;
	e->next = NULL;
	if(is_empty(list))
		list->first = list->last = e;
	else
		list->last=list->last->next= e; 
	return ++list->length;
};

void *get_first_element(LinkedList list){
	if(list.first)
		return list.first->data;
	return NULL;
};

void *get_last_element(LinkedList list){
	if(list.last)
		return list.last->data;
	return NULL;
};

void forEach(LinkedList list, ElementProcessor e){
	Element *element = list.first;
	while(element){
		e(element->data);
		element=element->next;
	};
};