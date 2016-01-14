#include <assert.h>
#include "linkList.h"
#define  TYPEINT *(int*)
#define  TYPECHAR *(char*)

LinkedList get_initalized_list_for_testing(){
	LinkedList list = createList();
	void *data_1 = malloc(sizeof(int));
	TYPEINT(data_1) = 23;
	void *data_2 = malloc(sizeof(int));
	TYPEINT(data_2) = 66;
	void *data_3 = malloc(sizeof(int));
	TYPEINT(data_3) = 45;
	void *data_4 = malloc(sizeof(int));
	TYPEINT(data_4) = 56;
	add_to_list(&list,data_1);
	add_to_list(&list,data_2);
	add_to_list(&list,data_3);
	add_to_list(&list,data_4);
	return list;
};


void inspect_the_list_elements(LinkedList list){
	Element *e = list.first;
	while(e){
		printf("%d\n",TYPECHAR(e->data));
		e=e->next;
	}
}

void free_memory_elements_of_the_list_(LinkedList *list){
	Element *e = list->first;
	while(e){
		free(e->data);
		e=e->next;
	};
};

int isEven(void* hint, void* item){
	int num = *((int*)item);
	return (num%2==0);
};

void increment(void *data){
	++(TYPEINT(data));
};

void add(void* hint, void* source, void* destination){
	TYPEINT(destination) = TYPEINT(source) + TYPEINT(hint) ;
};

void* sum(void* hint, void* previousItem, void* item){
	TYPEINT(previousItem) = TYPEINT(item) + TYPEINT(previousItem) ;
	return previousItem;
};

//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//

void test_createList(){
	LinkedList list = createList();
	assert(list.first==NULL);
	assert(list.last==NULL);
	assert(list.length==0);
};

void test_add_to_list(){
	LinkedList list = createList();
	void *data = malloc(sizeof(int));
	TYPEINT(data) = 23;
	assert(add_to_list(&list,data)==1);
	assert(add_to_list(&list,data)==2);
	assert(TYPEINT(list.first->data)==23);
	assert(TYPEINT(list.last->data)==23);
	assert(list.length==2);
};
void test_get_first_element(){
	LinkedList list = createList();
	int num = 23;
	void *data_1 = &num;
	char character = 65;
	void *data_2 =&character;
	assert(add_to_list(&list,data_1)==1);
	assert(add_to_list(&list,data_2)==2);
	assert(TYPEINT(get_first_element(list))==23);
};

void test_get_first_element_for_Empty_List(){
	LinkedList list = createList();
	assert((get_first_element(list))==NULL);
	assert((get_last_element(list))==NULL);
}

void test_get_last_element(){
	LinkedList list = createList();
	int num = 23;
	void *data_1 = &num;
	char character = 65;
	void *data_2 =&character;
	assert(add_to_list(&list,data_1)==1);
	assert(add_to_list(&list,data_2)==2);
	assert(TYPECHAR(get_last_element(list))==65);
};


void test_forEach(){
	LinkedList list = createList();
	int num = 23;
	void *data_1 = &num;
	char character = 65;
	void *data_2 =&character;
	add_to_list(&list,data_1);
	add_to_list(&list,data_2);
	forEach(list,&increment);
	assert(TYPEINT(get_first_element(list))==24);
	assert(TYPECHAR(get_last_element(list))==66);
};

void test_getElementAt(){
	LinkedList list = createList();
	int num = 23;
	void *data_1 = &num;
	char character = 65;
	void *data_2 =&character;
	add_to_list(&list,data_1);
	add_to_list(&list,data_2);
	assert(TYPEINT(getElementAt(list,0))==23);
	assert(TYPECHAR(getElementAt(list,1))==65);
};


void test_indexOf(){
	LinkedList list = createList();
	int num = 23;
	void *data_1 = &num;
	char character = 65;
	void *data_2 =&character;
	add_to_list(&list,data_1);
	add_to_list(&list,data_2);
	assert(indexOf(list,data_1)==0);
	assert(indexOf(list,data_2)==1);
};


