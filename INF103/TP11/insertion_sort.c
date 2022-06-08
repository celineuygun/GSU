int bs(int* arr, int l, int r, int n){
    if(l < r){
        int m = (l + r)/2;
        if(arr[m] == n) return m + 1;
        else if(arr[m] < n) return bs(arr, m+1, r, n);
        else return bs(arr, l, m-1, n);
    }
    return (n > arr[l]) ? l + 1 : l;
}

void insertion_sort(int *arr, int size){
    for(int i = 1; i < size; ++i){
        int j = i - 1, selected = arr[i];
        int loc = bs(arr, 0, i-1, arr[i]);
        while(j >= loc){
            arr[j+1] = arr[j];
            j--;
        }arr[j+1] = selected;
    }
}