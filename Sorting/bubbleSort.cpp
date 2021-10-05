#include <iostream>
#include <ctime>
using namespace std;
//time O(N^2)  and  Space O(1)
bool compare(int a, int b)
{
	return a > b;
}

//Sort the elements in increasing order
void bubble_sort(int a[], int n)
{
	int flag = 0;
	for (int times = 0; times < n - 1; times++)
	{
		//repeated swapping
		for (int j = 0; j < n - times - 1; j++)
		{
			if (compare(a[j], a[j + 1]))
			{
				swap(a[j], a[j + 1]);
				flag = 1;
			}
		}
		//it will be zero if after first iteration no swaps took place as the array was in sorted order
		if (flag == 0) //giving this check reduces time to O(N) for sorted qarray rather than O(N^2)
			break;
	}
}
int main()
{
	int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
	int n = sizeof(arr) / sizeof(int);
	bubble_sort(arr, n);
	for (auto i : arr)
	{
		cout << i << " ";
	}
	return 0;
}