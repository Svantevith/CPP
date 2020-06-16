#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

struct Node* leastCommonAncestor(struct Node* root, int n1, int n2)
{
    // If the root of the tree does not exist, the height is always 0
    if (root == nullptr)
    {
        return nullptr;
    }
        // If any of the root->data equal to n1 or n2, that root is LCA
    else if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    else
    {
        struct Node* leftLCA = leastCommonAncestor(root->left, n1, n2);
        struct Node* rightLCA = leastCommonAncestor(root->right, n1, n2);
        // if the root has both left and right root, then this root is LCA
        if (leftLCA && rightLCA)
        {
            return root;
        }
        else
        {
            // Otherwise if left branch exists, find LCA for left branch,
            // if left branch does not exists, find LCA for right branch
            return (leftLCA != nullptr) ? leftLCA : rightLCA;
        }
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    int n1 = 2;
    int n2 = 4;
    cout << "Least common ancestor of " << n1 << " and " << n2 << " is " << leastCommonAncestor(root, n1, n2)->data << endl;
    return 0;
}