#include<iostream>
using namespace std;

struct Node{
    struct Node* Lchild;
    int data;
    int height;// to calculate balance factor
    struct Node* Rchild;
};
typedef struct Node NODE;
NODE *root = nullptr;

int calc_nodeHeight(NODE *node);
int calc_balanceFactor(NODE *node);
NODE* LL_Rotation(NODE *node);
NODE* LR_Rotation(NODE *node);
NODE* RR_Rotation(NODE *node);
NODE* RL_Rotation(NODE *node);
NODE* createBST_recursiveInsert(NODE *node, int ele);
void printInorder(NODE *node);

int main(void)
{
    root = createBST_recursiveInsert(root, 10);
    createBST_recursiveInsert(root, 20);
    createBST_recursiveInsert(root, 30);
    createBST_recursiveInsert(root, 25);
    createBST_recursiveInsert(root, 28);
    createBST_recursiveInsert(root, 27);
    createBST_recursiveInsert(root, 5);

    printInorder(root);
    cout << endl;

    return 0;
}

int calc_nodeHeight(NODE *node)
{
    int right_height, left_height;
    left_height = ((node != nullptr) && (node->Lchild != nullptr)) ? node->Lchild->height : 0;
    right_height = ((node != nullptr) && (node->Rchild != nullptr)) ? node->Rchild->height : 0;

    if(left_height > right_height)
        return left_height + 1;//height of current node is equal to height of subtree + 1
    else
        return right_height + 1;
}

int calc_balanceFactor(NODE *node)
{
    int right_height, left_height;
    left_height = ((node != nullptr) && (node->Lchild != nullptr)) ? node->Lchild->height : 0;
    right_height = ((node != nullptr) && (node->Rchild != nullptr)) ? node->Rchild->height : 0;

    return left_height - right_height;
}

NODE* LL_Rotation(NODE *node)
{
    cout << "Performing LL Rotation" << endl;

    NODE *node_Lchild = node->Lchild;
    NODE *node_Lchild_Rchild = node->Lchild->Rchild;

    //making necessary rotations
    node->Lchild = node_Lchild_Rchild;
    node_Lchild->Rchild = node;

    /*
    The height of a node effectively is equal to max{distance from "bottom" of left subtree, distance 
    from "bottom" of right subtree}. Hence, even if a node is moving "up" or "down", the "bottom" of its
    subtrees (left and right) will also move along with it. We only update the height of the nodes 
    after rotation whose left or right children have been modified because their heights may have 
    changed.
    */
    node->height = calc_nodeHeight(node);
    node_Lchild->height = calc_nodeHeight(node_Lchild);

    if(root == node)
        root = node_Lchild;

    return node_Lchild;
}

NODE* LR_Rotation(NODE *node)
{
    cout << "Performing LR Rotation" << endl;

    NODE *node_Lchild_Rchild = node->Lchild->Rchild;
    NODE *node_Lchild_Rchild_Lchild = node_Lchild_Rchild->Lchild;
    NODE *node_Lchild_Rchild_Rchild = node_Lchild_Rchild->Rchild;

    //performing rotation
    node_Lchild_Rchild->Lchild = node->Lchild;
    node_Lchild_Rchild->Rchild = node;
    node->Lchild->Rchild = node_Lchild_Rchild_Lchild;
    node->Lchild = node_Lchild_Rchild_Rchild;

    //modifying the heights
    node->height = calc_nodeHeight(node);
    node_Lchild_Rchild->height = calc_nodeHeight(node_Lchild_Rchild);
    node_Lchild_Rchild->Lchild->height = calc_nodeHeight(node_Lchild_Rchild->Lchild);

    if(root == node)
        root = node_Lchild_Rchild;
    
    return node_Lchild_Rchild;
}

NODE* RR_Rotation(NODE *node)
{
    cout << "Performing RR Rotation" << endl;

    NODE *nodeB = node->Rchild;
    NODE *nodeB_Lchild = nodeB->Lchild;

    //performing rotation
    nodeB->Lchild = node;
    node->Rchild = nodeB_Lchild;

    //modifying the heights
    nodeB->height = calc_nodeHeight(nodeB);
    node->height = calc_nodeHeight(node);

    if(root == node)
        root = nodeB;
    
    return nodeB;
}

NODE* RL_Rotation(NODE *node)
{
    cout << "Performing RL Rotation" << endl;
    
    NODE *nodeC = node->Rchild->Lchild;
    NODE *nodeC_Rchild = nodeC->Rchild;
    NODE *nodeC_Lchild = nodeC->Lchild;

    //performing rotation
    nodeC->Lchild = node;
    nodeC->Rchild = node->Rchild;
    node->Rchild->Lchild = nodeC_Rchild;
    node->Rchild = nodeC_Lchild;

    if(root == node)
        root = nodeC;

    return nodeC;
}

//this function is interresting because it takes a partcular path doen the BST to insert the required node 
//in the correct position. Once done with insertion, it traces back the path it took
NODE* createBST_recursiveInsert(NODE *node, int ele)
{
    if(node == nullptr)
    {
        NODE *newNode = new NODE;
        newNode->Lchild = nullptr;
        newNode->Rchild = nullptr;
        newNode->data = ele;
        newNode->height = 1;
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

        node->height = calc_nodeHeight(node);//to update height of a node

        if((calc_balanceFactor(node) == 2) && (calc_balanceFactor(node->Lchild) == 1))//node is unbalanced
            return LL_Rotation(node);
        else if((calc_balanceFactor(node) == 2) && (calc_balanceFactor(node->Lchild) == -1))
            return LR_Rotation(node);
        else if((calc_balanceFactor(node) == -2) && (calc_balanceFactor(node->Rchild) == -1))
            return RR_Rotation(node);
        else if((calc_balanceFactor(node) == -2) && (calc_balanceFactor(node->Rchild) == 1))
            return RL_Rotation(node);

        return node;//doesn't make a difference but since the function has a return type. 
        //The node always returned to main() is 'root'. 
        //But node returned to adjacent recusrsive calls are just re-assigning the left/right child back to the parent node 
    }
}

void printInorder(NODE *node)
{
    if(node != nullptr)
    {
        printInorder(node->Lchild);
        cout << node->data << " ";
        printInorder(node->Rchild);
    }
}