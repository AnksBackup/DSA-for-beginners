// C++ implementation of Shell Sort

// Best time complexity: O(nlogn)
// Average time complexity: O(nlogn)
// Worst time complexity: O(n^2)

// Space complexity: O(1)

// Shell sort is not a stable sort algorithm, i.e, it does not preserve the relative order of 2 equal elements in the input array after sorting.
// Shell sort is an inplace sort algorithm, i.e, it does not require extra memory, except for O(1) auxiliary space.

#include <iostream>
#include <vector>
using namespace std;
 
/* Function to sort a vector using shellSort */
int shellSort(vector<int>& arr, int n)
{
    // Start with a big gap - n/2, half the gap for every iteration
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is gap sorted
        for (int i = gap; i<n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}
 
int main()
{
    vector<int> arr = {12, 34, 54, 2, 3};
    int n = arr.size();
 
    cout << "Array before sorting: ";
    
    for (int i = 0; i<n; ++i)
        cout << arr[i] << " ";
    cout << '\n';
    
    shellSort(arr, n);
 
    cout << "\nArray after sorting: ";
    
    for (int i = 0; i<n; ++i)
        cout << arr[i] << " ";
    cout << '\n';
 
    return 0;
}
