#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *sortList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *head_0 = new Node(-1);
    Node *head_1 = new Node(-1);
    Node *head_2 = new Node(-1);

    Node *move_0 = head_0;
    Node *move_1 = head_1;
    Node *move_2 = head_2;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            move_0->next = temp;
            move_0 = move_0->next;
        }

        else if (temp->data == 1)
        {
            move_1->next = temp;
            move_1 = move_1->next;
        }

        else
        {
            move_2->next = temp;
            move_2 = move_2->next;
        }

        temp = temp->next;
    }

    if (move_0->data != -1)
    {
        move_0->next = head_1->next;
    }

    if (move_1->data != -1)
    {
        move_1->next = head_2->next;
    }

    move_2->next = NULL;

    if (move_0->data != -1)
        head = head_0->next;
    else if (move_1->data != -1)
        head = head_1->next;
    else
    {
        head = head_2->next;
    }

    return head;
}
