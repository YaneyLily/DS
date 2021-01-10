/*************************************************
Copyright:Yaney
Author:网工1701 杨莉
Date:2021-01-05
Description:数据结构第二次作业：vector的练习，P438 12～16
**************************************************/
#include <iostream>
#include <vector>
using namespace std;

/*************************************************
Function:       // 输出存储在一个vector中的值到一个ostream，使用一个常迭代器在vector中移动
Input:          // T是一个类型形参T，已经为类型T定义了<<操作符，ostream 已经被打开
Output:         // 储存在aVector中到值被输出到out中
*************************************************/
template <typename T>
void display(ostream & out,const vector<T> & aVector)//aVector是一个常引用形参，这样就不会被display函数所修改
{
    for(typename vector<T>::const_iterator it=aVector.begin();it!=aVector.end();it++)//it是一个常迭代器，也不能改变
    {
        out<<*it<<' ';
    }
    out<<endl<<endl;
}

/*************************************************
Function:       // 判断是否升序排序的。
Input:          // T是一个类型形参T，已经为类型T定义了<<操作符，ostream 已经被打开
Output:         // 如果aVector是升序排序的，返回true，否则返回false
*************************************************/
template <typename T>
bool ascend(const vector<T> & aVector)//aVector是一个常引用形参，这样就不会被ascend函数所修改
{
    for(int i=0;i<aVector.size()-1;i++)
    {
        if(aVector[i]>aVector[i+1]) return false;
        else return true;
    }
}

/*************************************************
Function:       // 找到aVector中的值的范围
Input:          // T是一个类型形参T，已经为类型T定义了<<、-、=操作符，ostream 已经被打开
Output:         // 返回aVector的最大值和最小值的差
*************************************************/
template <typename T>
T range(const vector<T> & aVector)//aVector是一个常引用形参，这样就不会被range函数所修改
{
    T min=aVector[0];
    T max=aVector[0];
    for(int i=1;i<aVector.size();i++)
    {
        if(aVector[i]<min)  min=aVector[i];
        else if(aVector[i]>max)    max=aVector[i];
    }
    return max-min;
}

int main() {
    /********12题：存储从0～99的整数序列************/
    vector<int> v12;
    for(int i=0;i<100;i++)
    {
        v12.push_back(i);
    }
    cout<<"12题：存储从0～99的整数序列:"<<endl;
    display(cout,v12);

    /********13题：逆序存储从0～99的整数序列************/
    vector<int> v13;
    for(int i=99;i>=0;i--)
    {
        v13.push_back(i);
    }
    cout<<"13题：逆序存储从0～99的整数序列"<<endl;
    display(cout,v13);

    /********14题：偶数存false，奇数存true************/
    vector<bool> v14(50);
    for(int i=0;i<50;i++)
    {
        v14[i]=(i%2==0);
    }
    cout<<"14题：偶数存false，奇数存true"<<endl;
    display(cout,v14);

    /********15题：判断vector是否升序************/
    if (ascend(v12))   cout<<"v12是升序函数"<<endl;
    else cout<<"v12不是升序函数"<<endl;

    if (ascend(v13))   cout<<"v13是升序函数"<<endl;
    else cout<<"v13不是升序函数"<<endl;

    if (ascend(v14))   cout<<"v14是升序函数"<<endl;
    else cout<<"v14不是升序函数"<<endl<<endl;

    /********16题：找到vector中的值的范围************/
    int range_v12=range(v12);
    cout<<"v12的值的范围是："<<range_v12<<endl;

    int range_v13=range(v13);
    cout<<"v13的值的范围是："<<range_v13<<endl;

    int range_v14=range(v14);
    cout<<"v14的值的范围是："<<range_v14<<endl;
    return 0;
}