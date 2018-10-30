#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PLUS 1
#define MINUS 1
#define MULTI 2
#define DIVIDE 2
#define BRACKET 0

int main(){
	while(1){
		char input[100] = "";
		char ans[100] = "";
		int stack_symbol[100] = {'\0'};
		int top_stack_symbol = 0;
		int top_ans = 0;
		scanf("%[^\n]%*c", &input);
		int len_input = strlen(input);
		if(!strcmp(input, "q")) break;

		while(--len_input){
			if((input[len_input] - '0') < 10 && (input[len_input] - '0' > -1)){
				// input number -> stack to ans
				char frag_int[100] = {'\0'};
				int i=0;
				while(input[len_input] != ' '){
					char tmp[50] = {'\0'};
					tmp[0] = input[len_input--];
					strcat(tmp, frag_int);
					strcpy(frag_int, tmp);
				}
				ans[top_ans] = atoi(frag_int);
				top_ans++;
			} else{
				int symbol = -1;
				if(input[len_input] == "+"){
					symbol = PLUS;
				} else if(input[len_input] == "-"){
					symbol = MINUS;
				} else if(input[len_input] == "*"){
					symbol = MULTI;
				} else if(input[len_input] == "/"){
					symbol = DIVIDE;
				}
				
				if(symbol > stack_symbol[top_stack_symbol]){
					// stack
				} else{
					// pop first and stack
					// maybe pop twice, so have to check > stack again
				}
			}
		}	
	}
	return 0;
}
