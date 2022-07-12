#include <iostream>
#include <math.h>
using namespace std;

typedef struct BiTNode
{
    char data; // 结点数据域
    struct BiTNode* lchild, * rchild; // 左孩子和右孩子指针
}BiTNode, * BiTree;


// 1. 构造二叉树

// 1.1 先序遍历建立二叉树

void CreateTreePre(BiTree& T)
{
    char c;
    cin >> c;
    if (c == '#')
    {
        T = NULL;
    }
    else
    {
        T = new BiTNode;
        T->data = c;
        CreatTreePre(T->lchild);
        CreatTreePre(T->rchild);
    }
}


// 1.2 中序遍历创建二叉树
void CreateTreeIn(BiTree T)
{
    char c;
    cin >> c;
    if (c == '#')
    {
        T = NULL;
    }
    else
    {
        T = new BiTNode;
        CreatTreeIn(T->lchild);
        T->data = c;
        CreatTreeIn(T->rchild);
    }
}


// 1.3 后序遍历创建二叉树
void CreateTreePost(BiTree& T)
{
    char c;
    cin >> c;
    if (c == '#')
    {
        T = NULL;
    }
    else
    {
        T = new BiTNode;
        CreateTreePost(T->lchild);
        CreateTreePost(T->rchild);
        T->data = c;
    }
}




// 2. 遍历二叉树
// 2.1 先序遍历二叉树
void PreOrder(BiTree& T)
{
    if (T)
    {
        cout << T->data << " ";
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 2.2 中序遍历二叉树
void Inorder(BiTree& T)
{
    if (T)
    {
        Inorder(T->lchild);
        cout << T->data << " ";
        Inorder(T->rchild);
    }

}

// 2.3 后序遍历二叉树
void PostOrder(BiTree& T)
{
    if (T)
    {
        PostOrder(T->lchild);
        cout << T->data << " ";
        PostOrder(T->rchild);
    }
}

// 3.递归统计二叉树中结点的个数
int NodeCount(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

// 4. 递归统计树的深度
int TreeDepth(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    int i = TreeDepth(T->lchild);
    int j = TreeDepth(T->rchild);
    return i > j ? i + 1 : j + 1;
}

// 5. 叶子节点的个数
int LeafCount(BiTree T)
{
    if (!T)
    {
        return 0;
    }
    if (T->lchild == NULL && T->rchild == NULL)
    {
        return 1;
    }

    return LeafCount(T->lchild) + LeafCount(T->rchild);
}
// 6. 复制二叉树
void CopyTree(BiTree T, BiTree& TCopy)
{
    if (T == NULL)
    {
        TCopy = NULL;
    }
    else
    {
        TCopy = new BiTNode;
        TCopy->data = T->data;
        CopyTree(T->lchild, TCopy->lchild);
        CopyTree(T->rchild, TCopy->rchild);
    }
}

// 7. 二叉树是否为空
bool TreeEmpty(BiTree& T)
{
    return T == NULL;
}

int main()
{
    BiTree T = NULL;
    cout << "先序遍历创建二叉树：" << endl;
    CreatTreePre(T);
    cout << "\n先序遍历：" << endl;
    PreOrder(T);
    cout << "\n中序遍历:" << endl;
    Inorder(T);
    cout << "\n后序遍历：" << endl;
    PostOrder(T);

    cout << "\n二叉树中结点的个数:" << NodeCount(T) << endl;
    cout << "\n二叉树深度：" << TreeDepth(T) << endl;
    cout << "\n叶子节点个数" << LeafCount(T) << endl;

    BiTree TCopy = NULL;
    CopyTree(T, TCopy);
    cout << "\n复制二叉树后的先序遍历：" << endl;
    PreOrder(TCopy);
}