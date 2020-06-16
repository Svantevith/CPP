#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    explicit Node (int new_data)
    : data(new_data), left(nullptr), right(nullptr)
    {

    }
};

int heightOfBinaryTree(struct Node* root)
{
    // If the root of the tree does not exist, the height is always 0
    if (root == nullptr)
    {
        return 0;
    }
        // If the root exists, the height will depend on right and left branch
    else
    {
        int leftHeight = heightOfBinaryTree(root->left);
        int rightHeight = heightOfBinaryTree(root->right);
        if (leftHeight >= rightHeight)
        {
            return ++leftHeight;
        }
        else
        {
            return ++rightHeight;
        }
    }
}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    cout << heightOfBinaryTree(root) << endl;
    system("pause");
}