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
MatrixPointer mread(int settingNumber);
MatrixPointer mtranspose(int settingNumber, int targetNumber);
MatrixPointer mmult(MatrixPointer node1, MatrixPointer node2, int settingNumber,int targetNumber1, int targetNumber2);
void mwrite(MatrixPointer node, int targetNumber);
void merase(MatrixPointer *node, int targetNumber);
int NumRows, NumCols, NumEntries[MAX_SIZE], NumHeads;

int main()
{
	MatrixPointer a, b, bt, ab;
	a = mread(0);
	printf("\n");
	b = mread(1);
	bt = mtranspose(2, 1);
	printf("\n\n");
	printf("b transpose:\nnumRows = %d, numCols = %d\nThe matrix:\n", bt->u.entry.row, bt->u.entry.col);
	mwrite(bt, 2);
	ab = mmult(a, bt, 3, 0, 2);
	printf("a * b transpose:\nnumRows = %d, numCols = %d\nThe matrix:\n", ab->u.entry.row, ab->u.entry.col);
	mwrite(ab, 3);

	merase(&a, 0);
	merase(&b, 1);
	merase(&bt, 2);
	merase(&ab, 3);
	return 0;
}

MatrixPointer mmult(MatrixPointer node1, MatrixPointer node2, int sn, int tn1, int tn2){
	MatrixPointer node, temp, last, tmp1, tmp2;
	int CurrentRow, row, col, value, i, j, numCols, numRows, Vars=sn;

	if (node1->u.entry.col != node2->u.entry.row) {
		printf("Invalid Array Multiplicand\n");
		node->right = node;
		return node;
	}

	// set H
	node = (MatrixPointer)malloc(sizeof(struct MatrixNode));
	node->tag = entry;
	node->u.entry.row = node1->u.entry.row;
	node->u.entry.col = node2->u.entry.col;
	numCols = node->u.entry.col;
	numRows = node->u.entry.row;

	NumHeads = (numCols > numRows) ? numCols : numRows;
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
		for (i = 0; i < numRows; i++) {
			for(j = 0; j < numCols; j++){
				value=0;
				// Multi
				for (tmp1 = HdNode[tn1][i]->right; tmp1 != HdNode[tn1][i]; tmp1 = tmp1->right){
					for (tmp2 = HdNode[tn2][j]->down; tmp2 != HdNode[tn2][j]; tmp2 = tmp2->down){
						if (tmp1->u.entry.col == tmp2->u.entry.row)
							value += (tmp1->u.entry.value * tmp2->u.entry.value);
					}				
				}
				if (value == 0){
					continue;
				}
				row = tmp1->right->u.entry.row;
				col = tmp2->down->u.entry.col;

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
		for (i = 0; i < numCols; i++)
			HdNode[Vars][i]->u.next->down = HdNode[Vars][i];

		// row point to left
		for (i = 0; i < NumHeads-1; i++)
			HdNode[Vars][i]->u.next = HdNode[Vars][i+1];
		HdNode[Vars][NumHeads-1]->u.next = node;
		node->right = HdNode[Vars][0];
	}
	return node;
}

MatrixPointer mtranspose(int sn, int tn){
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
			HdNode[sn][i] = temp;
			HdNode[sn][i]->tag = head;
			HdNode[sn][i]->right = temp;
			HdNode[sn][i]->u.next = temp;
		}

		// Start to store
		CurrentRow = 0;
		last = HdNode[sn][0];
		for (i = 0; i < NumCols; i++) {
			for (tmp = HdNode[tn][i]->down; tmp != HdNode[tn][i]; tmp = tmp->down){
				row = tmp->u.entry.col;
				col = tmp->u.entry.row;
				value = tmp->u.entry.value;
				// if input to next row -> point back to HdNode
				if (row > CurrentRow) {
					last->right = HdNode[sn][CurrentRow]; 
					CurrentRow = row;
					last = HdNode[sn][row];
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
				HdNode[sn][col]->u.next->down = temp; 
				HdNode[sn][col]->u.next = temp;
			}
		}
		// last point back to Hx
		last->right = HdNode[sn][CurrentRow];

		// col point back to top
		for (i = 0; i < NumCols; i++)
			HdNode[sn][i]->u.next->down = HdNode[sn][i];

		// row point to left
		for (i = 0; i < NumHeads-1; i++)
			HdNode[sn][i]->u.next = HdNode[sn][i+1];
		HdNode[sn][NumHeads-1]->u.next = node;
		node->right = HdNode[sn][0];
	}
	return node;
}

MatrixPointer mread(int sn){
	int row, col, value, CurrentRow, i, Vars = sn;
	MatrixPointer temp,last,node;

	printf("Enter the number of {rows columns entries}: ");
	scanf("%d%*c %d%*c %d%*c",&NumRows, &NumCols, &NumEntries[sn]);
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
		for (i = 0; i < NumEntries[sn]; i++) {
			printf("Enter {row column value}: ");
			scanf("%d%*c %d%*c %d%*c",&row,&col,&value);
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
	return node;
}	


void mwrite(MatrixPointer node, int tn){
	int i, zero, Vars=tn;
	MatrixPointer temp;
	printf("Matrix: \n");
	for (i = 0; i < node->u.entry.row; i++){
		zero = 0;
		for (temp = HdNode[Vars][i]->right; temp != HdNode[Vars][i]; temp = temp->right){
			while(zero++ < temp->u.entry.col) printf("  0");
			printf("%3d", temp->u.entry.value);
		}
		while(zero++ < node->u.entry.col) printf("  0");
		printf("\n");
	}
}

void merase(MatrixPointer *node, int tn){
	int i, NumHeads, Vars = tn;
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
