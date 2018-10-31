/* Only bug in BRACKET stack */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MULTI -1
#define DIVIDE -2
#define PLUS -11
#define MINUS -12
#define LBRACKET 998
#define RBRACKET 999

int main(){
	while(1){
		char input[100] = "";
		int ans[100] = {'\0'};
		int stack_symbol[100] = {-999};
		int top_stack_symbol = 0;
		int top_ans = 0;
		scanf("%[^\n]%*c", &input);
		int len_input = strlen(input);
		if(!strcmp(input, "q")) break;

		while(1){
			if(--len_input == -1) break;
			else if(input[len_input] == ' ') continue;
			if(((input[len_input] - '0') < 10) && (input[len_input] - '0' > -1)){
				char frag_int[100] = {'\0'};
				int i=0;
				char tmp[10] = {'\0'};
				while(input[len_input] != ' '){
					if(len_input == 0){
						tmp[0] = input[len_input];
						strcat(tmp, frag_int);
						strcpy(frag_int, tmp);
						break;
					} else{
						tmp[0] = input[len_input--];
					}
					strcat(tmp, frag_int);
					strcpy(frag_int, tmp);
				}
				ans[top_ans++] = atoi(frag_int);
			} else{
				int symbol = -1;
				if(input[len_input] == '+'){
					symbol = PLUS;
				} else if(input[len_input] == '-'){
					symbol = MINUS;
				} else if(input[len_input] == '*'){
					symbol = MULTI;
				} else if(input[len_input] == '/'){
					symbol = DIVIDE;
				} else if(input[len_input] == '('){
					symbol = LBRACKET;
				} else if(input[len_input] == ')'){
					symbol = RBRACKET;
				}

				while(1){
					if(top_stack_symbol == 0 && symbol != LBRACKET){
						stack_symbol[top_stack_symbol++] = symbol;
						break;
					}
					if(symbol == LBRACKET){
	top_stack_symbol--;
						if(stack_symbol[top_stack_symbol] == RBRACKET){
							stack_symbol[top_stack_symbol] = -999;
							break;
						}
						ans[top_ans++] = stack_symbol[top_stack_symbol];
						stack_symbol[top_stack_symbol] = -999;
					} else if(symbol == RBRACKET || symbol > stack_symbol[top_stack_symbol-1] || (stack_symbol[top_stack_symbol-1] == RBRACKET) || abs(symbol-stack_symbol[top_stack_symbol-1]) == 1){
						stack_symbol[top_stack_symbol++] = symbol;
						break;
					} else{
						ans[top_ans++] = stack_symbol[--top_stack_symbol];
						stack_symbol[top_stack_symbol] = -999;
					}
				}
			}
		}	
		while(top_stack_symbol != 0){
			ans[top_ans++] = stack_symbol[--top_stack_symbol];
		}
		// printf ans out
		while(1){
			if(--top_ans == -1) break;
			else if(ans[top_ans] >= 0) printf("%d", ans[top_ans]);
			else if(ans[top_ans] == -1) printf("*");
			else if(ans[top_ans] == -2) printf("/");
			else if(ans[top_ans] == -11) printf("+");
			else if(ans[top_ans] == -12) printf("-");
		}
		printf("\n");
	}
	return 0;
}
