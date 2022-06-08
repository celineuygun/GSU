#include <stdio.h>
#define N 6

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int binarySearch(int array[], int head, int tale){
    int leftSide;
    if(head>tale)return -1;

    int middle=(head+tale)/2;
	if(array[middle]==middle+1)return (middle+1);
	
    leftSide=binarySearch(array,head,MIN(array[middle],middle-1));

    if(leftSide!=-1)return leftSide;

    return binarySearch(array,MAX(array[middle],middle+1),tale);

} 

int main(){
    int array[N] = {-1,2,4,6,7,8};
    printf("%d %s\n", binarySearch(array,0,N-1),binarySearch(array,0,N-1)!=-1?"WOW":"NO");

    return 0;
}