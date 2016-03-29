#include <iostream>
#include <stack>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>

/**
1����ջ�����ʽת����Ϊ��׺ʽ��Ȼ������׺���ʽ��ֻ�ж����Ƿ���ȡ�
2��������һ�����������ĸת��֮���������ֵ����������ĸ��ֵ��
���õ���(int)s1[i]ֱ�ӽ���ASCII��Ϊ��ֵ�Դ������ҲAC��
�����������ֻ���ж��������ʽ�Ƿ�����ֵ���ǵȼ۵Ķ������ж�������ʽ�Ƿ�ȼ�
����˵��(b-a+c)*2 �� (1+c)*2Ҳ��ȣ����������Ϊ��ʽ�Ļ��������ǲ���ȵģ�
*/


using namespace std ;
char s1[100] ;//���������׺���ʽ������
map<char,int>m ;//+ - *�����ȼ�

bool IsChar( char ch )
{
    if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' ||
            ch >= '1' && ch <= '9' )
        return true;
    else
        return false;
}

void Change( char ch[] )//����׺���ʽת��Ϊ��׺���ʽ
{
    stack<char> s ;//��ջ������+ - *����
    int len = strlen( ch ) ;
    int i, j = 0 ;
    for ( i = 0 ; i < len ; i++ )
    {
        if ( IsChar( ch[i] ) )
        {
            s1[j++] = ch[i] ;
        }
        else
        {
            switch( ch[i] )
            {
            case '(' :
                s.push( ch[i] ) ;//����( ,��ջ
                break ;
            case ')' :
                while ( s.top() != '(' )
                {
                    s1[j++] = s.top() ;
                    s.pop() ;
                }
                s.pop() ;//����(
                break ;
            case '+' :
            case '-' :
            case '*' :
                while ( !s.empty() && m[s.top()] >= m[ch[i]] )//ջ�������ȼ���,����ջ���������
                {
                    s1[j++] = s.top() ;
                    s.pop() ;
                }
                s.push(ch[i]) ;//ѹ��Ŀǰ�ַ���ɨ��������ַ�
                break ;
            }
        }
    }

    while ( !s.empty() )
    {
        s1[j++] = s.top() ;
        s.pop() ;
    }
    s1[j] = '\0' ;//����ַ����Ľ�����ʶ
//    cout << s1 << endl ;
}

int Result()//�˿�����s1�б����Ϊ��׺���ʽ
{
    stack<int> s ;
    int len = strlen(s1), i ;
    for ( i = 0 ; i < len ; i++ )
    {
        if ( IsChar(s1[i]) )
        {
            if ( s1[i] >= '1' && s1[i] <= '9' )//ѹ������
                s.push( s1[i]-'0' ) ;//
            else
            {
                s.push( (int)s1[i] ) ;//ѹ���ַ���ascii ֵ
            }
        }
        else
        {
            int a, b ;
            a = s.top() ;
            s.pop() ;
            b = s.top() ;
            s.pop() ;
            switch( s1[i] )
            {
            case '+' :
                s.push(a+b) ;
                break ;
            case '-' :
                s.push(b-a) ;
                break ;
            case '*' :
                s.push(a*b) ;
                break ;
            }
        }
    }
    return s.top() ;//���غ�׺���ʽ��������ս��
}

int main()
{
    freopen("data.txt","r",stdin);
    std::ios::sync_with_stdio(false);

    int N ;
    char ch1[100], ch2[100] ;
    cin >> N ;
    m['+']=1;
    m['-']=1;
    m['*']=2;
    m['(']=0;
    cin.getline( ch1, 100, '\n' ) ;
    while ( N-- )
    {
        cin.getline( ch1, 100, '\n' ) ;
        cin.getline( ch2, 100, '\n' ) ;
        int n1, n2 ;
        Change( ch1 ) ;
        n1 = Result() ;
// cout << n1 << endl ;
        Change( ch2 ) ;
        n2 = Result() ;
// cout << n2 << endl ;
        if ( n1 == n2 )
            cout << "YES" << endl ;
        else
            cout << "NO" << endl ;
    }
    return 0 ;
}
