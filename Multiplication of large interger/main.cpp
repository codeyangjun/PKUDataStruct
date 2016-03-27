#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <assert.h>
using namespace std;
void reverse_data( string &data);//字符串反转
void compute_value( string lhs,string rhs,string &result );

void reverse_data( string &data)
{
    char temp = '0';
    int start=0;
    int end=data.size()-1;
    assert( data.size()&& start <= end );
    while ( start < end )
    {
        temp = data[start];
        data[start++] = data[end];
        data[end--] = temp;
    }
}

void compute_value( string lhs,string rhs,string &result )
{
    reverse_data(lhs);
    reverse_data(rhs);

    int i = 0, j = 0, res_i = 0;
    int tmp_i = 0;
    int carry = 0;

    for ( i = 0; i!=lhs.size(); ++i, ++tmp_i )
    {
        res_i = tmp_i;  //在每次计算时，结果存储的位需要增加
        for ( j = 0; j!= rhs.size(); ++j )
        {
            carry += ( result[res_i] - '0' )+(lhs[i] - '0') * (rhs[j] - '0');//此处注意，每次计算并不能保证以前计算结果的进位都消除， 并且以前的计算结果也需考虑。
            result[res_i++] = ( carry % 10 + '0' );
            carry /= 10;
        }
        while (carry)//乘数的一次计算完成，可能存在有的进位没有处理
        {
            result[res_i++] = (carry % 10 + '0');
            carry /= 10;
        }
    }

    for (int i=result.size()-1; i>=0; i--)
    {
        if (result[i]!='0')
            break;
        else
            //result.pop_back();
            result.erase(result.begin() + i);
    }
    reverse_data(result);
}

int main()
{
    freopen("data.txt","r",stdin);
    std::ios::sync_with_stdio(false);

    string a,b;
    cin>>a>>b;

    string result(a.size()+b.size(),'0');
    compute_value(a,b,result);
    cout<<result<<endl;

    return 0;
}
