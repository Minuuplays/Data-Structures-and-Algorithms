#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node():data(0), next(NULL){}

    Node (int data){
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
    Node* head;
    
public:
    LinkedList():head(NULL) {}

    void insertFirst(int x)
    {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    void insertAfter(int key, int x)
    {
        Node* temp = head;
        while(temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "VALUE NOT FOUND !!" << endl;
            return;
        }

        Node* newNode = new Node(x);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertBefore(int key, int x)
    {
        if (head == NULL)
        {
            cout << "LIST IS EMPTY !!" << endl;
            return;
        }

        if (head->data == key)
        {
            insertFirst(x);
            return;
        }

        Node* prev = NULL;
        Node* temp = head;

        while (temp != NULL && temp->data != key)
        { 
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "VALUE NOT FOUND !!" << endl;
            return;
        }

        Node* newNode = new Node(x);
        newNode->next = temp;
        prev->next = newNode;
    }

    void insertAtPosition(int pos, int x)
    {
        if (pos <= 0)
        {
            cout << "INVALID POSITION !!" << endl;
            return;
        }

        if (pos == 1)
        {
            insertFirst(x);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        } 

        if (temp == NULL)
        {
            cout << "POSITION OUT OF RANGE !!" << endl;
            return;
        }

        Node* newNode = new Node(x);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertLast(int x)
    {
        Node* newNode = new Node(x);
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)       
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteFirst()
    {
        if (head == NULL)
        {
            cout << "LIST IS EMPTY !!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast()
    {
        if (head == NULL)    
        {
            cout << "LIST IS EMPTY !!" << endl;
            return;
        } 
        
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void deleteAtValue(int key) 
    {
        if (head == NULL)   
        {
            cout << "LIST IS EMPTY !!" << endl;
            return;
        }

        if (head->data == key)
        {
            deleteFirst();
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            cout << "VALUE NOT FOUND !!" << endl;
            return;
        }

        Node* Delet = temp->next;
        temp->next = Delet->next;
        delete Delet;
    }

    void deleteAtPosition(int pos)
    {
        if (head == NULL)
        {
            cout << "LIST IS EMPTY !!" << endl;
            return;
        }

        if (pos <= 0)
        {
            cout << "INVALID POSITION !!" << endl;
            return;
        }

        if (pos == 1)        
        {
            deleteFirst();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }  

        if (temp == NULL || temp->next == NULL)
        {
            cout << "POSITION OUT OF RANGE !!" << endl;
            return;
        }

        Node* Delet = temp->next;
        temp->next = Delet->next;
        delete Delet;
    }

    void searchValue(int x)
    {
        int pos = 1;
        Node* temp = head;

        while(temp != NULL)
        {
            if (temp->data == x)
            {
                cout << "Value found at position : " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }

        cout << "Value Not Found !!" << endl;
    }

    void printList()
    {
        Node* temp = head;
        if(head == NULL)
        {
            cout << "EMPTY !!" << endl;
            return;
        }

        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->next != NULL) cout << " -> ";
            temp = temp->next;
        }

        cout << " -> NULL" << endl;
    }

    void printReverse(Node* node)
    {
        if (node == NULL) return;
        printReverse(node->next);
        cout << node->data;
        if (node != head) cout << " ";
    }

    void printReverse()
    {
        if (head == NULL)
        {
            cout << "EMPTY !!" << endl;
            return;
        }
        printReverse(head);
        cout << endl;
    }

    void listSize()
    {
        int count = 0;
        Node* temp = head;

        while(temp != NULL)
        {
            temp = temp->next;
            count++;
        }

        cout << "Size of the linked list : " << count << endl;
    }

    int getMiddle()   // ...... 
    {
        if (head == NULL)
        {
            cout << "LIST IS EMPTY !!" << endl;
            return -1;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Middle element : " << slow->data << endl;
        return slow->data;
    }

    bool hasCycle()         // .....
    {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                cout << "Cycle DETECTED !!" << endl;
                return true;
            }
        }

        cout << "No cycle found." << endl;
        return false;
    }

    void clearList()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = NULL;
        cout << "List cleared." << endl;
    }

    ~LinkedList()
    {
        clearList();
    }
};


int main()
{
    LinkedList ll;

    cout << "=== INSERT ===" << endl;
    ll.insertLast(10);
    ll.insertLast(20);
    ll.insertLast(30);
    ll.insertFirst(5);
    ll.insertAfter(10, 15);
    ll.insertAtPosition(4, 25);
    ll.printList();       // 5 -> 10 -> 15 -> 25 -> 20 -> 30 -> NULL

    cout << "\n=== SIZE ===" << endl;
    ll.listSize();

    cout << "\n=== SEARCH ===" << endl;
    ll.searchValue(25);
    ll.searchValue(99);

    cout << "\n=== MIDDLE ===" << endl;
    ll.getMiddle();

    cout << "\n=== DELETE ===" << endl;
    ll.deleteFirst();
    ll.deleteLast();
    ll.deleteAtValue(15);
    ll.deleteAtPosition(2);
    ll.printList();

    cout << "\n=== REVERSE PRINT ===" << endl;
    ll.printReverse();

    cout << "\n=== CYCLE CHECK ===" << endl;
    ll.hasCycle();

    cout << "\n=== CLEAR ===" << endl;
    ll.clearList();
    ll.printList();

    return 0;
}