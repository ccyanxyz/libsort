#ifndef __SORT_H__
#define __SORT_H__

#include <vector>

using namespace std;

void selection_sort(vector<int> &arr);
void bubble_sort(vector<int> &arr);
void insertion_sort(vector<int> &arr);
void merge_sort_recur(vector<int> &arr);
void merge_sort_non_recur(vector<int> &arr);
void quick_sort_recur(vector<int> &arr);
void quick_sort_non_recur(vector<int> &arr);
void print_vec(vector<int> &arr);
void random_gen(vector<int> &arr, int size);

#endif
