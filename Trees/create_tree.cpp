#include<iostream>
#include<vector>
using namespace std;

struct Node{
    struct Node *Lchild;
    int data;
    struct Node *Rchild;
};
typedef struct Node NODE;
NODE *root;

static vector <NODE *> ptr_queue;
static int current_index = 0;

//could have used a queue using linked lists. That way you can save space by dequeueing (deleting) the node in the queue

void create_Lchild(void);
void create_Rchild(void);
void create_tree(void);
void preorder(NODE *node);
void inorder(NODE *node);
void postorder(NODE *node);

int main(void)
{
    create_tree();
    cout << "Preorder traversal:" << endl;
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    return 0;
}

void create_Lchild(void)
{
    NODE *left_child = new NODE;
    ptr_queue.push_back(left_child);
    ptr_queue.at(current_index)->Lchild = left_child;
    cout << "Enter data:" << endl;
    cin >> left_child->data;
    left_child->Lchild = nullptr;
    left_child->Rchild = nullptr;
}

void create_Rchild(void)
{
    NODE *right_child = new NODE;
    ptr_queue.push_back(right_child);
    ptr_queue.at(current_index)->Rchild = right_child;
    cout << "Enter data:" << endl;
    cin >> right_child->data;
    right_child->Lchild = nullptr;
    right_child->Rchild = nullptr;
}

void create_tree(void)
{
    root = new NODE;
    cout << "Enter data for root node:" << endl;
    cin >> root->data;
    root->Lchild = nullptr;
    root->Rchild = nullptr;
    ptr_queue.push_back(root);

    char choice;
    cout << "Enter 'Y' to continue else enter 'Q' to quit..." << endl;
    cin >> choice;
    while(choice != 'Q')
    {
        cout << "Enter 'L' to create left child else enter 'N'" << endl;
        cin >> choice;
        if(choice == 'L')
            create_Lchild();
        cout << "Enter 'R' to create left child else enter 'N'" << endl;
        cin >> choice;
        if(choice == 'R')
            create_Rchild();
        current_index++;
        cout << "Enter 'Y' to continue else enter 'Q' to quit..." << endl;
        cin >> choice;
    }
}

void preorder(NODE *node)
{
    if(node != nullptr)
    {
        cout << node->data << " ";
        preorder(node->Lchild);
        preorder(node->Rchild);
    }
}

void inorder(NODE *node)
{
    if(node != nullptr)
    {
        inorder(node->Lchild);
        cout << node->data << " ";
        inorder(node->Rchild); 
    }
}

void postorder(NODE *node)
{
    if(node != nullptr)
    {
        postorder(node->Lchild);
        postorder(node->Rchild);
        cout << node->data << " "; 
    }
}