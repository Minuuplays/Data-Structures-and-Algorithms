#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data; 
    Node* left;
    Node* right;

    Node (int a=0):data(a), left(NULL), right(NULL){}
};

class BST{
    Node* root;

    Node* insertHelper(Node* node, int value)
    {
        if (node == NULL)
        {
            return new Node(value);
        }
        if (value < node->data)
        {
            node->left = insertHelper(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertHelper(node->right, value);
        }
        return node;
    }

     Node* searchHelper(Node* node, int value)
    {
        if (node == NULL || node->data == value)
        {
            return node;
        }

        if (node->data < value)
        {
            return searchHelper(node->right, value);
        }

        return searchHelper(node->left, value);
    }

    Node* findMin(Node* node)
    {
        Node* current = node;
        while (current && current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    Node* deleteHelper(Node* node, int value)
    {
        if (node == nullptr) return node;

        if (value < node->data)
        {
            node->left = deleteHelper(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = deleteHelper(node->right, value);
        }
        else
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteHelper(node->right, temp->data);
        }
        return node;
    }

    void inorderHelper(Node* node)
    {
        if (node != nullptr)
        {
            inorderHelper(node->left);           // Left
            cout << node->data << " ";      // Root
            inorderHelper(node->right);          // Right
        }
    }

    void preorderHelper(Node* node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";      // Root
            preorderHelper(node->left);          // Left
            preorderHelper(node->right);         // Right
        }
    }

    void postorderHelper(Node* node)
    {
        if (node != nullptr)
        {
            postorderHelper(node->left);         // Left
            postorderHelper(node->right);        // Right
            cout << node->data << " ";      // Root
        }
    }

public:
    BST():root(NULL){}

    void insert(int value)
    {
        root = insertHelper(root, value);
    }

    bool search(int value)
    {
        return searchHelper(root, value) != nullptr;
    }

    void remove(int value)
    {
        root = deleteHelper(root, value);
    }

    void displayInorder()
    {
        cout << "Inorder Traversal: ";
        inorderHelper(root);
        cout << endl;
    }

    void displayPreorder()
    {
        cout << "Preorder Traversal: ";
        preorderHelper(root);
        cout << endl;
    }

    void displayPostorder()
    {
        cout << "Postorder Traversal: ";
        postorderHelper(root);
        cout << endl;
    }
};


int main()
{
    BST b1;

    cout << "Insertion ::" << endl;
    int values[] = {50, 30, 20, 40, 70, 60, 80};

    for (auto v : values)
    {
        b1.insert(v);
    }
    cout << endl;

    cout << "Searching ::" << endl;
    int Key1 = 20;
    int Key2 = 72;
    cout << (b1.search(Key1) ? "Found" : "Not Found") << endl;
    cout << (b1.search(Key2) ? "Found" : "Not Found") << endl;
    cout << endl;

    cout << "Deletion ::" << endl;
    cout << "Deleting 20 (Leaf Node)..." << endl;
    b1.remove(20);

    cout << "Deleting 30 (Node with one child)..." << endl;
    b1.remove(30);

    cout << "Deleting 50 (Node with two children)..." <<endl;
    b1.remove(50);

    b1.displayInorder();

    cout << "Deleting 30 (Node with one child)..." << endl;
    b1.remove(30);
    b1.displayInorder();

    cout << "Deleting 50 (Node with two children)..." <<endl;
    b1.remove(50);
    b1.displayInorder();

    return 0;
}