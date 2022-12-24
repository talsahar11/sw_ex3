///-----Given a pointer to an element in an array and a index i, for each element in range (current, current + i)-----
///-----shift the element to the right by one-------------------------------------------------------------------------
void shift_element(int* arr, int i){
    while(i > 0){
        *(arr+i) = *(arr+i-1) ;
        i-- ;
    }
}

///-----Given a pointer to an array, and indexes i, j, shift all elements from i to j-1 to the right, and-----
///-----insert the element was at index j, to the index i in the array----------------------------------------
void shift_and_insert(int* arr, int i, int j){
    int temp = *(arr+i) ;
    shift_element((arr + j), i-j) ;
    *(arr+j) = temp ;
}

///-----Give an array and its length, sort the array with the insertion sort algorithm-----
void insertion_sort(int*  arr, int length) {
    int i = 0, j = 0, swappingIndex = 0;
    for (i = 1; i < length; i++) {
        swappingIndex = i ;
        for(j = i-1 ; j >= 0 ; j--){
            if(*(arr + i) < *(arr + j)){
                swappingIndex-- ;
            }
        }
        if(swappingIndex!=i){
            shift_and_insert(arr, i, swappingIndex) ;
        }
    }
}

