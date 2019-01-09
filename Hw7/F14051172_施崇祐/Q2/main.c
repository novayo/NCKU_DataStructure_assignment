#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct node *nodePointer;
typedef struct node{
	int vertex;
	nodePointer link;
}node;
typedef struct hdnodes{
	int count;
	nodePointer link;
}hdnodes;

void topSort(hdnodes graph[MAX], int n, int ee[MAX], int input[100][4]){
	int i, j, k, top;
	nodePointer ptr;
	top = -1;
	for (i = 0; i < n; i++){
		if (graph[i].count == 0){
			graph[i].count = top;
			top = i;
		}
	}
	for (i = 0; i < n; i++){
		if (top == -1){
			break;
		}
		else{
			j = top;
			top = graph[top].count;
			for (ptr = graph[j].link; ptr; ptr = ptr->link){
				k = ptr->vertex;
				int m;
				for (m = 0; m < n; m++){
					if (input[m][1] == j&&input[m][2] == k){
						break;
					}
				}
				if (ee[k] < ee[j] + input[m][3]){
					ee[k] = ee[j] + input[m][3];
				}
				graph[k].count--;
				if (graph[k].count == 0){
					graph[k].count = top;
					top = k;
				}
			}
		}
	}
}

int main(void){
	int active_num, i, input[100][4], j, cnt = 0;
	scanf("%d", &active_num);
	for (i = 0; i < active_num; i++)
		for (j = 0; j < 4; j++)
			scanf(" %d", &input[i][j]);
	hdnodes graph[MAX];
	for (i = 0; i < active_num; i++){
		for (j = 0; j < active_num; j++){
			if (input[j][2] == i){
				cnt++;
			}
		}
		graph[i].count = cnt;
		cnt = 0;
	}
	for (i = 0; i < active_num; i++){
		graph[i].link = NULL;
	}

	for (i = 0; i < active_num; i++){
		int con = 0;
		nodePointer  temp_node = (nodePointer)malloc(sizeof(node));
		temp_node->vertex = input[i][2];
		temp_node->link = NULL;
		int a = input[i][1];
		nodePointer  temp = (nodePointer)malloc(sizeof(node));
		nodePointer  temp_prv = (nodePointer)malloc(sizeof(node));
		for (temp = graph[a].link; temp != NULL; temp = temp->link){
			con = 1;
			temp_prv = temp;
		}
		if (con == 1){
			temp_prv->link = temp_node;
		}
		if (con == 0){
			graph[a].link = temp_node;
		}
	}
	int asd = input[0][2];
	for (i = 1; i < active_num; i++){
		if (input[i][2] > asd){
			asd = input[i][2];
		}
	}
	int ee[MAX] = { 0 };
	for (i = 0; i <= asd; i++){
		int end = input[i][2];
		int start = input[i][1];
		ee[end] = ee[start] + input[i][3];
	}
	topSort(graph, active_num, ee, input);
	int l[MAX] = { 0 };
	l[asd] = ee[asd];
	int t, c = 0;
	for (i = asd - 1; i >= 0; i--){
		t = -1;
		c = 0;
		for (j = 0; j < active_num; j++){
			if (input[j][1] == i){
				c = 1;
				l[i] = l[input[j][2]] - input[j][3];
				if (t != -1){
					if (t < l[i]){
						l[i] = t;
					}
				}
			}
			if (c == 1){
				t = l[i];
			}
		}
	}
	int a_ee[MAX] = { 0 }, tt[MAX] = { 0 }, s[MAX] = { 0 };
	char cc[MAX];
	int count1 = 0;
	int st, en;
	for (i = 1; i <= active_num; i++){
		st = input[i - 1][1];
		a_ee[i] = ee[st];
	}
	for (i = active_num; i > 0; i--){
		en = input[i - 1][2];
		tt[i] = l[en] - input[i - 1][3];
	}
	for (i = 1; i <= active_num; i++){
		s[i] = tt[i] - a_ee[i];
		if (s[i] == 0){
			cc[i] = 'Y';
		}
		else{
			cc[i] = 'N';
		}
	}
	printf("\n\n");
	printf("a   e   t   s   c\n");
	for (i = 1; i <= active_num; i++){
		printf("%-4d%-4d%-4d%-4d%-4c\n", i, a_ee[i], tt[i], s[i], cc[i]);
	}
	system("pause");
	return 0;
}