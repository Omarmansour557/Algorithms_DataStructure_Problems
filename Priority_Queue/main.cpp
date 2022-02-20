#include <iostream>
#include "my_pq.h"
using namespace std;

int main(int argc, char **argv)
{
    int index1 = -1;
    int root = 0;
    int size = 0;
    int operations = 0;

    cin >> size >> operations;

    vector<int> a(size);

    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    My_PQ PQ(a);

    for (int i = 0; i < operations; i++)
    {
        int x, y = 0;
        cin >> x;
        switch (x)
        {
        case 1:
            cin >> y;
            PQ.insert(y);
            cout << endl;
            break;
        case 2:

            cin >> index1 >> y;
            PQ.change_priority(index1, y);
            cout <<endl;
            break;
        case 3:
            cin >> y;
            PQ.remove(y);
            cout << endl;
            break;

        case 4:
            root = PQ.extract_max();
            cout << root << " " << endl;
            break;

        case 5:

            cout << PQ.peek() << " " << endl;
            break;

        case 6:
            PQ.extractMaxForAll();

            cout << endl;

            break;
        case 7:
            cout << PQ.heapSize()<< " "<<endl;
            

            break;
        }
    }

    return 0;
}