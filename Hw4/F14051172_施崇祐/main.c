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
MatrixPointer HdNode[MAX_SIZE];
MatrixPointer tHdNode[MAX_SIZE];
MatrixPointer mread(void);
MatrixPointer mtranspose(void);
void mwrite(MatrixPointer);
void merase(MatrixPointer *node);
int NumRows, NumCols,  NumEntries, NumHeads;

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
			tHdNode[i] = temp;
			tHdNode[i]->tag = head;
			tHdNode[i]->right = temp;
			tHdNode[i]->u.next = temp;
		}

		// Start to store
		CurrentRow = 0;
		last = tHdNode[0];
		for (i = 0; i < NumHeads; i++) {
			for (tmp = HdNode[i]->right; tmp != HdNode[i]; tmp = tmp->right){
				row = tmp->u.entry.row;
				col = tmp->u.entry.col;
				value = tmp->u.entry.value;
				// if input to next row -> point back to HdNode
				if (row > CurrentRow) {
					last->right = tHdNode[CurrentRow]; 
					CurrentRow = row;
					last = tHdNode[row];
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
				tHdNode[col]->u.next->down = temp; 
				tHdNode[col]->u.next = temp;
			}
		}
		// last point back to Hx
		last->right = tHdNode[CurrentRow];

		// col point back to top
		for (i = 0; i < NumCols; i++)
			tHdNode[i]->u.next->down = tHdNode[i];

		// row point to left
		for (i = 0; i < NumHeads-1; i++)
			tHdNode[i]->u.next = tHdNode[i+1];
		tHdNode[NumHeads-1]->u.next = node;
		node->right = tHdNode[0];
	}
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
			HdNode[i] = temp;
			HdNode[i]->tag = head;
			HdNode[i]->right = temp;
			HdNode[i]->u.next = temp;
		}

		// Start to store
		CurrentRow = 0;
		last = HdNode[0];
		for (i = 0; i < NumEntries; i++) {
			printf("Enter {row column value}: ");
			scanf("%d %d %d",&row,&col,&value);
			// if input to next row -> point back to HdNode
			if (row > CurrentRow) {
				last->right = HdNode[CurrentRow]; 
				CurrentRow = row;
				last = HdNode[row];
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
			HdNode[col]->u.next->down = temp; 
			HdNode[col]->u.next = temp;
		}
		// last point back to Hx
		last->right = HdNode[CurrentRow];

		// col point back to top
		for (i = 0; i < NumCols; i++)
			HdNode[i]->u.next->down = HdNode[i];

		// row point to left
		for (i = 0; i < NumHeads-1; i++)
			HdNode[i]->u.next = HdNode[i+1];
		HdNode[NumHeads-1]->u.next =  node;
		node->right = HdNode[0];
	}
	return node;
}	


void mwrite(MatrixPointer node)
{
	int i, zero;
	MatrixPointer temp;
	printf("Matrix: \n");
	for (i = 0; i < node->u.entry.row; i++){
		zero = 0;
		for (temp = HdNode[i]->right; temp != HdNode[i]; temp = temp->right){
			while(zero++ < temp->u.entry.col) printf("  0");
			printf("%3d", temp->u.entry.value);
		}
		while(zero++ < node->u.entry.col) printf("  0");
		printf("\n");
	}
}

void merase(MatrixPointer *node)
{
	MatrixPointer x,y;
	int i, NumHeads;
	for (i = 0; i < (*node)->u.entry.row; i++) {
		y = HdNode[i]->right;
		while (y != HdNode[i]) {
			x = y;
			y = y->right;
			free(x);
		}
	}
	NumHeads = ((*node)->u.entry.row > (*node)->u.entry.col) ?
		(*node)->u.entry.row : (*node)->u.entry.col;
	for (i = 0; i < NumHeads; i++)
		free(HdNode[i]);
	*node = NULL;
}
