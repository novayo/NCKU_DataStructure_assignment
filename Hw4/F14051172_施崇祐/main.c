#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE  25
typedef enum {head,entry} tagfield;
typedef struct MatrixNode *MatrixPointer;
struct EntryNode {
	int row;
	int col;
	int value;
};
struct MatrixNode {
	MatrixPointer down;
	MatrixPointer right;
	tagfield tag;
	union {
		MatrixPointer next;
		struct EntryNode entry;
	} u;
};

MatrixPointer HdNode[MAX_SIZE][MAX_SIZE];
MatrixPointer mread(void);
MatrixPointer mtranspose(void);
void mwrite(MatrixPointer);
void merase(MatrixPointer *node);
int NumRows, NumCols,  NumEntries, NumHeads, Vars;

int main()
{
	MatrixPointer a, b;
	a = mread();
	mwrite(a);
	b = mtranspose();
	printf("\n\n");
	mwrite(b);

	merase(&a);
	merase(&b);

	return 0;
}

MatrixPointer mtranspose(void){
	MatrixPointer node, temp, last, tmp;
	int CurrentRow, row, col, value, i;

	// set H
	node = (MatrixPointer)malloc(sizeof(struct MatrixNode));
	node->tag = entry;
	node->u.entry.row = NumCols; // transpose number of row
	node->u.entry.col = NumRows; // transpose number of col

	if (!NumHeads)
		node->right = node;
	else {
		// set H0 ~ Hx
		for (i = 0; i < NumHeads; i++) {
			temp = (MatrixPointer)malloc(sizeof(struct MatrixNode));
			HdNode[Vars][i] = temp;
			HdNode[Vars][i]->tag = head;
			HdNode[Vars][i]->right = temp;
			HdNode[Vars][i]->u.next = temp;
		}

		NumHeads = (NumCols < NumRows) ? NumCols : NumRows;
		// Start to store
		CurrentRow = 0;
		last = HdNode[Vars][0];
		for (i = 0; i < NumHeads; i++) {
// printf("i = %d\n", i);
			for (tmp = HdNode[Vars-1][i]->down; tmp != HdNode[Vars-1][i]; tmp = tmp->down){
				row = tmp->u.entry.col;
				col = tmp->u.entry.row;
				value = tmp->u.entry.value;
// printf("Row = %d, Col = %d, Value = %d\n", row, col, value);
				// if input to next row -> point back to HdNode
				if (row > CurrentRow) {
					last->right = HdNode[Vars][CurrentRow]; 
					CurrentRow = row;
					last = HdNode[Vars][row];
				}

				// temp for input value
				temp = (MatrixPointer)malloc(sizeof(struct MatrixNode));
				temp->tag = entry;
				temp->u.entry.row = row;
				temp->u.entry.col = col;
				temp->u.entry.value = value;

				// add into row
				last->right = temp;
				last = temp;

				// add into col
				HdNode[Vars][col]->u.next->down = temp; 
				HdNode[Vars][col]->u.next = temp;
			}
		}
		// last point back to Hx
		last->right = HdNode[Vars][CurrentRow];

		// col point back to top
		for (i = 0; i < NumCols; i++)
			HdNode[Vars][i]->u.next->down = HdNode[Vars][i];

		// row point to left
		for (i = 0; i < NumHeads-1; i++)
			HdNode[Vars][i]->u.next = HdNode[Vars][i+1];
		HdNode[Vars][NumHeads-1]->u.next = node;
		node->right = HdNode[Vars][0];
	}
	Vars++;
	return node;
}


MatrixPointer mread(void){
	int row, col, value, CurrentRow, i;
	MatrixPointer temp,last,node;

	printf("Enter the number of {rows columns entries}: ");
	scanf("%d %d %d",&NumRows, &NumCols, &NumEntries);
	NumHeads = (NumCols > NumRows) ? NumCols : NumRows;

	// set H
	node = (MatrixPointer)malloc(sizeof(struct MatrixNode));
	node->tag = entry;
	node->u.entry.row = NumRows;
	node->u.entry.col = NumCols;

	if (!NumHeads)
		node->right = node;
	else {
		// set H0 ~ Hx
		for (i = 0; i < NumHeads; i++) {
			temp = (MatrixPointer)malloc(sizeof(struct MatrixNode));
			HdNode[Vars][i] = temp;
			HdNode[Vars][i]->tag = head;
			HdNode[Vars][i]->right = temp;
			HdNode[Vars][i]->u.next = temp;
		}

		// Start to store
		CurrentRow = 0;
		last = HdNode[Vars][0];
		for (i = 0; i < NumEntries; i++) {
			printf("Enter {row column value}: ");
			scanf("%d %d %d",&row,&col,&value);
			// if input to next row -> point back to HdNode
			if (row > CurrentRow) {
				last->right = HdNode[Vars][CurrentRow]; 
				CurrentRow = row;
				last = HdNode[Vars][row];
			}

			// temp for input value
			temp = (MatrixPointer)malloc(sizeof(struct MatrixNode));
			temp->tag = entry;
			temp->u.entry.row = row;
			temp->u.entry.col = col;
			temp->u.entry.value = value;

			// add into row
			last->right = temp;
			last = temp;

			// add into col
			HdNode[Vars][col]->u.next->down = temp; 
			HdNode[Vars][col]->u.next = temp;
		}
		// last point back to Hx
		last->right = HdNode[Vars][CurrentRow];

		// col point back to top
		for (i = 0; i < NumCols; i++)
			HdNode[Vars][i]->u.next->down = HdNode[Vars][i];

		// row point to left
		for (i = 0; i < NumHeads-1; i++)
			HdNode[Vars][i]->u.next = HdNode[Vars][i+1];
		HdNode[Vars][NumHeads-1]->u.next = node;
		node->right = HdNode[Vars][0];
	}
	Vars++;
	return node;
}	


void mwrite(MatrixPointer node){
	int i, zero;
	MatrixPointer temp;
	printf("Matrix: \n");
	for (i = 0; i < node->u.entry.row; i++){
		zero = 0;
		for (temp = HdNode[Vars-1][i]->right; temp != HdNode[Vars-1][i]; temp = temp->right){
			while(zero++ < temp->u.entry.col) printf("  0");
			printf("%3d", temp->u.entry.value);
		}
		while(zero++ < node->u.entry.col) printf("  0");
		printf("\n");
	}
}

void merase(MatrixPointer *node){
	int i, NumHeads;
	Vars--;
	MatrixPointer x,y;
	for (i = 0; i < (*node)->u.entry.row; i++) {
		y = HdNode[Vars][i]->right;
		while (y != HdNode[Vars][i]) {
			x = y;
			y = y->right;
			free(x);
		}
	}
	NumHeads = ((*node)->u.entry.row > (*node)->u.entry.col) ? (*node)->u.entry.row : (*node)->u.entry.col;
	for (i = 0; i < NumHeads; i++)
		free(HdNode[Vars][i]);

	*node = NULL;
}
