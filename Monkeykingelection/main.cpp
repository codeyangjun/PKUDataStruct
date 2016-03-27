#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct monkey
{
    int num;
    monkey *next;
};

int joseph(int sum, int cycle)
{
    int i;
    monkey *p_old, *p_new, *head=NULL;

    head = new monkey;
//此处创建一个循环链表(create a circular chained table)
    head->num = 1;
    p_old = head;
    for(i=2; i<=sum; i++)
    {
        p_new = new monkey;
        p_new->num = i;
        p_old->next = p_new;
        p_old = p_new;
    }

    p_old->next = head;

    p_old = head;
    i = 1;
//循环删除元素直到只剩下最后一个元素(delete elements circularly until the last element left)
    while(1)
    {
        p_new = p_old->next;
        i++;
        if(p_new->next == p_new)//只剩下最后1个猴子了
            break;
        if((i % cycle) == 0)
        {
            p_old->next = p_new->next;
            p_old = p_new->next;
            delete p_new;
            i = 1;
        }
        else
        {
            p_old = p_new;
        }
    }

    return p_new->num;
}

int main(void)
{
    freopen("data.txt","r",stdin);
    std::ios::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    cout<<joseph(n, m)<<endl;
    return 0;
}
