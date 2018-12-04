#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define BUFFER 101
#define REMOVE -9999

void mdelete(int arr[], int size, int delete);
void reorder(int arr[], int size, int index);
void print_arr(int arr[], int size);

int main(int argc, char const *argv[]){
    int delete = 0;
    int len_arr = 0;
    int *arr = malloc(BUFFER * sizeof(int));
    memset(arr, 0, sizeof(arr));

    char enter[BUFFER] = {'\0'};
    scanf("%[^\n]%*c", &enter); 
    char *pch;
    pch = strtok(enter, " ");
    while (pch != NULL){
        arr[len_arr++] = atoi(pch);
        if (len_arr > 100){
            printf("Exceeding Buffer...\n");
            return -1;
        }
        pch = strtok (NULL, " ");
    }      
    
    memset(enter, '\0', sizeof(enter));
    scanf("%[^\n]%*c", &enter);
    delete = atoi(enter);

    mdelete(arr, len_arr, delete);
    print_arr(arr, len_arr);

    return 0;
}

void mdelete(int arr[], int size, int delete)
{
    int left, right, i, tmp, pnode;
 
    for (i = 0; i < size; i++) {
        if (arr[i] == delete) break;
    }
    if (i == size){
        printf("No match element...\n");
        return;
    }

    int atmp = min(arr[size - 1], arr[size - 2]);
    if (atmp == arr[size - 2]){
        int ttmp = arr[size - 1];
        arr[size - 1] = arr[size - 2];
        arr[size - 2] = ttmp;
    }
    arr[i] = arr[size - 1];
    size = size - 1;
    pnode =(i - 1) / 2;

    reorder(arr, size, i);

    arr[size] = REMOVE;
}

void reorder(int arr[], int size, int i){
    int tmp;
    while (i+i+2 < size){
        if (arr[i] >= arr[i+i+1] && arr[i] >= arr[i+i+2]) return;
        if (arr[i+i+2] <= arr[i+i+1]){
            tmp = arr[i];
            arr[i] = arr[i+i+1];
            arr[i+i+1] = tmp;
            i = i+i+1;
        }
        else{
            tmp = arr[i];
            arr[i] = arr[i+i+2];
            arr[i+i+2] = tmp;
            i = i+i+2;
        }
    }
    if (i+i+1 == size - 1 && arr[i]) {
        tmp = arr[i];
        arr[i] = arr[i+i+1];
        arr[i+i+1] = tmp;
    }
    return;
}

void print_arr(int arr[], int size){
    int i;
    for (i=0; i<size; i++){
        if (arr[i] != REMOVE) printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}