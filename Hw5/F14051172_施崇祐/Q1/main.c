#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 101

void re_priority(int arr[], int size, int delete, int replace);
void reorder(int arr[], int size);
void print_arr(int arr[], int size);

int main(int argc, char const *argv[]){
    int delete = 0;
    int replace = 0;
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
    pch = strtok(enter, " ");
    delete = atoi(pch);
    pch = strtok (NULL, " ");
    replace = atoi(pch);

    re_priority(arr, len_arr, delete, replace);
    print_arr(arr, len_arr);
    
    return 0;
}

void re_priority(int arr[], int size, int delete, int replace){
    int i;
    for (i=0; i<size; i++){
        if (arr[i] == delete) {
            arr[i] = replace;
            break;
        }
    }
    if (i != size) reorder(arr, size);
    else printf("No match element...\n");
    return;
}

void reorder(int arr[], int size){
    int i=0, tmp;
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
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}