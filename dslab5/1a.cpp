// Insert the element at the end of linked list and display the list in reverse direction using Recursion
// Approach?
#include <iostream>
using namespace std;

class Node
{
    public:
    Node *next;
    int data;

    Node (int data)
    {
        this->data=data;
        next=NULL;
    }
};

class Linkedlist
{
    private:
    Node *head;
    Node *tail;

    public:

    Linkedlist()
    {
        head=NULL;
        tail=NULL;
    }

    Node *add(int arr[],int n)
    {
        for (int i = 0; i < n; i++)
        {
           Node *n = new Node(arr[i]);
            if(head == NULL)
            {
                head=n;
                tail=n;
            }
            tail->next = n;
            tail = n;

        }
        return head;
    }

    void print (Node *head)
    {
        for(int i=0;i<4;i++)
        {
            cout<<head->data<<" ";
            head = head->next;
        }
    }
};

void printinreverse(Node *head)
{
    if(head == NULL)
    {
        return;
    }

    printinreverse(head->next);
    cout<<head->data<<" ";
    return;
};
int main() {

    int arr[4] = {0,1,2,3};
    Linkedlist obj;
    Node *head = obj.add(arr,4);
    obj.print(head);
    cout<<endl;
    printinreverse(head);
    return 0;
}