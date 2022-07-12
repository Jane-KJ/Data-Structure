#include <iostream>
using namespace std;
//顺序栈
# define MAXSIZE 100
// 1. 定义类型

typedef struct
{
    int* base;
    int* top;
    int stacksize;
}SeqStack;

// 2. 初始化
void InitSeqStack(SeqStack& S)
{
    S.base = new int[MAXSIZE];
    S.top = S.base;
    S.stacksize = MAXSIZE;
}

// 6. 判断栈空
bool StackEmpty(SeqStack& S)
{
    return S.base == S.top;
}
// 7. 判断栈满
bool StackFull(SeqStack& S)
{
    return S.top - S.base == S.stacksize;
}
// 3. 入栈
void Push(SeqStack& S, int value)
{
    // 判断栈满
    if (StackFull(S))
    {
        cout << "栈满" << endl;
        exit(1);
    }
    else
    {
        *S.top = value;
        S.top++;
    }
}


// 4. 出栈
int Pop(SeqStack& S)
{
    // 判断栈空
    if (StackEmpty(S))
    {
        cout << "栈空" << endl;
        exit(1);
    }

    int value = *(--S.top);
    return value;
}

// 5. 取栈顶元素
int GetTop(SeqStack& S)
{
    // 判断栈空
    if (StackEmpty(S))
    {
        cout << "栈空" << endl;
        exit(1);
    }

    return *(S.top - 1);
}

// 6. 输出栈中元素
void ShowSeqStack(SeqStack& S)
{
    // 判断栈空
    if (StackEmpty(S))
    {
        cout << "栈空" << endl;
        exit(1);
    }

    for (int i = 0; i < S.top - S.base; i++)
    {
        cout << *(S.base + i) << " ";

    }
}

// 9. 清空顺序栈
void ClearSeqStack(SeqStack& S)
{
    if (StackEmpty(S))
    {
        cout << "栈已空" << endl;
        exit(1);
    }
    else
    {
        S.top = S.base;
        cout << "已清空" << endl;
    }
}
// 10. 销毁顺序栈
void DestroySeqStack(SeqStack& S)
{
    S.top = NULL;
    S.base = NULL;
    cout << "已销毁" << endl;
}


int main()
{
    // 1. 定义类型
    SeqStack S;

    // 2. 初始化
    InitSeqStack(S);

    // 3. 入栈
    int a = 5, b = 7, c = 1;
    Push(S, a);
    Push(S, b);
    Push(S, c);
    cout << "分别入栈三个数值后的顺序栈S：" << endl;
    ShowSeqStack(S);
    SeqStack S2 = S;


    // 4. 出栈（试一下出栈后元素还在不在！！！雀实还在）
    int value1 = Pop(S);
    cout << "\n\n出栈操作后的顺序栈S：" << endl;
    ShowSeqStack(S);


    // 5. 取栈顶元素
    int value2 = GetTop(S);
    cout << "\n\n取出栈顶元素值：\n" << value2 << endl;

    // 6. 清空顺序栈
    cout << "\n\n清空顺序栈S：" << endl;
    ClearSeqStack(S);
    //ShowSeqStack(S);

    // 7. 销毁顺序栈
    cout << "\n\n销毁顺序栈S2：" << endl;
    DestroySeqStack(S2);
    ShowSeqStack(S2);

    return 0;
}