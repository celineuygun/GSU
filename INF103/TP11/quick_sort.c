void swap(int *intArray, int i, int j) {
   int temp = intArray[i];
   intArray[i] = intArray[j];
   intArray[j] = temp;
}

int partition(int* arr, int l, int r){
    int pivot = arr[r];
    int i = l - 1;
    int j;
    for(j = l; j < r; ++j){
        if(arr[j] < pivot){
            ++i;
            swap(arr, i, j);
        }
    }swap(arr, i + 1, r);
    return (i + 1);
}

void quick_sort(int* arr, int l, int r){
    if(l >= r) return;
    int p = partition(arr, l, r);
    quick_sort(arr, l, p-1);
    quick_sort(arr, p+1, r);
}

void quick_sort_wrapper(int *array, int size){
  quick_sort(array, 0, size - 1);
}