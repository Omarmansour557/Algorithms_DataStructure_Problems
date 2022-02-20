#include "naive.h"
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool are_equal(string text1, string text2)
{
    if (text1.size() != text2.size())
        return false;

    for (int i = 0; i < text1.size(); i++)
    {
        if (text1[i] != text2[i])
            return false;
    }

    return true;
}

vector<int> search_pattern_naive(string text, string pattern)
{
    vector<int> result;
    int textSize = text.size();
    int patternSize = pattern.size();

    string a = "aomarsdf";

    for (int i = 0; i <= textSize - patternSize; i++)
    {

        // bool flag = are_equal(text.substr(i, patternSize ), pattern);

        if (are_equal(text.substr(i, patternSize), pattern))
        {
            result.push_back(i);
            // cout<<"-------------"<<result.size()<<"---------------------"<<endl;
        }
    }

    // cout<<result.size();
    return result;
}

/*------------------------------------------------------

IN ORDER TO CHECK THE NAIVE ALGORITHM

-------------------------------------------------------*/




// int main(int argc, char **argv)
// {

//     string text = "dsfh kjadadfssfkjhadskjfh akjsdadfshfkjadshfkjasdfeidadfso adshkj fkjadshf kkjdadfsadsfah fkjladsf uaesbkjdfm, a";
//     string pattern = "dadfs";

//     // string text = "abcab", pattern = "ab";

//     vector<int> result1;
//     result1 = search_pattern_naive(text, pattern);

//     int size = result1.size();

//     for (int i = 0; i < size; i++)
//     {
//         cout << result1[i] << ", ";
//     }
//     return 0;
// }


