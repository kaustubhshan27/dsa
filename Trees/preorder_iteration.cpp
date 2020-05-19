#include<iostream>
#include<vector>
using namespace std;

struct Node{
    struct Node *Lchild;
    int data;
    struct Node *Rchild;
};
typedef struct Node NODE;
NODE *root = nullptr;

static vector <NODE *> ptr_queue;
static int current_index = 0;

struct Stack{
    struct Node *node;
    struct Stack *next;
};
typedef struct Stack STACK;
STACK *top = nullptr;

void push_stack(NODE *node);
NODE* pop_stack(void);

void create_Lchild(void);
void create_Rchild(void);
void create_tree(void);
void preorder(NODE *node);

int main(void)
{
    create_tree();
    cout << "Preorder traversal:" << endl;
    preorder(root);
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

void push_stack(NODE *node)
{
    STACK *newEle = new STACK;
    newEle->node = node;

    if(top == nullptr)
    {
        top = newEle;
        top->next = nullptr;
    }
    else
    {
        newEle->next = top;
        top = newEle;
    }
}

NODE* pop_stack(void)
{
    if(top == nullptr)
    {
        cout << "Stack is empty" << endl;
        return nullptr;
    }
    else
    {
        STACK *temp = top->next;
        NODE *node_ptr = top->node;
        delete top;
        top = temp;
        return node_ptr;
    }
}

void preorder(NODE *node)
{
    while(node != nullptr || top != nullptr)
    {
        if(node != nullptr)
        {
            cout << node->data << " ";
            push_stack(node);
            node = node->Lchild;
        }
        else
        {
            node = pop_stack();
            node = node->Rchild;
        }
    }
}
