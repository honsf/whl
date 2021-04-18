#include <stdio.h>
#include <stdlib.h>

typedef struct _binarytree
{
    char data;
    struct _binarytree * plchild;
    struct _binarytree * prchild;
}btnode;

btnode * createbtree();
void pretraversebtree(btnode * pt);
void intraversebtree(btnode * pt);
void posttraversebtree(btnode * pt);

int main()
{
    btnode * pt = createbtree();
    pretraversebtree(pt);
    printf("\n");
    intraversebtree(pt);
    printf("\n");
    posttraversebtree(pt);
    printf("\n");
    return 0;
}

btnode * createbtree()
{
    btnode * pa = (btnode*)malloc(sizeof(btnode));
    btnode * pb = (btnode*)malloc(sizeof(btnode));
    btnode * pc = (btnode*)malloc(sizeof(btnode));
    btnode * pd = (btnode*)malloc(sizeof(btnode));
    btnode * pe = (btnode*)malloc(sizeof(btnode));
    pa->data = 'A';
    pb->data = 'B';
    pc->data = 'C';
    pd->data = 'D';
    pe->data = 'E';
    pa->plchild = pb;
    pa->prchild = pc;
    pb->plchild = pb->prchild = NULL;
    pc->plchild = pd;
    pc->prchild = NULL;
    pd->plchild = NULL;
    pd->prchild = pe;
    pe->plchild = pe->prchild = NULL;
    return pa;

}

void pretraversebtree(btnode * pt)
{
    if(pt != NULL)
    {
        printf("%c",pt->data);
        if(pt->plchild != NULL)
        pretraversebtree(pt->plchild);
        if(pt->prchild != NULL)
        pretraversebtree(pt->prchild);
    }
}

/*鲍松山/数据结构/二叉树
void pretraversebtree(BinTreeNode * pt)
{
    if(pt != NULL)
    {
        printf("%c",pt->data);
        if(pt->leftChild != NULL)
        pretraversebtree(pt->leftChild);
        if(pt->rightChild != NULL)
        pretraversebtree(pt->rightChild);
    }
}
*/

void intraversebtree(btnode * pt)
{
    if(pt != NULL)
    {
        if(pt->plchild != NULL)
        intraversebtree(pt->plchild);
        printf("%c",pt->data);
        if(pt->prchild != NULL)
        intraversebtree(pt->prchild);
    }
}
void posttraversebtree(btnode * pt)
{
    if(pt != NULL)
    {
        if(pt->plchild != NULL)
        posttraversebtree(pt->plchild);
        if(pt->prchild != NULL)
        posttraversebtree(pt->prchild);
        printf("%c",pt->data);
    }
}
