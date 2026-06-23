#include <bits/stdc++.h>   // incompleteee
using namespace std; 

class Node {
public:
    int data;
    Node* next;

    Node():data(0), next(NULL){}

    Node (int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList():head(NULL) {}

    void display()
    {
        Node* temp = head;
        if (temp == NULL)
        {
            cout << "List Empty!!";
            return;
        }
        while (temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertFirst(int x)
    {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    void deleteOdd()
    {
        Node* nextt = head->next;
        Node* prev = head;
        if (prev == NULL)
        {
            cout << "List Empty!!" << endl;
            return;
        }
        while (prev!=NULL)
        {
            if ((nextt->data % 2) != 0)
            {
                prev->next=nextt->next;
            }
            prev = prev->next;
            nextt = nextt->next;
        }

    }
};

int main ()
{
    LinkedList l1;
    cout << "Menu: " << endl;
    cout << " 1.Display\n 2.Insert at First\n 3.Conditional Delete Operation\n 4.Exit" << endl;
    label:
    cout << "Enter Choice :" ;
    int a;
    cin >> a;
    switch (a)
    {
        case 1 :
            cout << "The elements in the list are:\n";
            l1.display();
            goto label;
            break;
        case 2 :
            int x;
            cout << "Enter Value :";
            cin >> x;
            l1.insertFirst(x);
            cout << "Value Inserted successfully!!" << endl;
            goto label;
            break;
        case 3 :
            cout << "Conditional Modification Done!!\n";
            goto label;
            break;
        case 4 :
            cout << "Program terminated !!";
            goto ending;
            break;
        default :
            cout << "Invalid !!" << endl;
            goto label;
    }
    ending:
    return 0;
}