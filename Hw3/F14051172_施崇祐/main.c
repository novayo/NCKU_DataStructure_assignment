#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct struct_deque{
	int data;
	struct struct_deque* next;
	struct struct_deque* pre;
}deque;

deque* create(deque* node, char* str, int input);

int main(){
	// create head node
	deque* head = malloc(sizeof(head));
	head->data = -1;
	head->next = NULL;
	head->pre = NULL;

	int i = 0;
	char input[20] = "";
	char frag_str[11] = "";
	int frag_int = -1;
	while(1){
		frag_int = -1;
		memset(input, 0, 20);
		memset(frag_str, 0, 11);
		scanf("%[^\n]%*c", input);

		// Get word and number
		for(i=0; i<strlen(input); ++i){
			if(input[i] == ' ') break;
			frag_str[i] = input[i];
		}
		frag_str[i] = '\0';

		if(i != strlen(input)){
			int j = 1;
			char tmp_frag_int[10] = "";
			memset(tmp_frag_int, 0, 10);
			for(j=1; j<10; ++j){
				if((i+j) == strlen(input)) break;
				tmp_frag_int[j-1] = input[i+j];
			}
			frag_int = atoi(tmp_frag_int);
		}

		if(!strcmp(frag_str, "show")) 
			break;
		else 
			head = create(head, frag_str, frag_int);
	}

	// print out
	deque* tmp = malloc(sizeof(tmp));
	tmp = head;
	while(tmp->pre != NULL) 
		tmp = tmp->pre;
	while(tmp->next != NULL){
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->next);
	return 0;
}

deque* create(deque* node, char* str,int input){
	if(node->data == -1 && (!strcmp(str, "push_front") || !strcmp(str, "push_back") || !strcmp(str, "pop_back") || !strcmp(str, "pop_back"))){
		node->data = input;
		node->next = NULL;
		node->pre = NULL;
		return node;
	}
	deque* new = malloc(sizeof(new));
	deque* tmp = malloc(sizeof(tmp));
	tmp = node;
	new->data = input;
	if(!strcmp(str, "push_back")){
		new->next = NULL;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->pre = tmp;
	} else if(!strcmp(str, "push_front")){
		new->pre = NULL;
		while(tmp->pre != NULL)
			tmp = tmp->pre;
		tmp->pre = new;
		new->next = tmp;
	} else if(!strcmp(str, "pop_back")){
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->pre->next = NULL;
		tmp->pre = NULL;
		free(tmp);
	} else if(!strcmp(str, "pop_front")){
		while(tmp->pre != NULL)
			tmp = tmp->pre;
		tmp->next->pre = NULL;
		tmp->next = NULL;
		free(tmp);
	} else{
		printf("Unknown parameters\n");
	}
	return node;
}
