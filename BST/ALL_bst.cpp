#include<iostream>
#include<vector>
#include<cstdbool>
using namespace std;

struct Node{
    struct Node* Lchild;
    int data;
    struct Node* Rchild;
};
typedef struct Node NODE;
NODE *root = nullptr;
NODE *trail = nullptr;

struct stackNode{
    NODE *node;
    struct stackNode *next;
};
typedef struct stackNode STACKNODE;
STACKNODE *top = nullptr;
void push_stack(NODE *node)
{
    STACKNODE *st_node = new STACKNODE;
    st_node->node = node;

    if(top == nullptr)
    { 
        st_node->next = nullptr;
        top = st_node;
    }
    else
    {
        st_node->next = top;
        top = st_node;
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
        STACKNODE *temp = top->next;
        NODE *node_ptr = top->node;
        delete top;
        top = temp;
        return node_ptr;
    }
}

bool bst_iterativeSearch(NODE *node, int ele);
bool bst_recursiveSearch(NODE *node, int ele);
void bst_recursiveInsert(NODE *node, int ele);
void bst_iterativeInsert(NODE *node, int ele);
NODE* bst_delete(NODE *node, int ele);//return type is a pointer to NODE type. Return the root node because the root node may change during deletion
NODE* findMin(NODE *node);//finds minimum element in a tree/subtree
NODE* createBST_recursiveInsert(NODE *node, int ele);
void generateFromPreorder(int *preorder, int size);//O(n)
NODE* generateFromPreorder_recursive(vector<int> preorder);//O(n^2)

void inorder(NODE *node)
{
    if(node != nullptr)
    {
        inorder(node->Lchild);
        cout << node->data << " ";
        inorder(node->Rchild); 
    }
}

