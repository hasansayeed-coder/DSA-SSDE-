#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node *findNthNode(Node *temp, int k)
{
    int cnt = 1;

    while (temp->next != NULL)
    {
        if (cnt == k)
            return temp;

        cnt++;

        temp = temp->next;
    }

    return temp;
}

Node *rotate(Node *head, int k)
{

    if (head == NULL || k == 0)
        return head;

    Node *tail = head;

    int len = 1;

    while (tail->next != NULL)
    {
        tail = tail->next;
        len++;
    }

    if (k % len == 0)
        return head;

    k = k % len;

    tail->next = head;
    Node *newLastNode = findNthNode(head, len - k);

    head = newLastNode->next;
    newLastNode->next = NULL;

    return head;
}
