#include<iostream>
#include<vector>
#include<cstdbool>
using namespace std;

struct Node{
    struct Node *Lchild;
    int data;
    struct Node *Rchild;
};
typedef struct Node NODE;
NODE *root = nullptr;

struct Queue{
    struct Node *node;
    struct Queue *next;
};
typedef struct Queue QUEUE;
QUEUE *front = nullptr;
QUEUE *rear = nullptr;

static vector <NODE *> ptr_queue;
static int current_index = 0;

void create_Lchild(void);
void create_Rchild(void);
void create_tree(void);
void enqueue(NODE *node);
NODE *dequeue(void);
bool isQueueEmpty(void);
void level_order(NODE *root);

int main(void)
{
    create_tree();
    cout << "Level Order Traversal:" << endl;
    level_order(root);
    cout << endl;
    return 0;
}

void create_Lchild(void)
{
    NODE *left_child = new NODE;
    ptr_queue.at(current_index)->Lchild = left_child;
    cout << "Enter data:" << endl;
    cin >> left_child->data;
    left_child->Lchild = nullptr;
    left_child->Rchild = nullptr;
    ptr_queue.push_back(left_child);
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

void enqueue(NODE *node)
{
    QUEUE *newEle = new QUEUE;
    newEle->node = node;
    if(front == nullptr)//queue is empty
    {
        front = rear = newEle;
        newEle->next = nullptr;
    }
    else
    {
        rear->next = newEle;
        newEle->next = nullptr;
        rear = newEle;
    }
}

NODE *dequeue(void)
{
    if(front == nullptr)
        cout << "Queue is empty" << endl;
    else
    {
        QUEUE *temp = front->next;
        NODE *node = front->node;
        delete front;
        front = temp;
        return (node);
    }
}

bool isQueueEmpty(void)
{
    if(front == nullptr)
        return true;
    else
        return false;
}

void level_order(NODE *root)
{
    enqueue(root);
    NODE *node;
    while(isQueueEmpty() == false)
    {
        node = dequeue();
        cout << node->data << " ";
        if(node->Lchild != nullptr)
            enqueue(node->Lchild);
        if(node->Rchild != nullptr)
            enqueue(node->Rchild);
    }
}