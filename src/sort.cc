#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include "sort.h"

using namespace std;

void random_gen(vector<int> &arr, int size)
{
	srand(time(NULL));
	for(int i = 0; i < size; ++i) {
		arr.push_back(rand() % 10000);
	}
}

void print_vec(vector<int> &v)
{
	for(auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void selection_sort(vector<int> &arr)
{
	for(int i = 0; i < arr.size(); ++i) {
		int index = i;
		for(int j = i + 1; j < arr.size(); ++j) {
			if(arr[index] > arr[j]) {
				index = j;
			}
		}
		int temp = arr[index];
		arr[index] = arr[i];
		arr[i] = temp;
	}
}

void bubble_sort(vector<int> &arr)
{
	for(int i = 0; i < arr.size(); ++i) {
		for(int j = 0; j < arr.size() - i - 1; ++j) {
			if(arr[j] > arr[j + 1]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void insertion_sort(vector<int> &arr)
{
	for(int i = 0; i < arr.size() - 1; ++i) {
		int j = i + 1;
		int temp = arr[j];
		while(arr[j - 1] > temp && j > 0) {
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = temp;
	}
}

void merge(vector<int> &ret, vector<int> &arr1, vector<int> &arr2)
{
	int i = 0, j = 0;
	while(i < arr1.size() && j < arr2.size()) {
		if(arr1[i] < arr2[j]) {
			ret.push_back(arr1[i++]);
		} else {
			ret.push_back(arr2[j++]);
		}
	}
	while(i < arr1.size()) {
		ret.push_back(arr1[i++]);
	}
	while(j < arr2.size()) {
		ret.push_back(arr2[j++]);
	}
}

void merge_sort_recur(vector<int> &arr)
{
	if(arr.size() < 2) {
		return;
	}

	int n1 = arr.size() / 2;
	int n2 = arr.size() - n1;

	vector<int> arr1(arr.begin(), arr.begin() + n1);
	vector<int> arr2(arr.begin() + n1, arr.end());

	merge_sort_recur(arr1);
	merge_sort_recur(arr2);

	arr.clear();
	merge(arr, arr1, arr2);
}

void merge_sort_non_recur(vector<int> &arr)
{
	vector<int> ret;
	for(int i = 1; i < arr.size(); i *= 2) {
		ret.clear();
		for(int k = 0; k < arr.size(); k += 2 * i) {
			vector<int> temp;
			vector<int> temp1(arr.begin() + k, min(arr.begin() + k + i, arr.end()));
			vector<int> temp2(min(arr.begin() + k + i, arr.end()), min(arr.begin() + k + 2 * i, arr.end()));
			merge(temp, temp1, temp2);	
			ret.insert(ret.end(), temp.begin(), temp.end());
		}
		arr.clear();
		arr.assign(ret.begin(), ret.end());
	}
}

void qsort(vector<int>::iterator begin, vector<int>::iterator end)
{
	vector<int>::iterator i = begin, j = end;
	int pivot = *end;
	if(begin >= end) {
		return;
	}

	while(i < j) {
		while(i < j && *i <= pivot) {
			++i;
		}
		while(i < j && *j >= pivot) {
			--j;
		}
		swap(*i, *j);
	}
	if(*i > pivot) {
		swap(*i, *end);
	}
	qsort(begin, i - 1);
	qsort(i + 1, end);
}

void quick_sort_recur(vector<int> &arr)
{
	qsort(arr.begin(), arr.end() - 1);
}

void quick_sort_non_recur(vector<int> &arr)
{
	stack< pair<vector<int>::iterator, vector<int>::iterator> > range;

	range.push(make_pair(arr.begin(), arr.end() - 1));
	while(!range.empty()) {
		pair<vector<int>::iterator, vector<int>::iterator> temp = range.top();
		range.pop();
		int pivot = *(temp.second);
		auto left = temp.first;
		auto right = temp.second - 1;
		if(left >= right) {
			continue;
		}
		while(left < right) {
			while(left < right && *left < pivot) {
				++left;
			}
			while(left < right && *right > pivot) {
				--right;
			}
			swap(*left, *right);
		}
		if(*left > pivot) {
			swap(*left, *(temp.second));
		}
		range.push(make_pair(temp.first, left - 1));
		range.push(make_pair(left + 1, temp.second));
	}
}
