#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}
void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void deleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}
void deletion(node *&head, int pos)
{

    int count = 1;
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {

        temp->next->prev = temp->prev;
    }
    delete temp;
}
int length(node *&head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}
node *kappend(node *&head, int k)
{
    node *newhead;
    node *newtail;
    node *tail = head;

    int l = length(head);
    k = k % l;
    int count = 1;
    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newtail = tail;
        }
        if (count == l - k + 1)
        {
            newhead = tail;
        }
        tail = tail->next;
        count++;
    }
    newtail->next = NULL;
    tail->next = head;
    return newhead;
}
int inersection(node *&head1, node *&head2)
{
    int l1 = length(head1);
    int l2 - length(head2);

    node *ptr1;
    node *ptr2;
    int d = 0;
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (d--)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}
int main()
{
    node *head = NULL;
    insertAtHead(head, 5);
    insertAtTail(head, 4);
    insertAtTail(head, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    insertAtTail(head, 0);

    display(head);
    cout << endl;
    display(kappend(head, 2));
    return 0;
}