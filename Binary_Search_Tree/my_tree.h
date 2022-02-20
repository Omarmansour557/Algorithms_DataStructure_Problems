#ifndef MY_TREE_H
#define MY_TREE_H

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

template <class T>
class MyTree
{

public:
    struct node
    {
        T key;
        node *left;
        node *right;
        // this only because the implementation of the post_order_it
        bool visited = false;
    };

    node *root;

public:
    /* default constructor */
    MyTree()
    {
        root = NULL;
    }

    /* parametrized constructor */

    MyTree(vector<T> elements)
    {
        sort(elements.begin(), elements.end());
        root = sortedArrayToBST(elements, 0, elements.size() - 1);
    }

    node *sortedArrayToBST(vector<T> &elements, int start, int end)
    {

        /* Base Case */
        if (start > end)
            return NULL;

        /* Get the middle element and make it root */
        int mid = (start + end) / 2;
        node *root = newNode(elements[mid]);

        /* Recursively construct the left subtree
        and make it left child of root */
        root->left = sortedArrayToBST(elements, start,
                                      mid - 1);

        /* Recursively construct the right subtree
        and make it right child of root */
        root->right = sortedArrayToBST(elements, mid + 1, end);

        return root;
    }

    node *newNode(int key)
    {
        node *node1 = new node();
        node1->key = key;
        node1->left = NULL;
        node1->right = NULL;

        return node1;
    }

    /* creating new node that point to root and this node will iterate in the tree*/
    bool search(T value, node *root)
    {
        node *nodePtr = root;
        bool status = false;

        while (nodePtr)
        {
            if (nodePtr->key == value)
            {
                status = true;
                return status;
            }

            else if (nodePtr->key < value)
            {

                // search right
                nodePtr = nodePtr->right;
            }
            else
            {

                // search left
                nodePtr = nodePtr->left;
            }
        }
        return status;
    }
    bool search(T value)
    {
        bool status = search(value, root);
        return status;
    }

    // this function is recursive till it find the leaf either in the right or left.
    void insert_node(node *&root, node *&newNode)
    {
        if (root == NULL)
        {
            root = newNode;
        }
        else if (root->key < newNode->key)
        {
            // search for right
            insert_node(root->right, newNode);
        }

        else
        {
            // search for left.
            insert_node(root->left, newNode);
        }
    }

    void insert(T key)
    {

        node *newNode = NULL; // this a pointer to a new node.

        // store the key in the new node
        newNode = new node;
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        insert_node(root, newNode);
    }
    void inorder_rec(node *nodePtr)
    {
        if (nodePtr)
        {
            inorder_rec(nodePtr->left);
            cout << nodePtr->key << " ";
            inorder_rec(nodePtr->right);
        }
    }
    void inorder_rec()
    {
        inorder_rec(root);
    }

    void preorder_rec(node *nodePtr)
    {
        if (nodePtr)
        {
            cout << nodePtr->key << " ";
            preorder_rec(nodePtr->left);
            preorder_rec(nodePtr->right);
        }
    }
    void preorder_rec()
    {
        preorder_rec(root);
    }

    void postorder_rec(node *nodePtr)
    {
        if (nodePtr)
        {
            postorder_rec(nodePtr->left);
            postorder_rec(nodePtr->right);
            cout << nodePtr->key << " ";
        }
    }
    void postorder_rec()
    {

        postorder_rec(root);
    }
    void inorder_it(node *root)
    {
        /* the idea in this function is to find  a way to raturn back to the root after going to the left of the tree
            so we can use morris way as after going to the node get the predessor of it first then attach it to the current
            and make the current = current->left.
        */
        node *prev;
        node *current;
        if (root == NULL)
            return;

        current = root;

        while (current != NULL)
        {
            if (current->left == NULL)
            {
                cout << current->key << " ";
                current = current->right;
            }
            else
            {
                prev = current->left;
                // git the predecessor of the current node
                while (prev->right != NULL && prev->right != current)
                    prev = prev->right;

                // attach the right of the predecessor to the current then make current = current->left.
                if (prev->right == NULL)
                {
                    prev->right = current;
                    current = current->left;
                }

                else
                {
                    // here we hit the node two times which mean that the left subtree traversed.
                    prev->right = NULL;
                    cout << current->key << " ";
                    current = current->right;
                }
            }
        }
    }

    void inorder_it()
    {
        inorder_it(root);
    }

