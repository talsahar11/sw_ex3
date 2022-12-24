#include "../hdrs/isort.h"
#include <stdio.h>
#define ARRAY_SIZE 50

int main() {
    int arr[ARRAY_SIZE] = {0} ;

    //-----Read the array elements from the input stream-----
    for(int i = 0 ; i < ARRAY_SIZE ; i++){
        scanf("%d", arr+i) ;
    }

    //-----Sort the array-----
    insertion_sort(arr, ARRAY_SIZE) ;

    //-----Print out the sorted array-----
    printf("%d", *(arr)) ;
    for(int i = 1 ; i < ARRAY_SIZE ; i++){
        printf(",%d", *(arr+i)) ;
    }
    printf("\n") ;
    return 0;
}
