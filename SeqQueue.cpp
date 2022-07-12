#include <iostream>
using namespace std;
// 顺序队列（循环队列）

# define MAXSIZE 10

typedef struct SeqQueue
{
    int data[MAXSIZE];
    int front;
    int rear;
};

// 1. 初始化
void InitSeqQueue(SeqQueue& Q)
{
    Q.front = 0;
    Q.rear = 0;
}

// 判断队空
bool SeqQueueEmpty(SeqQueue& Q)
{
    return Q.front == Q.rear;
}

// 判断队满
bool SeqQueueFull(SeqQueue& Q)
{
    return (Q.rear + 1) % MAXSIZE == Q.front;
}

// 2. 入队
void Push(SeqQueue& Q, int value)
{
    // 判断队满
    if ((Q.rear + 1) % MAXSIZE == Q.front)
    {
        cout << "队满" << endl;
        exit(1);
    }

    Q.rear = (Q.rear + 1) % MAXSIZE;
    Q.data[Q.rear] = value;
}

// 3. 出队
int Pop(SeqQueue& Q)
{
    // 判断队空
    if (Q.rear == Q.front)
    {
        cout << "队空" << endl;
    }

    Q.front = (Q.front + 1) % MAXSIZE;
    return Q.data[Q.front];

}

// 4. 遍历
void ShowSeqQueue(SeqQueue Q)
{
    while (Q.rear != Q.front)
    {
        cout << Pop(Q) << " ";
    }
}

int Length(SeqQueue Q)
{
    return abs(Q.front - Q.rear);
}

void DestroySeqQueue(SeqQueue& Q)
{
    if (SeqQueueEmpty(Q))
    {
        exit(1);
    }
    Q.rear = NULL;
    Q.front = Q.rear = 0;
}
int main()
{
    SeqQueue Q;
    InitSeqQueue(Q);

    int a = 9, b = 4, c = 8;
    Push(Q, a);
    Push(Q, b);
    Push(Q, c);
    cout << "顺序队列Q入队元素值9,4,8后：" << endl;
    ShowSeqQueue(Q);

    Pop(Q);
    cout << "\n\n顺序队列Q出队后：" << endl;
    ShowSeqQueue(Q);


    cout << "\n\n顺序队列Q的长度：" << Length(Q) << endl;
}