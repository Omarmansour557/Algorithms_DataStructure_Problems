#include <iostream>
#include "my_tree.h"
using namespace std;

int main(int argc, char **argv)
{
    int size = 0;
    int operations = 0;

    // cout << "Enter tree size & number of operations: " << endl;
    cin >> size >> operations;

    vector<int> a(size);
    // cout << "Enter the tree elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    MyTree<int> tree(a);

    for (int i = 0; i < operations; i++)
    {
        int x, y = 0;
        cin >> x;
        switch (x)
        {
        case 1:
            cin >> y;
            tree.insert(y);
            cout <<""<< endl;
            break;
        case 2:
            cin >> y;
            cout << tree.search(y) <<" "<< endl;
            break;
        case 3:
            cin >> y;
            if (y == 1)
            {
                tree.inorder_rec();
                cout << endl;
                break;
            }
            else
            {
                tree.inorder_it();
                cout << endl;
                break;
            }

        case 4:
            cin >> y;
            if (y == 1)
            {
                tree.preorder_rec();
                cout << endl;
                break;
            }
            else
            {
                tree.preorder_it();
                cout << endl;
                break;
            }
        case 5:
            cin >> y;
            if (y == 1)
            {
                tree.postorder_rec();
                cout << endl;

                break;
            }
            else
            {
                tree.postorder_it();
                cout << endl;

                break;
            }
        case 6:
            tree.breadth_traversal();
            cout << endl;

            break;
        case 7:
            cout << tree.size() << " " << endl;
            ;
            break;
        case 8:
            cin >> y;
            tree.remove(y);
            cout << endl;
            break;
        }
    }

    return 0;
}