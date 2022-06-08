#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int value_min(int[], size_t);
int value_max(int[], size_t);

int main(){
    int les_notes[N];
    int somme = 0;
    
    srand(time(0));

    for( int i = 0 ; i < N ; i++ ) {
        les_notes[i] = rand() % 101;
    }

    printf("\nLes notes des etudiants: ");
    for(int j=0; j<N; ++j){
        printf("%d ", les_notes[j]);
        somme += les_notes[j];  
    }
    printf("\nMoyen: %.2f", (somme/1.0)/N); 
    printf("\nMin: %d", value_min(les_notes, N));
    printf("\nMax: %d", value_max(les_notes, N));
    
    printf("\n");
	
	return 0;
}

int value_min(int array[], size_t size){ 
    int min_value = array[0];
    for (int k = 1; k < size; ++k){
        if (array[k] < min_value){
            min_value = array[k];
        }
    }
    return min_value;
}

int value_max(int array[], size_t size){
    int max_value = array[0];
    for (int k = 1; k < size; ++k){
        if (array[k] > max_value){
            max_value = array[k];
        }
    }
    return max_value;
}