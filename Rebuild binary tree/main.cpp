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
    //�߽���������
    if (inorder == NULL || post == NULL)
    {
        return;
    }

//�����������ĵ�1���ڵ�,���Ǹ��ڵ�
    Node *temp = new Node;
    temp->data = *(post + len - 1);
    temp->left = NULL;
    temp->right = NULL;

    if (*proot == NULL)
    {
        *proot = temp;
    }

    if (len == 1) //�ݹ����len==1��ֻ��1���ڵ��ˣ�ֱ�ӷ���
    {
        return;
    }

//���������з����������ˣ����η�
//���������������Ѱ�����������зֵ�
    int leftTreeLen = 0;
    int *p = inorder;	//�����������
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
//���������������ӦΪ���inorder,����leftTreeLen,���������ӦΪinorder+leftTreeLen+1,����len-leftTreeLen-1
//���������������ӦΪ���post,����leftTreeLen,���������ӦΪpost + len - 1  - rightTreeLen ,����len-leftTreeLen-1

    if (leftTreeLen > 0)	//�ؽ�������
    {
        rebuildTree(inorder, post, leftTreeLen, &((*proot)->left));
    }

    if (rightTreeLen > 0)	//�ؽ�������
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
