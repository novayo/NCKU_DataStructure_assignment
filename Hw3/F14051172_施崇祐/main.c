/*
	Try Lined list first	

 */

#include <stdio.h>
#include <stdlib.h>

typedef struct struct_deque* deque;
struct struct_deque{
	int data;
	deque next;
	deque pre;
};

int main(){
	// create first node
	deque head = malloc(sizeof(*head));

	int i = 10;
	head->data = i;
	head->next == NULL;
	head->pre == NULL;
	printf("%d", head->data); 

	// create front and back point to next and pre
	
	free(head);
	return 0;
}
