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
	e->index = list->length;
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

void * getElementAt(LinkedList list, int index){
	Element *element = list.first;
	while(element){
		if(element->index == index)
				return element->data;
		element=element->next;
	};
	return NULL;
};

int indexOf(LinkedList list, void *data){
	Element *element = list.first;
	while(element){
		if(element->data == data)
				return element->index;
		element=element->next;
	};
	return -1;
};

void decrementIndex(Element *element){
	while(element){
		element->index--;
		element=element->next;
	};
};

void incrementIndex(Element *element){
	while(element){
		element->index++;
		element=element->next;
	};
}

void *deleteAtFirst(LinkedList *list){
	Element *element = list->first;
	void * deletedElement = element->data;
	list->first = element->next;
	free(element);
	decrementIndex(list->first);
	return deletedElement;
};



void * deleteElementAt(LinkedList *list, int index){
	Element *element = list->first;
	void * deletedElement = NULL;
	if(index==0)  return deleteAtFirst(list);
	Element *prevElement = list->first;
	while(element){
		if(element->index == index){
			prevElement->next = element->next;
			deletedElement = element->data;
	 		decrementIndex(element);
	 		free(element);
	 		if(index==(list->length-1)) list->last = prevElement;
	 		return deletedElement;
		}
	 	prevElement = element;
		element=element->next; 	
	}
	return deletedElement;
};


int asArray(LinkedList list, void ** arr, int maxElements){
	Element *element = list.first;
	size_t i = 0; 
	for (i = 0; i < list.length && i < maxElements; ++i){
		arr[i] = element->data;
		element=element->next; 
	}
	return i;
}


LinkedList filter(LinkedList src, MatchFunc match, void *hint){
	LinkedList list = createList();
	Element *element = src.first;
	while(element){
		if(match(hint,element->data))
			add_to_list(&list,element->data);
		element=element->next;
	}
	return list;
};

int insert_in_begining(LinkedList *list,void *data){
	Element *e = (Element *)malloc(sizeof(Element));
	e->data = data;
	e->next = NULL;
	e->index = 0;
	if(is_empty(list))
		list->last = e;
	else
		e->next = list->first;
	list->first = e;
	incrementIndex(list->first->next);
	return ++list->length;
};


LinkedList reverse(LinkedList src){
	LinkedList list = createList();
	Element *element = src.first;
	while(element){
		insert_in_begining(&list,element->data);
		element=element->next;
	};
	return list;
};


LinkedList map(LinkedList src, ConvertFunc convert, void *hint ){
	Element *element = src.first;
	LinkedList list = src;
	Element *e = list.first;
	while(element){
		convert(hint,element->data,e->data);
		e=e->next;
		element=element->next;
	};
	return list;
}


