#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

char dict[10001][16];
char word[51][16];

int DictNum=0; //�ֵ������
int WordNum=0; //���ʼ�����

void Input(void);
bool Change(char* word,char* dict);  //����ַ���word�ܷ�ͨ���任�õ�dict
bool Del(char* word,char* dict);  //����ַ���word�ܷ�ͨ��ɾ���õ�dict
bool Add(char* word,char* dict);  //����ַ���word�ܷ�ͨ����ӵõ�dict

int main(void)
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    std::ios::sync_with_stdio(false);

    Input();

    int* DictLen=new int[DictNum];  //�Ǽ����ֵ��и������ʵĳ���
    for(int n=0; n<DictNum; n++)
        DictLen[n]=strlen(dict[n]);

    for(int i=0; i<WordNum; i++)
    {
        int* address=new int[DictNum];  //��¼word[i]ͨ���仯�õ��ĵ�����dict�е��±�
        int pa=0; //�ֵ����м�����word[i]ƥ��

        bool flag=false;  //����ֵ����Ƿ��е���word[i]
        int len=strlen(word[i]);

        for(int k=0; k<DictNum; k++) //�����ֵ�
        {
            if(DictLen[k]==len)  //Change or Equal
            {
                if(!strcmp(word[i],dict[k]))//���
                {
                    flag=true;
                    break;
                }
                else if(Change(word[i],dict[k]))
                    address[pa++]=k;
            }
            else if(len-DictLen[k]==1)  //Delete
            {
                if(Del(word[i],dict[k]))
                    address[pa++]=k;
            }
            else if(DictLen[k]-len==1)  //Add
            {
                if(Add(word[i],dict[k]))
                    address[pa++]=k;
            }
        }

        /*Output*/

        if(flag)
            cout<<word[i]<<" is correct"<<endl;
        else
        {
            cout<<word[i]<<": ";
            for(int j=0; j<pa; j++)
                cout<<dict[ address[j] ]<<' ';
            cout<<endl;
        }

        delete address;
    }
    return 0;
}

void Input(void)
{
    while(cin>>dict[DictNum] && dict[DictNum++][0]!='#');
    while(cin>>word[WordNum] && word[WordNum++][0]!='#');

    DictNum--;  //�޳�'#'
    WordNum--;
    return;
}

bool Change(char* word,char* dict)  //WordLen==DictLen
{
    int dif=0;  //��¼word��dict������ͬλ�ó��ֲ�ͬ�ַ��ĸ���

    while(*word)
    {
        if(*(word++) != *(dict++))
        {
            dif++;
            if(dif>1)
                return false;
        }
    }
    return true;
}

bool Del(char* word,char* dict)  //WordLen==DictLen+1
{
    int dif=0;  //��¼word��dict���ڶ�Ӧλ�ó��ֲ�ͬ�ַ��ĸ���

    while(*word)
    {
        if(*word != *dict)
        {
            word++;  //word����һλ��ƥ��
            dif++;
            if(dif>1)
                return false;
        }
        else
        {
            word++;
            dict++;
        }
    }
    return true;
}

bool Add(char* word,char* dict)  //WordLen==DictLen-1
{
    int dif=0;  //��¼word��dict���ڶ�Ӧλ�ó��ֲ�ͬ�ַ��ĸ���

    while(*dict)
    {
        if(*word != *dict)
        {
            dict++;  //dict����һλ��ƥ��
            dif++;
            if(dif>1)
                return false;
        }
        else
        {
            word++;
            dict++;
        }
    }
    return true;
}
