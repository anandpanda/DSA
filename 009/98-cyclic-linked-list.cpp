#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = this;
    }
    ~Node()
    {
        int value = data;
        if (next != NULL)
            next = NULL;
        cout << "Delete Node with data : " << value << endl;
    }
};

// insert after element
void insert(Node *&head, int element, int data)
{
    // empty list
    if (head == NULL)
    {
        cout << "List Empty. Inserted Data" << endl;
        Node *newNode = new Node(data);
        head = newNode;
        newNode->next = newNode;
    }
    else
    {
        bool elementFound = false;
        Node *end = NULL;
        Node *ele = head;
        do
        {
            if (ele->data == element)
            {
                elementFound = true;
                Node *newNode = new Node(data);
                newNode->next = ele->next;
                ele->next = newNode;
                break;
            }
            end = ele;
            ele = ele->next;
        } while (ele != head);

        if (!elementFound)
        {
            cout << "Element not found. Inserted Data" << endl;
            Node *newNode = new Node(data);
            newNode->next = end->next;
            end->next = newNode;
        }
    }
}

// delete node
void dn(Node *&head, int element)
{
    if (head == NULL)
        cout << "List Empty. Inserted Data" << endl;
    else if (element == head->data)
    {
        Node *ele = head;
        while (ele->next != head)
            ele = ele->next;

        Node *del = head;
        head = head->next;
        ele->next = head;

        delete del;
    }
    else
    {
        bool elementFound = false;
        Node *found = NULL;
        Node *ele = head;
        do
        {
            if ((ele->next)->data == element)
            {
                found = ele->next;
                ele->next = (ele->next)->next;
                delete found;
                break;
            }
            ele = ele->next;
        } while (ele != head);

        if (!found)
            cout << "Element not found." << endl;
    }
}

void display(Node *head)
{
    if (head == NULL)
        cout << "List is Empty." << endl;
    else
    {
        Node *newNode = head;
        do
        {
            cout << newNode->data << " ";
            newNode = newNode->next;
        } while (newNode != head);
        cout << endl;
    }
}

bool isCircular(Node *head)
{
    if (head == NULL) //empty
        return true;
    Node *temp = head->next;
    while (temp != NULL && temp != head)
        temp = temp->next;
    if (temp == head)
        return true;
    return false;
}

int main()
{
    Node *head = NULL;
    insert(head, 0, 1);
    insert(head, 0, 2);
    insert(head, 0, 3);
    insert(head, 1, 0);
    insert(head, 2, 4);
    insert(head, 2, 4);
    insert(head, 4, 6);
    display(head);

    dn(head, 4);
    display(head);

    dn(head, 5);
    display(head);

    dn(head, 1);
    display(head);

    cout<<isCircular(head);

    return 0;
}