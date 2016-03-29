#include <iostream>
#include <stack>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>

/**
1，用栈将表达式转换成为后缀式，然后计算后缀表达式的只判断其是否相等。
2，其中有一个问题就是字母转换之后如何算其值来代表其字母的值，
我用的是(int)s1[i]直接将其ASCII作为数值对待，结果也AC了
（看来这个题只是判断两个表达式是否在数值上是等价的而不是判断两个公式是否等价
比如说：(b-a+c)*2 与 (1+c)*2也相等，但是如果作为公式的话这两个是不相等的）
*/


using namespace std ;
char s1[100] ;//用来保存后缀表达式的数组
map<char,int>m ;//+ - *的优先级

bool IsChar( char ch )
{
    if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' ||
            ch >= '1' && ch <= '9' )
        return true;
    else
        return false;
}

void Change( char ch[] )//将中缀表达式转化为后缀表达式
{
    stack<char> s ;//用栈来保存+ - *符号
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
                s.push( ch[i] ) ;//遇到( ,入栈
                break ;
            case ')' :
                while ( s.top() != '(' )
                {
                    s1[j++] = s.top() ;
                    s.pop() ;
                }
                s.pop() ;//弹出(
                break ;
            case '+' :
            case '-' :
            case '*' :
                while ( !s.empty() && m[s.top()] >= m[ch[i]] )//栈顶的优先级高,弹出栈顶的运算符
                {
                    s1[j++] = s.top() ;
                    s.pop() ;
                }
                s.push(ch[i]) ;//压人目前字符串扫描读到的字符
                break ;
            }
        }
    }

    while ( !s.empty() )
    {
        s1[j++] = s.top() ;
        s.pop() ;
    }
    s1[j] = '\0' ;//添加字符串的结束标识
//    cout << s1 << endl ;
}

int Result()//此刻数组s1中保存的为后缀表达式
{
    stack<int> s ;
    int len = strlen(s1), i ;
    for ( i = 0 ; i < len ; i++ )
    {
        if ( IsChar(s1[i]) )
        {
            if ( s1[i] >= '1' && s1[i] <= '9' )//压入数字
                s.push( s1[i]-'0' ) ;//
            else
            {
                s.push( (int)s1[i] ) ;//压人字符的ascii 值
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
    return s.top() ;//返回后缀表达式计算的最终结果
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
