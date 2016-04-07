#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

char dict[10001][16];
char word[51][16];

int DictNum=0; //字典计数器
int WordNum=0; //单词计数器

void Input(void);
bool Change(char* word,char* dict);  //检查字符串word能否通过变换得到dict
bool Del(char* word,char* dict);  //检查字符串word能否通过删除得到dict
bool Add(char* word,char* dict);  //检查字符串word能否通过添加得到dict

int main(void)
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    std::ios::sync_with_stdio(false);

    Input();

    int* DictLen=new int[DictNum];  //记计算字典中各个单词的长度
    for(int n=0; n<DictNum; n++)
        DictLen[n]=strlen(dict[n]);

    for(int i=0; i<WordNum; i++)
    {
        int* address=new int[DictNum];  //记录word[i]通过变化得到的单词在dict中的下标
        int pa=0; //字典中有几个与word[i]匹配

        bool flag=false;  //标记字典中是否含有单词word[i]
        int len=strlen(word[i]);

        for(int k=0; k<DictNum; k++) //遍历字典
        {
            if(DictLen[k]==len)  //Change or Equal
            {
                if(!strcmp(word[i],dict[k]))//相等
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

    DictNum--;  //剔除'#'
    WordNum--;
    return;
}

bool Change(char* word,char* dict)  //WordLen==DictLen
{
    int dif=0;  //记录word与dict中在相同位置出现不同字符的个数

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
    int dif=0;  //记录word与dict中在对应位置出现不同字符的个数

    while(*word)
    {
        if(*word != *dict)
        {
            word++;  //word后移一位再匹配
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
    int dif=0;  //记录word与dict中在对应位置出现不同字符的个数

    while(*dict)
    {
        if(*word != *dict)
        {
            dict++;  //dict后移一位再匹配
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
