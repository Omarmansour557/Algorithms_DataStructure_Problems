#ifndef MY_PQ_H
#define MY_PQ_H

#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

class My_PQ
{

public:
    vector<int> heap;

    My_PQ()
    {
        heap.push_back(0);
    }

    My_PQ(vector<int> arr)
    {
        // sort(arr.begin(), arr.end(), greater<int>());
        for (int i = 0; i < arr.size(); i++)
        {
            insert(arr[i]);
        }
    }
    int parent(int index)
    {
        return ceil((index - 1) / 2);
    }
    int leftChild(int index)
    {
        return (index * 2 + 1);
    }
    int rightChild(int index)
    {
        return (index * 2 + 2);
    }
    void siftUP(int index)
    {

        while (index > 0 && heap[index] > heap[parent(index)])
        {

            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void siftDown(int index)
    {
        // cout<<"-----"<<heap[3];
        int i = index;
        int leftOFIndex = leftChild(index);
        int rightOfIndex = rightChild(index);

        if (leftOFIndex < heap.size() && heap[leftOFIndex] > heap[i])
        {
            i = leftOFIndex;
        }
        if (rightOfIndex < heap.size() && heap[rightOfIndex] > heap[i])
        {
            i = rightOfIndex;
        }
        if (i != index)
        {
            swap(heap[i], heap[index]);
            siftDown(i);
        }
    }

    int extract_max()
    {
        int result = heap[0];
        //    cout<<"heap Size is: "<<heap.size()<<endl;
        swap(heap[0], heap[heap.size() - 1]);
        // cout<<" after swaping -------" << endl;
        // printHeap();

        heap.pop_back();
        // cout<<"after pop_back"<<endl;
        // printHeap();

        siftDown(0);
        // cout<<endl;
        // printHeap();

        return result;
    }

    void change_priority(int index, int new_priority)
    {
        int old = heap[index];
        heap[index] = new_priority;
        if (old < new_priority)
            siftUP(index);
        else
            siftDown(index);
    }

    int peek()
    {
        return heap[0];
    }

    void insert(int value)
    {

        heap.push_back(value);
        siftUP(heap.size() - 1);
    }

    void remove(int index)
    {
        heap[index] = INT_MAX;
        siftUP(index);
        // cout<<"------------ after siftUP"<<endl;
        // printHeap();
        // cout<<endl;
        // cout<<"-------------------------"<<endl;

        extract_max();
    }
    int heapSize()
    {
        return heap.size();
    }

    void printHeap()
    {

        for (int i = 0; i < heap.size(); i++)
        {
            cout << heap[i] << " ";
        }
    }

    void extractMaxForAll()
    {
        int size = heap.size();
        for (int i = 0; i < size; i++)
        {
            int x = extract_max();
            cout << x << " ";
        }
    }
};

#endif