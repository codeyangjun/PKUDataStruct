#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
#define N 1000010

char s[N];
int next[N];
int len;

void buildNext(const char *s)//kmp����next��
{
	int i = 0, j = -1;
	next[0] = -1;
	while(i != len)
	{
		if(j == -1 || s[i] == s[j])
        {
            i++;
            j++;
            next[i] = j;
        }
		else
        {
            j = next[j];
        }

	}
}

int main()
{
	int T = 1;
	int length, add;
	while(scanf("%d", &len) && len)
	{
		scanf("%s", s);
		buildNext(s);
		printf("Test case #%d\n", T++);
		for(int i = 1; i <= len; ++i)
		{
			length = i - next[i]; //ѭ���ڵĳ���
			if(i != length && i % length == 0) //����ж��ѭ��
				printf("%d %d\n", i, i / length);
		}
		printf("\n");
	}
	return 0;
}
