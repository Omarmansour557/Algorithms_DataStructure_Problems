#include <bits/stdc++.h>
using namespace std;

int naive_counting_inversions(vector<int> &a)
{
    int inversionCount = 0;
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                inversionCount++;

    return inversionCount;
}

