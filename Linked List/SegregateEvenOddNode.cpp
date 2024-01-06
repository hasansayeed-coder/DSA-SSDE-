#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr){};
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node *segregateEvenOdd(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *odd = NULL;
    Node *even = NULL;
    Node *evenHead = NULL;
    Node *temp = head;
    Node *oddHead = NULL;

    while (temp != NULL)
    {
        int val = temp->data;

        if (val % 2 == 0)
        {
            if (even == NULL)
            {

                even = temp;
                evenHead = temp;
            }

            else
            {
                even->next = temp;
                even = even->next;
            }
        }

        else
        {
            if (odd == NULL)
            {
                odd = temp;
                oddHead = temp;
            }

            else
            {
                odd->next = temp;
                odd = odd->next;
            }
        }

        temp = temp->next;
    }

    even->next = oddHead;
    odd->next = NULL;

    return evenHead;
}
