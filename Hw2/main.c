#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define u unsigned
#define MAX_EXEC_TIMES 50000
#define Row_1 15
#define Col_1 15
#define Row_2 39
#define Col_2 19
#define Iniposx_1 10
#define Iniposy_1 10
#define Iniposx_2 1
#define Iniposy_2 1

/***** Create vars *****/
u arr_1[Row_1][Col_1];
u arr_2[Row_2][Col_2];
u point_1[2] = {Iniposx_1, Iniposy_1}; // [0] for x, [1] for y
u point_2[2] = {Iniposx_2, Iniposy_2}; // [0] for x, [1] for y

u move(u Question, u direction);
u nonZero(u Question);
void print_arr(u Question, u Steps);

int main(int argc, char* argv[]){
	// Initial vars
	arr_1[point_1[0]][point_1[1]] += 1;
	arr_2[point_2[0]][point_2[1]] += 1;
	
	// Random seed
	srand(time(NULL));

	/*** Question 1 ***/
	int i=0;
	u Question = 1;
	u Steps = 0;
	for(i=0; i<=MAX_EXEC_TIMES; ++i){
		int direction = rand()%8;
		int tmp = move(Question, direction);
		if(tmp) Steps += 1;
		else i -= 1;
		if(nonZero(Question)) break;
	}
	print_arr(Question, Steps);

	/*** Question 2 ***/
	i=0;
	Question = 2;
	Steps = 0;
	for(i=0; i<=MAX_EXEC_TIMES; ++i){
		int direction = rand()%8;
		int tmp = move(Question, direction);
		if(tmp) Steps += 1;
		else i -= 1;
		if(nonZero(Question)) break;
	}
	print_arr(Question, Steps);
	return 0;
}

/***** Move eight direction *****/
u move(u Question, u direction){
	u pre_point[2];
	if(Question == 1){
		pre_point[0] = point_1[0];
		pre_point[1] = point_1[1];
	} else if(Question == 2){
		pre_point[0] = point_2[0];
		pre_point[1] = point_2[1];
	}
	switch(direction){
		case 0:
			if(Question == 1){
				point_1[0] += -1;
				point_1[1] += 1;
			} else if(Question == 2){
				point_2[0] += -1;
				point_2[1] += 1;
			}
			break;
		case 1:
			if(Question == 1){
				point_1[0] += 0;
				point_1[1] += 1;
			} else if(Question == 2){
				point_2[0] += 0;
				point_2[1] += 1;
			}
			break;
		case 2:
			if(Question == 1){
				point_1[0] += 1;
				point_1[1] += 1;
			} else if(Question == 2){
				point_2[0] += 1;
				point_2[1] += 1;
			}
			break;
		case 3:
			if(Question == 1){
				point_1[0] += 1;
				point_1[1] += 0;
			} else if(Question == 2){
				point_2[0] += 1;
				point_2[1] += 0;
			}
			break;
		case 4:
			if(Question == 1){
				point_1[0] += 1;
				point_1[1] += -1;
			} else if(Question == 2){
				point_2[0] += 1;
				point_2[1] += -1;
			}
			break;
		case 5:
			if(Question == 1){
				point_1[0] += 0;
				point_1[1] += -1;
			} else if(Question == 2){
				point_2[0] += 0;
				point_2[1] += -1;
			}
			break;
		case 6:
			if(Question == 1){
				point_1[0] += -1;
				point_1[1] += -1;
			} else if(Question == 2){
				point_2[0] += -1;
				point_2[1] += -1;
			}
			break;
		case 7:
			if(Question == 1){
				point_1[0] += -1;
				point_1[1] += 0;
			} else if(Question == 2){
				point_2[0] += -1;
				point_2[1] += 0;
			}
			break;
	}
	if(point_1[0] < 0 || point_1[0] > 15 || point_1[1] < 0 || point_1[1] > 15 || point_2[0] < 0 || point_2[0] > 39 || point_2[1] < 0 || point_2[1] > 19){
		if(Question == 1){
			point_1[0] = pre_point[0];
			point_1[1] = pre_point[1];
		} else if(Question == 2){
			point_2[0] = pre_point[0];
			point_2[1] = pre_point[1];
		}
		return 0;
	}
	if(Question == 1){
		arr_1[point_1[0]][point_1[1]] += 1;
	} else if(Question == 2){
		arr_2[point_2[0]][point_2[1]] += 1;
	}
	return 1;
}

/* Check if done */
u nonZero(u Question){
	int i, j, row, col;
	if(Question == 1){
		row = Row_1;
		col = Col_1;
	} else if(Question == 2){
		row = Row_2;
		col = Col_2;
	}
	for(i=0; i<row; ++i){
		for(j=0; j<col; ++j){
			if(Question == 1){
				if(arr_1[i][j] == 0) break;
			} else if(Question == 2){
				if (arr_2[i][j] == 0) break;
			}
		}
		if(Question == 1){
			if(arr_1[i][j] == 0) break;
		} else if(Question == 2){
			if (arr_2[i][j] == 0) break;
		}
	}
	if(i == row && j == col) return 1;
	else return 0;
}

/***** Print arr *****/
void print_arr(u Question, u Steps){
	// Initial vars
	int i, j, row, col;
	if(Question == 1){
		row = Row_1;
		col = Col_1;
	} else if(Question == 2){
		row = Row_2;
		col = Col_2;
	}
	printf("Experiment %u:\n", Question);
	printf("Total moves: %u\n", Steps);
	// print out array
	for(i=0; i<row; ++i){
		for(j=0; j<col; ++j){
			if (Question == 1){
				printf("% 4u", arr_1[i][j]);
			} else if (Question == 2){
				printf("% 4u", arr_2[i][j]);
			}
		}
		printf("\n");
	}	
	return;	
}
