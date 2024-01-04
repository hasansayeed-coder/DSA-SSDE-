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

Node *insertAtFirst(Node *list, int newValue)
{
    Node *temp = new Node(newValue, list);
    list = temp;
    return list;
}