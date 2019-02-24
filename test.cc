#include <iostream>
#include <vector>
#include "sort.h"

int main()
{
	using namespace std;

	vector<int> arr;
	random_gen(arr, 100);

	cout << "array:";
	print_vec(arr);
	cout << endl;

	cout << "sorted:";
	quick_sort_non_recur(arr);
	print_vec(arr);
	cout << endl;

	return 0;
}
