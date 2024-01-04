#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    stack<int> st;
    Node *current = head;

    while (current)
    {
        st.push(current->data);
        current = current->next;
    }

    current = head;

    while (!st.empty())
    {
        int value = st.top();
        st.pop();

        current->data = value;
        current = current->next;
    }

    return head;
}
