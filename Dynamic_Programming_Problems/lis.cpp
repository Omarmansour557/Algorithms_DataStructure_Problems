#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int n, vector<int> &arr)
{
    // LIS satand for longest increasing subsequence
    std::vector<int> listContainLIS(n);
    for (int i = 0; i < n; i++)
    {
        listContainLIS[i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && listContainLIS[i] < listContainLIS[j] + 1)
            {
                listContainLIS[i] = listContainLIS[j] + 1;
            }
        }
    }

    // finding maximum subsequence
    int max = listContainLIS[0];
    for (int i = 1; i < n; i++)
    {
        max = max < listContainLIS[i] ? listContainLIS[i] : max;
    }
    return max;
}
int main(int argc, char **argv)
{
    int n;
    cout << "Enter the nummber of items : " << endl;
    cin >> n;
    cout << "Enter the values of weights of each item: " << endl;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxValue = longestIncreasingSubsequence(n, arr);
    cout << "The maximum value  is: " << maxValue << endl;
}