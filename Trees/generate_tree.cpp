#include<iostream>
#include<vector>
using namespace std;

struct Node{
    struct Node *Lchild;
    int data;
    struct Node *Rchild;
};
typedef struct Node NODE;

struct Stack{
    struct Node *node;
    struct Stack *next;
};
typedef struct Stack STACK;
STACK *top = nullptr;

void push_stack(NODE *node);
NODE* pop_stack(void);
void preorder_display(NODE *node);
int find_inorder_root_index(int *inorder, int in_start, int in_end, int root_element);
NODE* construct_tree(int* preorder, int* inorder, int pre_start, int pre_end, int in_start, int in_end); 
NODE* generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd);

int main(void)
{
    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
    
    //size of preorder and inorder arrays are same
    int size = sizeof(preorder)/sizeof(preorder[0]);

    NODE* root = construct_tree(preorder, inorder, 0, size - 1, 0, size - 1);
    preorder_display(root);
    cout << endl;

    root = generateFromTraversal(inorder, preorder, 0, size - 1);
    preorder_display(root);
    cout << endl;

    return 0;
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

void preorder_display(NODE *node)
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

int find_inorder_root_index(int *inorder, int in_start, int in_end, int root_element)
{
    for(int index = in_start; index <= in_end; index++)
    {
        if(inorder[index] == root_element)
            return index;
    }
}

NODE* construct_tree(int* preorder, int* inorder, int pre_start, int pre_end, int in_start, int in_end)
{
    if(in_start > in_end)
    {
        return nullptr;
    }
    else
    {
        int root_element = preorder[pre_start];
        int root_inorder_index = find_inorder_root_index(inorder, in_start, in_end, root_element);

        NODE *root = new NODE;

        root->data = root_element;

        int Lin_st = in_start;
        int Lin_end = root_inorder_index - 1;
        int Lpre_st = pre_start + 1;
        int Lpre_end = Lpre_st + (Lin_end - Lin_st);
        int Rpre_st = Lpre_end + 1;
        int Rpre_end = pre_end;
        int Rin_st = root_inorder_index + 1;
        int Rin_end = in_end;

        root->Lchild = construct_tree(preorder, inorder, Lpre_st, Lpre_end, Lin_st, Lin_end);
        root->Rchild = construct_tree(preorder, inorder, Rpre_st, Rpre_end, Rin_st, Rin_end);

        return root;
    }
}

NODE* generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd) 
{
    static int preIndex = 0;
 
    if (inStart > inEnd){
        return nullptr;
    }
 
    Node* node = new Node;
    node->data = preorder[preIndex++];
 
    int splitIndex = find_inorder_root_index(inorder, inStart, inEnd, node->data);
    node->Rchild = generateFromTraversal(inorder, preorder, inStart, splitIndex-1);
    node->Lchild = generateFromTraversal(inorder, preorder, splitIndex+1, inEnd);
 
    return node;
}