int main(void)
{
    root = createBST_recursiveInsert(root, 30);
    createBST_recursiveInsert(root, 15);
    createBST_recursiveInsert(root, 10);
    createBST_recursiveInsert(root, 20);
    createBST_recursiveInsert(root, 50);
    createBST_recursiveInsert(root, 40);
    createBST_recursiveInsert(root, 60);


    cout << bst_recursiveSearch(root, 40) << endl;
    cout << bst_recursiveSearch(root, 100) << endl;
    cout << bst_iterativeSearch(root, 40) << endl;
    cout << bst_iterativeSearch(root, 100) << endl;

    bst_iterativeInsert(root, 100);
    bst_recursiveInsert(root, 120);

    root = bst_delete(root, 120);
    inorder(root);

    cout << endl; 

    int preorder[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int size = sizeof(preorder)/sizeof(preorder[0]);
    generateFromPreorder(preorder, size);
    inorder(root);

    cout << endl;

    vector<int> preorder_vec {30, 20, 10, 15, 25, 40, 50, 45};
    root = generateFromPreorder_recursive(preorder_vec);
    inorder(root);

    return 0;
}

NODE* createBST_recursiveInsert(NODE *node, int ele)
{
    if(node == nullptr)
    {
        NODE *newNode = new NODE;
        newNode->Lchild = nullptr;
        newNode->Rchild = nullptr;
        newNode->data = ele;

        return newNode;
    }
    else
    {
        if(node->data > ele)
        {
            node->Lchild = createBST_recursiveInsert(node->Lchild, ele);
        }
        else if(node->data < ele)
        {
            node->Rchild = createBST_recursiveInsert(node->Rchild, ele);
        }
        else
        {
            cout << "Node is already present! Nothing inserted." << endl;
            return nullptr;
        }
        return node;//doesn't make adifference but since the function has a return type 
    }
}

bool bst_iterativeSearch(NODE *node, int ele)
{
    while(node != nullptr)
    {
        if(node->data > ele)
            node = node->Lchild;
        else if(node->data < ele)
            node = node->Rchild;
        else
            return true;
    }
    return false;
}

bool bst_recursiveSearch(NODE *node, int ele)
{
    if(node == nullptr)
        return false;
    else
    {
        if(node->data > ele)
            bst_recursiveSearch(node->Lchild, ele);
        else if(node->data < ele)
            bst_recursiveSearch(node->Rchild, ele);
        else
            return true;
    }
}

void bst_recursiveInsert(NODE *node, int ele)//to be applied on already existing tree
{
    static bool status = false;

    if(node == nullptr)
    {
        status = true;
        return;
    }
    else
    {
        if(node->data > ele)
        {
            bst_recursiveInsert(node->Lchild, ele);
            if(status == true)
            {
                NODE *newNode = new NODE;
                newNode->Lchild = nullptr;
                newNode->Rchild = nullptr;
                newNode->data = ele;

                node->Lchild = newNode;
                status = false;
            }
        }
        else if(node->data < ele)
        {
            bst_recursiveInsert(node->Rchild, ele);
            if(status == true)
            {
                NODE *newNode = new NODE;
                newNode->Lchild = nullptr;
                newNode->Rchild = nullptr;
                newNode->data = ele;
                
                node->Rchild = newNode;
                status = false;
            }
        }
        else
            cout << "Element is already present! Nothing inserted." << endl;
    }
}

void bst_iterativeInsert(NODE *node, int ele)
{
    trail = nullptr;
    if(node == nullptr)//if no node previously present
    {
        NODE *newNode = new Node;
        newNode->data = ele;
        newNode->Lchild = nullptr;
        newNode->Rchild = nullptr;
        node = newNode;
        return;
    }
    while(node != nullptr)
    {
        trail = node;
        if(node->data < ele)
        {
            node = node->Rchild;
        }
        else if(node->data > ele)
        {
            node = node->Lchild;
        }
        else
        {
            cout << "Element is already present!" << endl;
            return;
        }
    }
    NODE *newNode = new Node;
    newNode->data = ele;
    newNode->Lchild = nullptr;
    newNode->Rchild = nullptr;

    if(trail->data < ele)
        trail->Rchild = newNode;
    else if(trail->data > ele)
        trail->Lchild = newNode;
}

NODE* findMin(NODE *node)
{
    while(node->Lchild != nullptr)
        node = node->Lchild;
    return node;
}

NODE* bst_delete(NODE *node, int ele)
{
    if(node == nullptr)
        return node;
    else
    {
        if(ele < node->data)
            node->Lchild = bst_delete(node->Lchild, ele);
        else if(ele > node->data)
            node->Rchild = bst_delete(node->Rchild, ele);
        else//node found
        {
            //case1: no child
            if((node->Lchild == nullptr) && (node->Rchild == nullptr))
            {
                delete node;
                node = nullptr;
            }    
            //case2: 1 child
            else if(node->Lchild == nullptr)
            {
                NODE* temp = node;
                node = node->Rchild;
                delete temp;
            }
            else if(node->Rchild == nullptr)
            {
                NODE* temp = node;
                node = node->Lchild;
                delete temp;
            }
            //case3: 2 children - searching for minimum node in right subtree of current node = inorder successor
            else if(node->Lchild && node->Rchild)
            {
                NODE *temp = findMin(root->Rchild);
                node->data = temp->data;
                node->Rchild = bst_delete(node->Rchild, temp->data);//delete the duplicate
            }
        }
        return node;
    }
    
}

void generateFromPreorder(int *preorder, int size)
{
    int index = 0;
    root = new NODE;
    root->data = preorder[index++];
    root->Lchild = nullptr;
    root->Rchild = nullptr;
    NODE *ptr = root;

    while(index < size)
    {
        if(preorder[index] < ptr->data)
        {
            NODE *newNode = new NODE;
            newNode->data = preorder[index++];
            newNode->Lchild = nullptr;
            newNode->Rchild = nullptr;

            ptr->Lchild = newNode;
            push_stack(ptr);
            ptr = newNode;
        }
        else if((preorder[index] > ptr->data) && ((top == nullptr) || (preorder[index] < (top->node)->data)))
        {
            NODE *newNode = new NODE;
            newNode->data = preorder[index++];
            newNode->Lchild = nullptr;
            newNode->Rchild = nullptr;

            ptr->Rchild = newNode;
            ptr = newNode;
        }
        else if((preorder[index] > ptr->data) && (preorder[index] > (top->node)->data))
        {
            ptr = pop_stack();
        }
    }
}

NODE* generateFromPreorder_recursive(vector<int> preorder)
{
    if(preorder.empty())
    {
        return nullptr;
    }
    else
    {
        NODE* node = new NODE;
        node->Lchild = nullptr;
        node->Rchild = nullptr;
        node->data = preorder.at(0);

        vector<int> lesser;
        vector<int> greater;
        for(int index = 1; index < preorder.size(); index++)
        {
            if(node->data > preorder.at(index))
                lesser.push_back(preorder.at(index));
            else if(node->data < preorder.at(index))
                greater.push_back(preorder.at(index));
        }

        node->Lchild = generateFromPreorder_recursive(lesser);
        node->Rchild = generateFromPreorder_recursive(greater);

        return node;
    }
}