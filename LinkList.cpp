// 单链表
#include <iostream>
using namespace std;
// 单链表

typedef struct LNode
{
    int data;  // 数据域
    struct LNode* next;  // 指针域
}LNode, * LinkList;

// 头指针 - 头结点 - 首元节点


// 1. 初始化
void InitList(LinkList& L)
{
    L = new LNode;  // 生成新节点作为头结点，用头指针L指向头结点
    L->next = NULL;  // 头结点的指针域置空

}


// 2. 创建单链表
// 2.1 头部插入法
void CreateList_head(LinkList& L, int a[], int n)
{
    LinkList p;
    for (int i = 0; i < n; i++)
    {
        p = new LNode;
        p->next = L->next;
        p->data = a[i];
        L->next = p;

    }
}



// 2.2 尾部插入法
void CreateList_tail(LinkList& L, int a[], int n)
{
    LinkList p;
    LinkList temp;

    // p 指向L最后一个元素
    p = L;
    while (p->next)
    {
        p = p->next;
    }

    for (int i = 0; i < n; i++)
    {
        temp = new LNode;
        temp->data = a[i];
        temp->next = NULL;
        p->next = temp;
        p = temp;
    }
}



// 3. 遍历
void ShowList(LinkList& L)
{
    LinkList p;
    p = L->next;

    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

// 4. 求长度
int ListLength(LinkList& L)
{
    LinkList p = L->next;
    int length = 0;

    while (p)
    {
        length += 1;
        p = p->next;
    }
    return length;
}

// 5. 销毁

void DestroyList(LinkList& L)
{
    LinkList p = L;

    while (p)
    {
        L = L->next;
        free(p);
        p = L;
    }
}
// 6. 按值查找
int LocateElement(LinkList& L, int value)
{
    LinkList p = L->next;
    int location = 0;

    while (p->data != value && p)
    {
        p = p->next;
        location += 1;
    }

    if (p)
        return location;
    else
        return 0;
}

// 7. 插入节点
void InsertList(LinkList& L, int i, int value)
{
    // 定义p指向L第i个位置的元素
    LinkList p = L;
    while (i - 1)
    {
        p = p->next;
        i--;
    }

    LinkList n;
    n = new LNode;
    n->next = p->next; // p->next 为NULL也没关系
    n->data = value;
    p->next = n;
}

// 8. 删除节点
void DeleteList(LinkList& L, int i)
{
    if (i > ListLength(L) || i < 1)
    {
        cout << "删除位置不合法" << endl;
        exit(1);
    }

    LinkList p = L;
    int j = 0;
    while ((j < i - 1) && p->next) // p指向i-1
    {
        p = p->next;
        j++;
    }
    LinkList q = p->next;
    p->next = q->next;
    free(q);
}

// 9. 置逆
void ReverseList(LinkList& L)
{
    // 将链表断开
    LinkList p;
    p = L->next;
    L->next = NULL;

    // 将等待插入剩下的链表断开成一个节点和剩下的一个链表，并将节点插入逆置链表
    LinkList s;
    while (p)
    {
        s = p;
        p = p->next;
        s->next = L->next;
        L->next = s;
    }

}

// 10. 清空
void ClearList(LinkList& L)
{
    LinkList p;
    while (L->next)
    {
        p = L->next;
        L->next = p->next;
        delete(p);
    }
    cout << "已清空！" << endl;
}

// 主程序

int main()
{
    // 1. 初始化
    LinkList L1;
    InitList(L1);

    // 2. 插入值
    // 2.1 头部插入法
    int a[] = { 1,2,3,4,5,6,7,8,9,77,33,55,11,3,33,6,8,87,99 };
    int n = 19; // 列表a 长度
    CreateList_head(L1, a, n);
    cout << "头部插入法结果L1：" << endl;
    ShowList(L1);


    // 2.2 尾部插入法
    LinkList L2;
    InitList(L2);
    CreateList_tail(L2, a, n);
    cout << "\n\n尾部插入法结果L2:" << endl;
    ShowList(L2);

    // 3. 单链表长度
    cout << "\n\n单链表L2 长度为：" << ListLength(L2) << endl;

    // 4. 值查询
    cout << "\n\n单链表L2 值为33的元素位置是：" << LocateElement(L2, 33) << endl;

    // 5. 插入
    cout << "\n\n向单链表L2第17个位置插入元素值8888：" << endl;
    InsertList(L2, 17, 8888);
    ShowList(L2);

    // 6. 销毁单链表
    // DestroyList(L2);


    // 7. 删除节点
    cout << "\n\n删除单链表L2第3个元素后：" << endl;
    DeleteList(L2, 3);
    ShowList(L2);

    // 8. 逆置单链表
    cout << "\n\n单链表L2 逆置：" << endl;
    ReverseList(L2);
    ShowList(L2);

    // 9. 清空单链表
    cout << "\n\n清空单链表：" << endl;
    ClearList(L2);
    cout << "\n清空后单链表展示：" << endl;
    ShowList(L2);
    return 0;

}
