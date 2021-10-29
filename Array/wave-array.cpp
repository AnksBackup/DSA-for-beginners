//probles statement : convert given array into wave array

#include <bits/stdc++.h>
using namespace std;
/*From GFG O(n)*/
/*=>This give only wave array*/
void convertToWave(int *a, int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if ((i > 0) && (a[i - 1] > a[i]))
        {
            swap(a[i - 1], a[i]);
        }
        if ((i < (n - 1)) && (a[i] < a[i + 1]))
        {
            swap(a[i], a[i + 1]);
        }
    }
}

/*Own InterviewBit*/
/*O(nlogn)*/
/*=>This give lexiographicaly smallest posiible solution*/
vector<int> wave(vector<int> &a)
{
    sort(a.begin(), a.end());
    for (int i = 1; i < a.size(); i += 2)
    {
        swap(a[i - 1], a[i]);
    }
    return a;
}
