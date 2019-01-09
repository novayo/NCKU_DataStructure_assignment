#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX_EDGES 99

typedef struct struct_edge{
	int start;
	int end;
	int weight;
}edge_t;

typedef struct struct_graph
{
	int num_of_vertex, num_of_edge;
    edge_t edge[MAX_EDGES];
}graph_t;

typedef struct struct_subset
{
	int root;
    int rank;
}subset_t;

int weighFind(subset_t subset[], int i);
void simpleUnion(subset_t subset[], int x, int y);
void Sollin(graph_t graph);

int main() {
	graph_t graph;
	char input[50];
	char *tmp;
	char *delim = " ";

	scanf("%d%*c", &graph.num_of_edge);
	graph.num_of_vertex = graph.num_of_edge;

    for(int i=0;i<graph.num_of_edge;i++){
		scanf("%[^\n]%*c", &input);
		tmp = strtok(input,delim);
		graph.edge[i].start = atoi(tmp);

		tmp = strtok(NULL,delim);
		graph.edge[i].end = atoi(tmp);

		tmp = strtok(NULL,delim);
		graph.edge[i].weight = atoi(tmp);
	}
	puts("");
	Sollin(graph); 
	return 0;
}

int weighFind(subset_t subset[], int i){
	if (subset[i].root != i) subset[i].root = weighFind(subset, subset[i].root);
	return subset[i].root;
}

void simpleUnion(subset_t subset[], int x, int y) {
	if (subset[weighFind(subset, x)].rank < subset[weighFind(subset, y)].rank) subset[weighFind(subset, x)].root = weighFind(subset, y);
	else if (subset[weighFind(subset, x)].rank > subset[weighFind(subset, y)].rank) subset[weighFind(subset, y)].root = weighFind(subset, x);
	else {
		subset[weighFind(subset, y)].root = weighFind(subset, x);
		subset[weighFind(subset, x)].rank++;
	}
}

void Sollin(graph_t graph) {
	subset_t subset[graph.num_of_vertex];
	int tmp_subset[graph.num_of_vertex];
	for (int i=0; i < graph.num_of_vertex; ++i) {
		subset[i].root = i;
		subset[i].rank = 0;
		tmp_subset[i] = -1;
	}

	int num_of_tree = graph.num_of_vertex;
	while (num_of_tree > 1) {
		for (int i=0; i < graph.num_of_vertex; ++i) {
			tmp_subset[i] = -1;
		}
		for (int i=0; i<graph.num_of_edge; i++) {
			int set1 = weighFind(subset, graph.edge[i].start);
			int set2 = weighFind(subset, graph.edge[i].end);
			if (set1 == set2) continue;
			else {
				if (tmp_subset[set1] == -1 || graph.edge[tmp_subset[set1]].weight > graph.edge[i].weight) tmp_subset[set1] = i;
				if (tmp_subset[set2] == -1 || graph.edge[tmp_subset[set2]].weight > graph.edge[i].weight) tmp_subset[set2] = i;
			}
		}

		for (int i=0; i<graph.num_of_vertex; i++) {
			if (tmp_subset[i] != -1) {
				int set1 = weighFind(subset, graph.edge[tmp_subset[i]].start);
				int set2 = weighFind(subset, graph.edge[tmp_subset[i]].end);
				if (set1 == set2) continue;
				printf("%d %d %d\n", graph.edge[tmp_subset[i]].start,
									 graph.edge[tmp_subset[i]].end,
									 graph.edge[tmp_subset[i]].weight);
				simpleUnion(subset, set1, set2);
				num_of_tree--;
			}
		}
	}
	return;
}