    void preorder_it(node *root)
    {
        /* this is the same as inorder but the change here is instead of printing the node after reach the most left of the tree
        we print the node before we rich the left.
        */
        node *prev;
        node *current;
        if (root == NULL)
            return;

        current = root;

        while (current != NULL)
        {
            if (current->left == NULL)
            {
                cout << current->key << " ";
                current = current->right;
            }
            else
            {
                prev = current->left;
                // git the predecessor of the current node
                while (prev->right != NULL && prev->right != current)
                    prev = prev->right;

                // attach the right of the predecessor to the current then make current = current->left.
                if (prev->right == NULL)
                {
                    prev->right = current;
                    // this is a change
                    cout << current->key << " ";
                    current = current->left;
                }

                else
                {
                    // here we hit the node two times which mean that the left subtree traversed.
                    prev->right = NULL;

                    current = current->right;
                }
            }
        }
    }

    void preorder_it()
    {
        preorder_it(root);
    }

    void postorder_it(node *head)
    {
        node *temp = head;
        while (temp && temp->visited == false)
        {

            // visit the left subtree
            if (temp->left && temp->left->visited == false)
            {
                temp = temp->left;
            }
            // visit the right subtree
            else if (temp->right && temp->right->visited == false)
            {
                temp = temp->right;
            }
            // visit node
            else
            {
                cout << temp->key << " ";
                temp->visited = true;
                temp = head;
            }
        }
    }

    void postorder_it()
    {
        postorder_it(root);
    }
    void breadth_traversal(node *root)
    {
        if (root == NULL)
            return;
        queue<node *> q;
        // push root into the queue
        q.push(root);
        while (q.empty() == false)
        {
            // display the front then remove it
            node *node1 = q.front();
            cout << node1->key << " ";
            q.pop();

            if (node1->left != NULL)
                q.push(node1->left);
            if (node1->right != NULL)
                q.push(node1->right);
        }
    }
    void breadth_traversal()
    {
        breadth_traversal(root);
    }

    int size(node *ptrNode)
    {

        if (ptrNode == NULL)
            return 0;
        else
        {
            return (1 + size(ptrNode->right) + size(ptrNode->left));
        }
    }
    int size()
    {

        return size(root);
    }

    void remove(T num)
    {
        deleteNode(num, root);
    }
    //********************************************
    // deleteNode deletes the node whose value *
    // member is the same as num. *
    //********************************************
    void deleteNode(T num, node *&nodePtr)
    {
        if (num < nodePtr->key)
        {
            deleteNode(num, nodePtr->left);
        }
        else if (num > nodePtr->key)
        {
            deleteNode(num, nodePtr->right);
        }
        else
        {
            makeDeletion(nodePtr);
        }
    }
    //***********************************************************
    // makeDeletion takes a reference to a pointer to the node that is to be deleted. *
    // The node is removed and the branches of the tree below the node are reattached. *
    //***********************************************************

    void makeDeletion(node *&nodePtr)
    {

        // Temporary pointer, used in reattaching the left subtree.
        node *tempNodePtr = NULL;
        if (nodePtr == NULL)
        {
            cout << "Cannot delete empty node.\n";
        }
        else if (nodePtr->right == NULL)
        {
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->left; // Reattach the left child
            delete tempNodePtr;
        }
        else if (nodePtr->left == NULL)
        {
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->right; // Reattach the right child
            delete tempNodePtr;
        }
        // If the node has two children.
        else
        {
            // Move one node the right.
            tempNodePtr = nodePtr->right;
            // Go to the end left node.
            while (tempNodePtr->left)
            {
                tempNodePtr = tempNodePtr->left;
            }
            // cout<<"---------------------------------------------------"<<endl;
            // cout<<"elmfrod 5: "<<tempNodePtr->key<<endl;
            // Reattach the left subtree.
            tempNodePtr->left = nodePtr->left;
            // cout<<"elmfrod 5: "<<tempNodePtr->key<<endl;

            tempNodePtr = nodePtr;
            // cout<<"elmfrod 4: " <<tempNodePtr->key<<endl;
            // cout<<"elmfrod 4: "<<nodePtr->key<<endl;

            // cout<<"---------------------------------------------------"<<endl;

            // Reattach the right subtree.
            nodePtr = nodePtr->right;
            // cout<<"elfrod 6: "<<nodePtr->key<<endl;
            delete tempNodePtr;
        }

       
    }
};

#endif