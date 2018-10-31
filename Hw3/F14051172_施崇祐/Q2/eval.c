#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char input[100] = "";
	int ans[100] = {'\0'}; // for stack
	int top = 0;

	while(1){
		scanf("%[^\n]%*c", &input);
		int len_input = strlen(input);
		if(!strcmp(input, "q")) break;

		while(--len_input >= 0){
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
				ans[top] = atoi(frag_int);
				top++;
			} else{
				// input symbol -> pop ans
				top--;
				int tmp1 = ans[top];
				int tmp2 = ans[top-1];
				if(input[len_input] == '+'){
					ans[top-1] = tmp1 + tmp2;
				} else if(input[len_input] == '-'){
					ans[top-1] = tmp1 - tmp2;
				} else if(input[len_input] == '*'){
					ans[top-1] = tmp1 * tmp2;
				} else if(input[len_input] == '/'){
					ans[top-1] = tmp1 / tmp2;
				}
				ans[top] = '\0';
				len_input--;
			}
		}
		printf("%d\n", ans[0]);
		top = 0;
		ans[0] = '\0';
	}
	return 0;
}
