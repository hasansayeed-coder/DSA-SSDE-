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

int length(Node *head)
{
    Node *temp = head;

    int length = 1;

    while (temp->next != NULL)
    {
        temp = temp->next;
        length++;
    }

    return length;
}