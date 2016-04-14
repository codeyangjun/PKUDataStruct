#ifndef MAIN_CPP_INCLUDED
#define MAIN_CPP_INCLUDED

#include <iostream>
#include <cstdlib>
#include <cstdio>

#define MAX 65535
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
};

void preorderTree(Node *pRoot)
{
    if (!pRoot)
    {
        return;
    }
    else
    {
        printf("%d ", pRoot->data);
        preorderTree(pRoot->left);
        preorderTree(pRoot->right);
    }
}

void rebuildTree(int *inorder, int *post, int len, Node **proot)
{
    //边界条件处理
    if (inorder == NULL || post == NULL)
    {
        return;
    }

//处理后序遍历的第1个节点,他是根节点
    Node *temp = new Node;
    temp->data = *(post + len - 1);
    temp->left = NULL;
    temp->right = NULL;

    if (*proot == NULL)
    {
        *proot = temp;
    }

    if (len == 1) //递归基，len==1，只有1个节点了，直接返回
    {
        return;
    }

//接下来该切分左右子树了，分治法
//在中序遍历队列中寻找左子树的切分点
    int leftTreeLen = 0;
    int *p = inorder;	//左子树的起点
    int *postEnd = post + len - 1;

    if (postEnd == NULL || p == NULL)
    {
        return;
    }

    if ((*postEnd) == (*p))
    {
        leftTreeLen = 1;
    }
    else
    {
        while (p && ((*p) != (*postEnd)))
        {
            ++leftTreeLen;
            p++;
        }
    }

    int rightTreeLen = len - leftTreeLen - 1;
//中序遍历的左子树应为起点inorder,长度leftTreeLen,右子树起点应为inorder+leftTreeLen+1,长度len-leftTreeLen-1
//后序遍历的左子树应为起点post,长度leftTreeLen,右子树起点应为post + len - 1  - rightTreeLen ,长度len-leftTreeLen-1

    if (leftTreeLen > 0)	//重建左子树
    {
        rebuildTree(inorder, post, leftTreeLen, &((*proot)->left));
    }

    if (rightTreeLen > 0)	//重建右子树
    {
        rebuildTree(inorder+leftTreeLen+1,
                    post + len - 1 - rightTreeLen, rightTreeLen,
                    &((*proot)->right));
    }

}

int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    std::ios::sync_with_stdio(false);

    int len = 0;

    int *inorder = new int[MAX];
    int *post = new int[MAX];
    while(cin>>inorder[len++])
        if(cin.get()!=' ')
            break;

    len=0;
    while(cin>>post[len++])
        if(cin.get()!=' ')
            break;

    Node *pRoot = NULL;
    rebuildTree(inorder, post, len, &pRoot);
    preorderTree(pRoot);

    return 0;
}


#endif // MAIN_CPP_INCLUDED
