#include <assert.h>
#include "linkList.h"
#define  TYPEINT *(int*)
#define  TYPECHAR *(char*)

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

void increment(void *data){
	++(TYPEINT(data));
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