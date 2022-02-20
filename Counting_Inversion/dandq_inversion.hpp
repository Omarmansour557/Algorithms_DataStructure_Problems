// using Merge Sort
#include <bits/stdc++.h>
using namespace std;

int mergeSort(vector<int> &a, vector<int> &temp, int left, int right);
int merge(vector<int> &a, vector<int> &temp, int left, int mid,
          int right);

/* this is the final function that return number of inversion */
int dandq_counting_inversions(vector<int> &a)
{
    vector<int> temp(a.size());
    return mergeSort(a, temp, 0, a.size() - 1);
}

/* helpful function that sort the splitted vectors and return number of inversions. */
int mergeSort(vector<int> &a, vector<int> &temp, int left, int right)
{
    int mid, inversionCount = 0;
    if (right > left)
    {
        /* Divide the array into two parts and
        call _mergeSortAndCountInv()
        for each of the parts */
        mid = (right + left) / 2;

        /* Inversion count will be sum of
        inversions in left-part, right-part
        and number of inversions in merging */
        inversionCount += mergeSort(a, temp, left, mid);
        inversionCount += mergeSort(a, temp, mid + 1, right);

        /*Merge the two parts*/
        inversionCount += merge(a, temp, left, mid + 1, right);
    }
    return inversionCount;
}

/* function that merge the sorted two splitted vectors then return number of inversions*/
int merge(vector<int> &a, vector<int> &temp, int left, int mid,
          int right)
{
    int i, j, k;
    int inversionCount = 0;

    i = left; /* i is index for left subvector*/
    j = mid;  /* j is index for right subvector*/
    k = left; /* k is index for resultant merged subvector*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];

            /*this line because the two parts are sorted so when we compare a[i] >a[j] 
            then the rest of array after a[i] will be greater than a[j]
            thus, we conclude that the inversion equal to mid-i*/
            
                  
                  
          // this line is included in the comment by mistake.
            inversionCount = inversionCount + (mid - i);
        }
    }

    /* Copy the remaining elements of left subvector
(if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = a[i++];

    /* Copy the remaining elements of right subvector
       (if there are any) to temp*/
    while (j <= right)
        temp[k++] = a[j++];

    /*Copy back the merged elements to original vector*/
    for (i = left; i <= right; i++)
        a[i] = temp[i];

    return inversionCount;
}


