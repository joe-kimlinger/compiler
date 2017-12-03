#include "scratch.h"
#include <stdio.h>
#include <stdlib.h>

struct scratch_set *head = 0;

int scratch_alloc(){
	if (!head)
		head = scratch_create(0);
	int i;
	for (i = 0; i < 7; i++){
		if (!head->scratches[i]){
			head->scratches[i] = 1;
			return i;
		}
	}
	printf("codegen error: no free scratch registers\n");
	return -1;
}

struct scratch_set *scratch_create(struct scratch_set *n){
	struct scratch_set *s = malloc(sizeof(*s));
	int i;
	s->next = n;
	for (i = 0; i < 7; i++){
		s->scratches[i] = 0;
	}
	return s;
}

void scratch_push(){
	head = scratch_create(head);	
}

void scratch_pop(){
	struct scratch_set *s = head->next;
	free(head);
	head = s;
}

void scratch_free( int r ){
	head->scratches[r] = 0;
}

const char * scratch_name( int r ){
	switch (r){
		case 0:
			return "%rbx";
		case 1:
			return "%r10";
		case 2:
			return "%r11";
		case 3:
			return "%r12";
		case 4:
			return "%r13";
		case 5:
			return "%r14";
		case 6:
			return "%r15";
	}
	return NULL;
}