void test_deleteElementAt_when_element_is_on_first(){
	LinkedList list = createList();
	int num = 23;
	void *data_1 = &num;
	char character = 65;
	void *data_2 =&character;
	int val = 45;
	void *data_3 = &val;
	add_to_list(&list,data_1);
	add_to_list(&list,data_2);
	add_to_list(&list,data_3);
	assert(TYPEINT(deleteElementAt(&list,0))==23);
	assert(TYPECHAR(getElementAt(list,0))==65);
	assert(TYPEINT(getElementAt(list,1))==45);
};


void test_deleteElementAt_when_element_is_in_middle(){
	LinkedList list = createList();
	int num = 23;
	void *data_1 = &num;
	char character = 65;
	void *data_2 =&character;
	int val = 45;
	void *data_3 = &val;
	add_to_list(&list,data_1);
	add_to_list(&list,data_2);
	add_to_list(&list,data_3);
	assert(TYPECHAR(deleteElementAt(&list,1))==65);
	assert(TYPECHAR(getElementAt(list,0))==23);
	assert(TYPECHAR(getElementAt(list,1))==45);
};


void test_deleteElementAt_when_element_is_last(){
	LinkedList list = createList();
	int num = 23;
	void *data_1 = &num;
	char character = 65;
	void *data_2 =&character;
	int val = 45;
	void *data_3 = &val;
	add_to_list(&list,data_1);
	add_to_list(&list,data_2);
	add_to_list(&list,data_3);
	assert(TYPECHAR(deleteElementAt(&list,2))==45);
	assert(TYPECHAR(getElementAt(list,0))==23);
	assert(TYPECHAR(getElementAt(list,1))==65);
};

void test_deleteElementAt_when_not_found(){
	LinkedList list = createList();
	int num = 23;
	void *data_1 = &num;
	char character = 65;
	void *data_2 =&character;
	int val = 45;
	void *data_3 = &val;
	add_to_list(&list,data_1);
	add_to_list(&list,data_2);
	add_to_list(&list,data_3);
	assert(deleteElementAt(&list,4)==NULL);
};

void test_asArray_populates_a_array_from_list(){
	LinkedList list = get_initalized_list_for_testing();
	int length = 4;
	void *array[length];
	assert(asArray(list,array,length)==4);
	assert(TYPECHAR(array[0])==23);
	assert(TYPECHAR(array[1])==66);
	assert(TYPECHAR(array[2])==45);
	assert(TYPECHAR(array[3])==56);
	free_memory_elements_of_the_list_(&list);
};



void test_filter_isEven(){
	LinkedList list = get_initalized_list_for_testing();
	LinkedList filtered_list =filter(list,isEven,NULL);
	assert(TYPEINT(filtered_list.first->data)==66);
	assert(TYPEINT(filtered_list.last->data)==56);
	assert(filtered_list.length==2);
	free_memory_elements_of_the_list_(&list);
};

void test_reverse_should_give_the_reverse_list_of_the_list_and_not_change(){
	LinkedList list = get_initalized_list_for_testing();
	LinkedList reverse_list = reverse(list);
	assert(TYPECHAR(list.first->data)==23);
	assert(TYPECHAR(reverse_list.first->data)==56);
	assert(TYPECHAR(reverse_list.last->data)==23);
	assert(reverse_list.length==4);
	free_memory_elements_of_the_list_(&list);
};

void test_map_should_map_all_elements_to_increment_it_by_2(){
	LinkedList list = get_initalized_list_for_testing();
	int increment = 2;
	int *hint = &increment;
	LinkedList new_list = map(list,add,hint);
	assert(TYPECHAR(list.first->data)==23);
	assert(TYPECHAR(new_list.first->data)==25);
	assert(TYPECHAR(new_list.last->data)==58);
	assert(new_list.length==4);
	free_memory_elements_of_the_list_(&list);
};

void test_reduce_should_reduce_the_list_and_give_some_of_list(){
	LinkedList list = get_initalized_list_for_testing();
	int add = 2;
	int *hint = &add;
	int init = 0;
	void *initialValue =&init;
	void *result = reduce(list,sum,hint,initialValue);
	assert(190==TYPEINT(result));
	free_memory_elements_of_the_list_(&list);
};