#include <iostream>
using namespace std;
// 链栈

// 1. 定义类型
typedef struct LNode
{
    int data;
    struct LNode* next;
} *LinkStack;

// 2. 初始化
void InitLinkStack(LinkStack& S)
{
    S = NULL;
}

// 3. 判断栈空
bool LinkStackEmpty(LinkStack& S)
{
    return S == NULL; // S->next == NULL 会报错，因为不一定有next
}


// 5. 入栈
void Push(LinkStack& S, int value)
{
    LinkStack p;
    p = new LNode;
    p->data = value;
    p->next = S;
    S = p;
}

// 6. 出栈
int Pop(LinkStack& S)
{
    // 判断栈空
    if (LinkStackEmpty(S))
    {
        cout << "栈空" << endl;
        exit(1);
    }

    LinkStack p = new LNode;
    p->next = S;
    int value = S->data;
    S = S->next;
    delete p;
    return value;
}

// 7. 取栈顶元素
int GetTop(LinkStack& S)
{
    // 判断栈空
    if (LinkStackEmpty(S))
    {
        cout << "栈空" << endl;
        exit(1);
    }

    return S->data;
}

// 8. 遍历链栈
void ShowLinkStack(LinkStack& S)
{
    // 判断栈空
    if (LinkStackEmpty(S))
    {
        cout << "栈空" << endl;
        exit(1);
    }
    LinkStack p = S;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

// 9. 清空链栈
void ClearLinkStack(LinkStack& S)
{
    // 判断栈空
    if (LinkStackEmpty(S))
    {
        cout << "栈空" << endl;
        exit(1);
    }

    LinkStack p = new LNode;
    while (S)
    {
        p = S;
        S = S->next;
        delete p;
    }


}

// 10. 销毁链栈
void DestroyLinkStack(LinkStack& S)
{
    // 判断栈空
    if (LinkStackEmpty(S))
    {
        cout << "栈空" << endl;
        exit(1);
    }

    LinkStack p;
    while (S)
    {
        p = S;
        S = S->next;
        delete p;
    }
}

// 11. 链表长度
int LinkStackLength(LinkStack& S)
{
    LinkStack p = S;
    int length = 0;
    while (p)
    {
        p = p->next;
        length++;
    }
    return length;
}

int main()
{
    LinkStack S;

    // 1. 初始化
    InitLinkStack(S);


    // 2. 入栈
    int a = 5, b = 2, c = 10;
    Push(S, a);
    Push(S, b);
    Push(S, c);
    cout << "分别入栈元素值为5，2，10 后的链栈S:" << endl;
    ShowLinkStack(S);

    LinkStack S2 = S;

    // 链表长度
    int length = LinkStackLength(S);
    cout << "\n\n链栈S的长度：" << length << endl;

    // 4. 出栈
    Pop(S);
    cout << "\n\n出栈操作后的链栈S：" << endl;
    ShowLinkStack(S);


    // 5. 取栈顶元素
    int value = GetTop(S);
    cout << "\n\n链栈S的栈顶元素值：" << value << endl;

    // 6. 清空
    ClearLinkStack(S);
    cout << "\n\n清空操作后的链栈S:" << endl;
    ShowLinkStack(S);

    // 7. 销毁
    DestroyLinkStack(S2);
    cout << "\n\n销毁操作后的链栈S2：" << endl;
    ShowLinkStack(S2);
}