#include <bits/stdc++.h>

using namespace std;

int knapsackWithRepetitions(int ks_weight, vector<int> &weights, vector<int> &values, int itemsNumber)
{
    vector<int> optimizingVector(ks_weight + 1);
    int val = 0;
    for (int w = 0; w <= ks_weight; w++)
    {
        for (int i = 0; i < itemsNumber; i++)
        {
            if (w >= weights[i])
            {
                val = optimizingVector[w - weights[i]] + values[i];
                optimizingVector[w] = val < optimizingVector[w] ? optimizingVector[w] : val;
            }
        }
    }
    return optimizingVector[ks_weight];
}

int main(int argc, char **argv)
{
    size_t n, ks_weight;
    cout << "Enter the nummber of items in knapsack followed by maximum knapsack Weight: " << endl;
    cin >> n >> ks_weight;
    cout << "Enter the values of weights of each item: " << endl;
    vector<int> weights(n);
    vector<int> values(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    cout << "Enter the weight's price of each item: " << endl;

    for (size_t i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    int maxValue = knapsackWithRepetitions(ks_weight, weights, values, n);
    cout << "The maximum value that the knapsack can hold is: " << maxValue << endl;
}