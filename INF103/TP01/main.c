#include <stdio.h>
#include <stdlib.h>
#include "structpoint.h"

int main(){
  struct Point p1;
  struct Point *pt1 = &p1;
  pt1->x = 11;
  pt1->y = 9;
  printf("Nokta 1: x %.2f, y %.2f\n",pt1->x,pt1->y);

  struct Circle c1 = {1, {0,0}};
  struct Circle *cp1 = &c1;
  printf("Cember 1: merkez(%.2f, %.2f) yaricap %.2f\n",cp1->nokta.x,cp1->nokta.y,cp1->r);

  printf("Uzaklik: %f\n", distance(pt1, &cp1->nokta));

  printf("Nokta1 Cember1'in %s\n", is_in_circle(pt1, cp1) ? "icinde" : "disinda");

  int n_point = 1000; 
  struct Point pt_array[n_point];
  create_point_array(pt_array, n_point);

  int i;
  printf("Rastgele [0,1] arasinda olusturulan %d nokta:\n", n_point);
  printf("==========================================================================\n");
  for(i=0;i<n_point;i++)printf("%4d: (%.2f,%.2f) %s", i+1, pt_array[i].x, pt_array[i].y, i%4==3 ? "\n": " ");
  printf("==========================================================================\n");

  int nbr_in_circle = 0;

  struct Circle c2 = {.5, {.5,.5}};
  struct Circle *cp2 = &c2;

  printf("Cember2: merkez(%.2f,%.2f) yaricap %.2f\n", cp2->nokta.x, cp2->nokta.y, cp2->r);

  for(i=0;i<n_point;i++){
    if(is_in_circle(&pt_array[i], cp2)){
      nbr_in_circle++;
    }
  }
  printf("Toplam nokta sayisi: %d\n", n_point);
  printf("Cember2 icinde kalan nokta sayisi: %d\n",nbr_in_circle);
  double calculated_pi = 0;

  double oran = (double)nbr_in_circle / n_point;
  calculated_pi = oran * 4;

  printf("Hesaplanan pi sayisi: %f\n",calculated_pi);
    
  return 0;
}
