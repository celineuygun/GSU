void bubble_sort(int *arr, int size){
    for(int i = size; i >= 2; --i){
        int flag = 0;
        for(int j = 0; j < i - 1; ++j){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if(!flag)break;
    }
}