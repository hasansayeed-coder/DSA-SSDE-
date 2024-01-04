#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node *deleteAllOccurrences(Node *head, int k)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == k)
        {
            if (temp == head)
            {
                head = temp->next;
            }
            Node *previousNode = temp->prev;
            Node *nextNode = temp->next;

            if (previousNode != NULL)
                previousNode->next = nextNode;
            if (nextNode != NULL)
                nextNode->prev = previousNode;

            free(temp);
            temp = temp->next;
        }

        else
        {
            temp = temp->next;
        }
    }

    return head;
}
