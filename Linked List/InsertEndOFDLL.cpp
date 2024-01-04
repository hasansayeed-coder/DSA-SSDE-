#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *prev;
    Node *next;
    Node() : value(0), prev(nullptr), next(nullptr) {}
    Node(int val) : value(val), prev(nullptr), next(nullptr) {}
    Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
};

Node *insertAtTail(Node *head, int k)
{

    if (head == NULL)
    {
        Node *newNode = new Node(k);
        return newNode;
    }

    Node *newNode = new Node(k);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    newNode->prev = temp;
    newNode->next = nullptr;
    temp->next = newNode;

    return head;
}
