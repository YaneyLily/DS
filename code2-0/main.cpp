//
// Created by Yaney on 2021/1/4.
//--Program to get size of int
//
#include <iostream>
using namespace std;
int main()
{
    int len1=sizeof (unsigned short);
    int len2=sizeof (unsigned);
    int len3=sizeof (unsigned long);
    cout<<len1<<endl<<len2<<endl<<len3<<endl;
    return 0;
}