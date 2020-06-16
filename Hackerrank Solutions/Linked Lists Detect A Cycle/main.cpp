#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
using namespace std;

int sizeOfList = 0;

struct Node
{
    int data;
    struct Node* next;
    Node(int new_data)
            : data(new_data), next(nullptr)
    {
        sizeOfList++;
    }
};

struct LinkedList
{
    static bool hasLoop(Node** head)
    {
        if (*head == nullptr)
        {
            return false;;
        }
        else
        {
            Node* slow = *head;
            Node* fast = slow->next;
            while (slow != fast)
            {
                if (fast == nullptr || fast->next == nullptr)
                {
                    return false;
                }
                else
                {
                    slow = slow->next;
                    fast = fast->next->next;
                }
            }
        }
        return true;
    }

    static void printList(Node* node)
    {
        while (node != nullptr)
        {
            cout << node->data << " -> ";
            node = node->next;
        }
        cout << endl;
    }
};

int main()
{
    Node* head = new Node(11);
    head->next = new Node(9);
    head->next->next = new Node(19);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(4);
    if (LinkedList::hasLoop(&head))
    {
        cout << "There is a loop" << endl;
    }
    else
    {
        cout << "There is no loop" << endl;
    }
    delete head;
    head = nullptr;
    system("pause");
}