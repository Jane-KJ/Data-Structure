#include <iostream>
#include <math.h>
using namespace std;
typedef struct HTNode
{
    int data, weight;
    struct HTNode* lchild, * rchild, * parent;
}HTNode, * HuffmanTree;
// HuffmanTree

typedef struct HTNode
{
    int data, weight;
    struct HTNode* lchild, * rchild, * parent;
}HTNode, * HuffmanTree;

void Select(HuffmanTree HT, int i, int s1, int s2)
{
    int j;
    for (j = 0; j < i; j++)
    {
        if (HT[j].parent == -1) break;  // j定位到没有parent的结点
    }

    for (s1 = j, j++; j < i; j++)
    {
        if (HT[j].parent == -1 && HT[j].weight < HT[s1].weight)
            s1 = j;
    }

    for (j = 0; j < i; j++)
    {
        if (HT[j].parent != -1 && s1 != j) break;
    }

    for (s2 = j, j++; j < i; j++)
    {
        if (HT[j].parent == -1 && HT[j].weight < HT[s2].weight && s1 != j)
            s2 = j;
    }
}

void CreateHuffmanTree(HuffmanTree& HT, int n)  // n是叶子结点个数
{        // 1. 数值收集
    char* input_char = new char[n];
    int* input_weight = new int[n];
    cout << "Please input char:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin << input_char[i];
    }

    cout << "Please input weight:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin << input_weight[i];
    }


    // 2. 创建Huffman数组
    int m = 2 * n - 1; // 申请m个单位的数组
    HT = new HTNode[m];


    // 3. 初始化
    for (i = 0; i < n; i++)
    {
        HT[i].data = input_char[i];
        HT[i].weight = input_weight[i];
        HT[i].parent = -1;
        HT[i].lchild = -1;
        HT[i].rchild = -1;
    }
    for (i = n; i < m; i++)
    {
        HT[i].parent = -1;
    }

    // 4. 创建HuffmanTree
    for (i = n; i < m; i++)
    {
        int s1, s2;
        Select(HT, i, s1, s2); // Select函数选择出具有最小weight的序列号s1，s2
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = H[s1].weight + H[s2].weight;
    }

    // 5. 清理内存
    delete input_weight;
    delete input_char;
}

// 对字符编码
void HuffmanCode(HuffmanTree T, int n, int i, char* code)
{
    char* temp = new char[n];
    temp[n - 1] = '\0';
    int start = n - 1;
    int parent = HT[i].parent;
    int p = i;  // parent为父，p为子，同时不断向上，组成新的父子
    while (parent != -1)
    {
        if (HT[parent].lchild == p) temp[--start] = '0';
        else temp[--start] = '1';
        p = parent;
        parent = HT[parent].parent;
    }
    strcpy(code, &temp[start]);
    delete temp;
}

int main()
{
    int n;
    cout << "Please input the number of char:"；
        cin >> n;

    HuffmanTree HT;
    CreateHuffmanTree(HT, n);

    char* code = new char[n];
    for (int i = 0; i < n; i++)
    {
        HuffmanCode(HT, n, i, code);
    }

    delete code;
    delete HT;
}