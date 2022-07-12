// 线性表
#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int length;
}SeqList;


void Init_SeqList(SeqList& L) {
    L.length = 0;
    // L->length=10;
}


void Create_SeqList(SeqList& L, int a[], int n) {
    if (n > MAXSIZE) {
        cout << endl << "参数超出顺序表容量" << endl;
        exit(1);
    }

    // L.lenght=0;

    for (int i = 0; i < n; i++) {
        L.data[i] = a[i];
        L.length++;
    }
}

void Show_SeqList(SeqList& L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << "\n\n";
}

void Insert_SeqList(SeqList& L, int i, int t) {
    // 1. 线性表是否已经满了
    if (L.length == MAXSIZE) {
        cout << endl << "顺序表已经满了" << endl;
        exit(1);
    }

    // 2. 插入位置是否合法,合法位置是【1，length+1】
    if (i<1 || i>L.length + 1) {
        cout << endl << "插入位置不合法" << endl;
        exit(1);
    }
    // 3. 把数值后移
    for (int j = L.length - 1; j >= i - 1; j--) {
        L.data[j + 1] = L.data[j];
    }
    // 4. 插入数值
    L.data[i - 1] = t;
    L.length += 1;
}


void Del_SeqList(SeqList& L, int i) {
    // 1. i的合法删除范围是【1，length】
    if (i<1 | i>L.length) {
        cout << endl << "删除位置不合法" << endl;
        getchar();
        exit(1);
    }
    // 2. 删除
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j]; //直接覆盖
    }
    L.length -= 1;
}

void Clear_SeqList(SeqList& L)
{
    if (L.length == 0)
    {
        exit(1);
    }

    else
    {
        for (int i = 0; i < L.length; i++)
        {
            L.data[i] = NULL;

        }
        L.length = 0;
    }
}


void Destroy_SeqList(SeqList& L)
{
    if (L.length == 0)
    {
        exit(1);
    }

    else
    {
        free(L.data);
        L.length = 0;
        L.data = NULL;
    }

    cout << "线性表已销毁";
}

int main() {
    // 1. 初始化线性表
    SeqList test_seq;
    Init_SeqList(test_seq);

    // 2. 向线性表添加一列数值
    int a[] = { 2,4,6 };
    int n = 3;
    Create_SeqList(test_seq, a, n);

    cout << "初始化后的顺序表：\n";
    Show_SeqList(test_seq);

    // 3. 向线性表添加一个数值
    int i = 4, t = 100;  // 向表的第i个位置插入值t
    Insert_SeqList(test_seq, i, t);
    cout << "\n向表的第四个位置插入数值100后的顺序表：\n";
    Show_SeqList(test_seq);

    // 4. 从线性表删除一个数值
    int del = 3;  // 删除第个位置的数据
    Del_SeqList(test_seq, del);
    cout << "\n删除表位置为3的元素后的顺序表：\n";
    Show_SeqList(test_seq);

    // 5. 清空线性表
    Clear_SeqList(test_seq);
    cout << "\n清空后的线性表：\n";
    Show_SeqList(test_seq);


    // 6. 销毁线性表
    cout << "\n重置线性表:\n";
    Create_SeqList(test_seq, a, n);
    Show_SeqList(test_seq);

    Destroy_SeqList(test_seq);

}