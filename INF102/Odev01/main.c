#include <stdio.h>
#include <float.h>
#include <limits.h>

int main() {

   printf("INT_MIN       = %+d\n", INT_MIN);
   printf("INT_MAX       = %+d\n", INT_MAX);
   printf("sizeof(int)   = %lu byte\n", sizeof(int));
   
   printf("FLT_MIN       = %e\n", FLT_MIN);
   printf("FLT_MAX       = %e\n", FLT_MAX);
   printf("sizeof(float) = %lu byte\n", sizeof(float));

   
   return(0);
}