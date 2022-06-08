void shell_sort(int *array, int size) {
  /* Sedgewick tarafindan belirlenen gap serisi */
  int gaps[] = {4193, 1073, 281, 77, 23, 8, 1};
  int i, j, k;
  for(k = 0; k < 7; k++){
    int h = gaps[k];
    for(i = h; i < size; i++){
      int temp = array[i];
      for(j = i; j >= h && array[j-h] > temp; j -= h){
        array[j] = array[j-h];
      }
      array[j] = temp;
    }
  }
}

void ciura_shell_sort(int *array, int size) {
  /* Ciura tarafindan belirlenen gap serisi */
  int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
  int i, j, k;
  for(k = 0; k < 8; k++){
    int h = gaps[k];
    for(i = h; i < size; i++){
      int temp = array[i];
      for(j = i; j >= h && array[j-h] > temp; j -= h){
        array[j] = array[j-h];
      }
      array[j] = temp;
    }
  }
}