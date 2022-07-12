#include <iostream>
#include <math.h>
using namespace std;
enum flag { Child, Thread };
typedef struct BiThrNode
{
    ElemType  data;
    struct  BiThrNode* lchild, * rchild;
    flag  ltype, rtype;
} *BiThrTree;

// 中序线索化
void InThreaded(BiTree& T)
{
    static BiTree prenode = NULL;
    // prenode必须是静态或全局，保证每次递归能正常返回当前值

    if (T)
    {
        InTreaded(T->lchild)  // 1. 处理左子树

            if (!T->lchild)        // 2. 处理根节点
            {
                T->ltype = Thread;
                T->lchild = prenode;
            }
        if (prenode && !prenode->rchild)
        {
            prenode->rtype = Thread;
            prenode->rchild = T;
        }
        prenode = T;

        InThreaded(T->rchild)// 3. 处理右子树
    }
}
BiTNode* InOrder_Post(BiTNode* p)
{
    BiNode* q;
    if (p->rtype == Thread)
        return p->rchild;
    else {
        q = p->rchild;
        while (q->ltype == Child)
            q = q->lchild;
        return q;
    }
}

BiTNode* InOrder_Pre(BiTNode* p)
{
    BiNode* q;
    if (p->ltype == Thread)
        return p->lchild;
    else {
        q = p->lchild;
        while (q->rtype == Child)
            q = q->rchild;
        return q;
    }
}

void DestroyTree(Bitree T)
{
    if (T)
    {
        if (T->ltype == Child)
            DestroyTree(T->lchild);
        if (T->rtype == Child)
            DestroyTree(T->rchild);
        delete T;
        T = NULL;
    }
}