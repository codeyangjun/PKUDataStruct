#include <iostream>   // std::cout
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstddef>

using namespace std;
int num;

int getNumber(string &str)
{
    int n = 0;
    //处理百位
    std::size_t index = str.find("hundred");
    if(index != string::npos)
    {
        if(str.find("one") != string::npos && str.find("one") < index )
        {
            n += 100;
        }
        if(str.find("two") != string::npos && str.find("two") < index )
        {
            n += 200;
        }
        if(str.find("three") != string::npos && str.find("three") < index )
        {
            n += 300;
        }
        if(str.find("four") != string::npos && str.find("four") < index )
        {
            n += 400;
        }
        if(str.find("five") != string::npos && str.find("five") < index )
        {
            n += 500;
        }
        if(str.find("six") != string::npos && str.find("six") < index )
        {
            n += 600;
        }
        if(str.find("seven") != string::npos && str.find("seven") < index )
        {
            n += 700;
        }
        if(str.find("eight") != string::npos && str.find("eight") < index )
        {
            n += 800;
        }
        if(str.find("nine") != string::npos && str.find("nine") < index )
        {
            n += 900;
        }

        str = str.substr(index + 7);//去掉了百位
    }

    //处理十位
    if((index = str.find("ten")) != string::npos)
    {
        n += 10;
        str = str.substr(index + 3);
    }
    if((index = str.find("eleven")) != string::npos)
    {
        n += 11;
        str = str.substr(index + 6);
    }
    if((index = str.find("twelve")) != string::npos)
    {
        n += 12;
        str = str.substr(index + 6);
    }
    if((index = str.find("thirteen")) != string::npos)
    {
        n += 13;
        str = str.substr(index + 8);
    }
    if((index = str.find("fourteen")) != string::npos)
    {
        n += 14;
        str = str.substr(index + 8);
    }
    if((index = str.find("fifteen")) != string::npos)
    {
        n += 15;
        str = str.substr(index + 7);
    }
    if((index = str.find("sixteen")) != string::npos)
    {
        n += 16;
        str = str.substr(index + 7);
    }
    if((index = str.find("seventeen")) != string::npos)
    {
        n += 17;
        str = str.substr(index + 9);
    }
    if((index = str.find("eighteen")) != string::npos)
    {
        n += 18;
        str = str.substr(index + 8);
    }
    if((index = str.find("nineteen")) != string::npos)
    {
        n += 19;
        str = str.substr(index + 8);
    }
    if(str.find("twenty") != string::npos)
    {
        n += 20;
        str = str.substr(index + 6);
    }
    if((index = str.find("thirty")) != string::npos)
    {
        n += 30;
        str = str.substr(index + 6);
    }
    if((index = str.find("forty")) != string::npos)
    {
        n += 40;
        str = str.substr(index + 5);
    }
    if((index = str.find("fifty")) != string::npos)
    {
        n += 50;
        str = str.substr(index + 5);
    }
    if((index = str.find("sixty"))!= string::npos)
    {
        n += 60;
        str = str.substr(index + 5);
    }
    if((index = str.find("seventy")) != string::npos)
    {
        n += 70;
        str = str.substr(index + 7);
    }
    if((index = str.find("eighty")) != string::npos)
    {
        n += 80;
        str = str.substr(index + 6);
    }
    if((index = str.find("ninety")) != string::npos)
    {
        n += 90;
        str = str.substr(index + 6);
    }

    //处理个位
    if(str.find("one") != string::npos)
    {
        n += 1;
    }
    if(str.find("two") != string::npos)
    {
        n += 2;
    }
    if(str.find("three") != string::npos)
    {
        n += 3;
    }
    if(str.find("four") != string::npos)
    {
        n += 4;
    }
    if(str.find("five") != string::npos)
    {
        n += 5;
    }
    if(str.find("six") != string::npos)
    {
        n += 6;
    }
    if(str.find("seven") != string::npos)
    {
        n += 7;
    }
    if(str.find("eight") != string::npos)
    {
        n += 8;
    }
    if(str.find("nine") != string::npos)
    {
        n += 9;
    }

    return n;
}
void parse(string &str)
{
    //cout << str << endl;
    //处理百万
    std::size_t index = str.find("million");
    if(index != string::npos)
    {
        string subStr = str.substr(0, index);
        int n = getNumber(subStr);
        num += n * 1000000;
        str = str.substr(index + 7);//去掉了million
    }

    //处理千
    index = str.find("thousand");
    if(index != string::npos)
    {
        string subStr = str.substr(0, index);
        int n = getNumber(subStr);
        num += n * 1000;
        str = str.substr(index + 8);//去掉了thousand
    }

    //处理剩余
    int n = getNumber(str);
    num += n;

}

int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    std::ios::sync_with_stdio(false);

    std::string str;
    std::getline (std::cin,str);
    while(!str.empty())
    {
        num = 0;
        bool isNegative = ((str.find("negative") != string::npos) ? true : false);
        parse(str);
        if(isNegative)
        {
            num *= -1;
        }
        cout << num << endl;

        std::getline (std::cin,str);
    }
    return 0;
}
