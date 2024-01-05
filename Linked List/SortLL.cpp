#include<bits/stdc++.h>
using namespace std ;

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

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    Node *res = new Node(-1);
    Node *temp = res;

    while (left && right)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }

        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    res = res->next;

    return res;
}

Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *sortList(Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    Node *mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = sortList(left);
    right = sortList(right);

    // merge two part
    Node *ans = merge(left, right);

    return ans;
}
