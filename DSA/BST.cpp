#include <iostream>
using namespace std;

class BST
{
    int data;
    BST *right;
    BST *left;

public:
    int getData()
    {
        return this->data;
    }
    BST()
    {
        this->data = 0;
        this->right = NULL;
        this->left = NULL;
    }
    BST(int data)
    {
        this->data = data;
    }
    BST *insert(BST *root, int value)
    {
        if (root == NULL)
        {
            return new BST(value);
        }

        if (value > root->data)
        {
            root->right = insert(root->right, value);
        }
        else
        {
            root->left = insert(root->left, value);
        }
        return root;
    }
    static void inOrder(BST *root)
    {
        if (root == NULL)
        {
            return;
        }
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    static void preOrder(BST *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    static void postOrder(BST *root)
    {
        if (root == NULL)
        {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    static BST *searchNode(BST *&root, int key)
    {

        if (root == NULL || root->data == key)
        {
            return root;
        }

        if (root->data < key)
        {
            return searchNode(root->right, key);
        }

        return searchNode(root->left, key);
    }

    static void deleteKey(BST *&root, int key)
    {
        root = deleteRec(root, key);
    }

    static BST *deleteRec(BST *&root, int key)
    {
        if (root == NULL)
            return root;

        if (key < root->data)
            root->left = deleteRec(root->left, key);
        else if (key > root->data)
            root->right = deleteRec(root->right, key);

        else
        {
            if (root->left == NULL)
                return root->right;
            else if (root->right == NULL)
                return root->left;

            root->data = minValue(root->right);

            root->right = deleteRec(root->right, root->data);
        }

        return root;
    }

    static int minValue(BST *&root)
    {
        int minv = root->data;
        while (root->left != NULL)
        {
            minv = root->left->data;
            root = root->left;
        }
        return minv;
    }
};

int main()
{
    BST b, *root = NULL;
    root = b.insert(root, 30);
    b.insert(root, 12);
    b.insert(root, 32);
    b.insert(root, 14);
    b.insert(root, 31);

    cout << "In Order ";
    BST::inOrder(root);
    cout << endl;
    cout << "Pre Order ";
    BST::preOrder(root);
    cout << endl;
    cout << "Post Order ";
    BST::postOrder(root);
    cout << endl;
    cout << "Searching for node with value 14:\n";
    BST *node = BST::searchNode(root, 14);
    cout << "Printing value:" << node->getData() << endl;

    cout << "Deleting node with value 32: \n";
    BST::deleteKey(root, 32);
    cout << "In Order ";
    BST::inOrder(root);
    cout << endl;

    return 0;
}
