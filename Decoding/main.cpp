#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    freopen("data.txt","r",stdin);
    std::ios::sync_with_stdio(false);

    char str[1000];
    int n,i,j;
    cin>>n;
    int ch;
    cin.get();

    for (i=0; i<n; i++)
    {
        memset(str,0,sizeof(char)*1000);
        cin.getline(str,1000);
        int length = strlen(str);
        for(j = 0; j < length; j++)
        {
            if((str[j]>='A' && str[j] <= 'Z')||(str[j]>='a' && str[j] <= 'z'))
            {
                if(str[j]=='Z')
                    str[j] = 'A';
                else if (str[j]=='z')
                {
                    str[j] ='a';
                }
                else
                {
                    str[j] = str[j] + 1;
                }
            }
        }
        cout<<str<<endl;
    }
    return 0;
}
