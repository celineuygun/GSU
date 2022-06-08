#ifndef APPLICATIONS_H_
#define APPLICATIONS_H_

int is_array_sorted(int* arritem,int size);
int find_maxsum_elements_sorted(int* arritem,int size);
int find_maxsum_elements_unsorted(int* arritem,int size);
int find_mode_element(int* arritem,int size);
void minimum_k_elements(int* arritem,int size,int k,int arrRes[k]);
void remove_duplications(int* arritem,int size,int* dest);

#endif /* APPLICATIONS_H_ */