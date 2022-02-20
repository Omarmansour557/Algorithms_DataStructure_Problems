#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int knWitoutRepetition(int kn_weight, int items, vector<int> &weights, vector<int> &values)
{
    vector<vector<int>> table(items + 1, vector<int>(kn_weight + 1));
    for (int i = 0; i <= items; i++)
    {
        for (int w = 0; w <= kn_weight; w++)
        {
            if (i == 0 || w == 0)
            {
                table[i][w] = 0;
            }
            else if (w >= weights[i - 1])
            {
                table[i][w] = max(table[i - 1][w], values[i - 1] + table[i - 1][w - weights[i - 1]]);
            }
            else
            {
                table[i][w] = table[i - 1][w];
            }
        }
    }
    return table[items][kn_weight];
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
    int maxValue = knWitoutRepetition(ks_weight, n, weights, values);
    cout << "The maximum value that the knapsack can hold is: " << maxValue << endl;
}