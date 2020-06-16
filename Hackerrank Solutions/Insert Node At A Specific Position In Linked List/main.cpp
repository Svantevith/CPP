#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

int sizeOfList = 0;

struct Node* newNode(int newData)
{
    Node* newNode = new Node(); // malloc is C, not C++!!!
    newNode->data = newData;
    newNode->next = nullptr;
    ++sizeOfList;
    return newNode;
}

void insert(Node** current_node, int position, int new_data)
{
    // Check if given position is valid
    // Positions are indexed from 0 in Linked List !
    if (position < 0 || position > sizeOfList + 1)
    {
        cout << "Invalid position!" << endl;
    }
    else
    {
        while (position >= 0)
        {
            if (position == 0)
            {
                Node* new_node = newNode(new_data);
                new_node->next = *current_node;
                *current_node = new_node;
                break;
            }
            else
            {
                current_node = &(*current_node)->next;
                position--;
            }
        }
    }
}

void printList(Node* node)
{
    while (node != nullptr)
    {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    printList(head);
    insert(&head, 3, 5);
    printList(head);
    system("pause");
}