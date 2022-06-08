#ifndef _HW_H_
#define _HW_H_

#define GETSECONDS(a, b) ((((b.tv_sec - a.tv_sec) * 1000) + ((b.tv_usec - a.tv_usec) / 1000.0)))

extern void merge_sort_wrapper(int *, int);
extern void shell_sort(int *, int);
extern void ciura_shell_sort(int *, int);
extern void insertion_sort(int *, int);
extern void bubble_sort(int*, int);
extern void selection_sort(int*, int);
extern void quick_sort_wrapper(int*, int);

extern void print_array(int *, int);
extern int sort_comparator(const void *, const void *);
extern int* generate_random_array(int, int, int);
extern int arrays_equal(int *, int *, int);

typedef struct {
  /* Algoritmanin adi, ornek: "Insertion Sort" */
  char *name;
  /* Algoritmanin siralama hizi (max 16) */
  double perf[16];
  /* Algoritmayi gercekleyen fonksiyonu gosterecek pointer */
  void (*fptr) (int *, int);
  /* Performansi olculsun mu? */
  int dont_benchmark;
} SortMethod;


#endif
