#include <iostream>
using namespace std;
// 链队列

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

typedef struct
{
    Node* front;
    Node* rear;
}LinkQueue;

void InitLinkQueue(LinkQueue& Q)
{
    Q.front = Q.rear = new Node;
    Q.front->data = NULL;
}

void EnQueue(LinkQueue& Q, int value)
{
    Node* p = new Node;
    p->next = NULL;
    p->data = value;

    Q.rear->next = p;
    Q.rear = p;
}

int DeQueue(LinkQueue& Q)
{
    // 判断队空
    if (Q.front == Q.rear)
    {
        cout << "队空" << endl;
        exit(1);
    }

    Node* p = Q.front->next;
    int value = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
    {
        Q.rear = Q.front;
    }
    delete p;
    return value;
}

void ShowLinkQueue(LinkQueue& Q)
{
    // 判断队空
    if (Q.front == Q.rear)
    {
        cout << "队空" << endl;
        exit(1);
    }

    Node* p = Q.front->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void DestroyLinkQueue(LinkQueue& Q)
{
    while (Q.front)
    {
        Q.rear = Q.front->next; // rear是一个临时变量，不断指向front的next
        delete Q.front;
        Q.front = Q.rear;
    }
}

int main()
{
    LinkQueue Q;
    InitLinkQueue(Q);
    int a = 4, b = 3, c = 10;
    EnQueue(Q, a);
    EnQueue(Q, b);
    EnQueue(Q, c);

    cout << "入队操作后的链队列Q：" << endl;
    ShowLinkQueue(Q);

    DeQueue(Q);
    cout << "\n\n出队操作后的链队列Q：" << endl;
    ShowLinkQueue(Q);

    DestroyLinkQueue(Q);
    cout << "\n\n销毁后的链队列Q：" << endl;
    ShowLinkQueue(Q);
}