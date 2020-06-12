#include<iostream>
#include<cstdbool>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node NODE;
NODE *front = NULL;
NODE *rear = NULL;

void enqueue(int ele);
int dequeue(void);
bool isEmpty(void);
void BFS(int (*arr)[7], int num, int n);//int arr[][7]
void DFS(int (*arr)[7], int num, int n);

int main(void)
{
    int G[7][7]={{0,0,0,0,0,0,0},
                {0,0,1,1,0,0,0},
                {0,1,0,0,1,0,0},
                {0,1,0,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}};

    BFS(G, 1, 7);
    cout << endl;
    DFS(G, 1, 7);
    cout << endl;
}

void enqueue(int ele)
{
    NODE *newNode = new NODE;
    newNode->data = ele;
    newNode->next = NULL;

    if(front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue(void)
{
    if(front != NULL)
    {
        NODE *temp = front->next;
        int data = front->data;
        delete front;
        front = temp;
        return data;
    }
}

bool isEmpty(void)
{
    if(front == NULL)
        return true;
    else
        return false;
}

void BFS(int arr[][7], int num, int n)
{
    int visited[7]={0};

    cout << num << " ";
    visited[num] = 1;
    enqueue(num);

    while(!isEmpty())
    {
        int vertex = dequeue();
        for(int adj = 1; adj <= n; adj++)
        {
            if((arr[vertex][adj] == 1) && (visited[adj] != 1))
            {
                cout << adj << " ";
                visited[adj] = 1;
                enqueue(adj);
            }
        }
    }
}

void DFS(int arr[][7], int num, int n)
{
    static int visited[7]={0};
    if(visited[num] == 0)
    {
        cout << num << " ";
        visited[num] = 1;
        for(int vertex = 1; vertex <= n; vertex++)
        {
            if(arr[num][vertex] == 1)
                DFS(arr, vertex, n);
        }
    }
}