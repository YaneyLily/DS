[TOC]

# HOMEWORK1——邮箱问题

## 题目

有一天晚上，邮差Peter感到非常无聊，为了打破夜班的单调，他使用邮局中的一行邮箱进行了以下的实验。这些邮箱被从1-150进行了编号，然后从邮箱2开始，他打开了所有编号为偶数的邮箱的门，而保持其他邮箱的门关着。接着，从邮箱3开始，每个3个邮箱，如果这个邮箱的门是关着的他就打开这个邮箱的门，而如果门是开着的，他就关上门。然后他每隔4个邮箱重复这个过程，再每隔5个邮箱重复这个过程如此下去。当结束时，他被关着的邮箱的分布所惊讶了。编写一个程序来判断哪些邮箱是关着的。

## 代码

```c++
/*************************************************
Copyright:Yaney
Author:网工1701 杨莉
Date:2021-01-05
Description:数据结构第一次作业：书上P126第二题：邮箱问题
**************************************************/
#include<iostream>
using namespace std;
const int CAPACITY = 150;//邮箱的个数
/*************************************************
Function:       // 初始化邮箱
Description:    // 将所有的邮箱设置为false，即关闭状态
Input:          // array为动态数组的类型，CAPACITY为动态数组的容量
*************************************************/
void InitMailbox(bool *array,int CAPACITY);
/*************************************************
Function:       // 转换邮箱的状态
Description:    // 从邮箱2开始，他打开了所有编号为偶数的
                // 邮箱的门，而保持其他邮箱的门关着。接着，
                // 从邮箱3开始，每个3个邮箱，如果这个邮箱
                // 的门是关着的他就打开这个邮箱的门，而如
                // 果门是开着的，他就关上门。然后他每隔4个
                // 邮箱重复这个过程，再每隔5个邮箱重复这个
                // 过程如此下去。
Input:          // array为动态数组的类型，CAPACITY为动态
                // 数组的容量
*************************************************/
void TransformMailbox(bool *array,int CAPACITY);
/*************************************************
Function:       // 查看关闭的邮箱
Description:    // 输出所有为false的邮箱号（1为起始邮箱）
Input:          // array为动态数组的类型，CAPACITY为动态数组的容量
*************************************************/
void ClosedMailbox(bool *array,int CAPACITY);
int main()
{
    bool *array = new bool[CAPACITY];//创建一个动态数组
    InitMailbox(array,CAPACITY);//默认所有的邮箱是关闭状态
    TransformMailbox(array,CAPACITY);//按照题目要求改变邮箱状态
    ClosedMailbox(array,CAPACITY);//输出所有关闭着的邮箱号
    delete []array;//释放内存
}
void InitMailbox(bool *array,int CAPACITY)
{
    for (int i = 0; i < CAPACITY; i++)//将150个门默认为关/false
    {
        array[i] = false;
    }
}
void TransformMailbox(bool *array,int CAPACITY)
{
    for (int j = 2; j <= CAPACITY; j++)//每隔j个邮箱，从2开始到150
    {
        for (int i = 0; i < CAPACITY; i++)
        {
            if ((i + 1) % j == 0)//改变第j个门的状态
            {
                if (array[i] == true)
                    array[i] = false;
                else
                    array[i] = true;
            }
        }
    }
}
void ClosedMailbox(bool *array,int CAPACITY)
{
    for (int i = 0; i < CAPACITY; i++)
    {
        if (array[i]==false)
            cout << i+1<<endl;
    }
}


```

## 执行

![](/Users/yaney/Library/Application Support/typora-user-images/image-20210105142140078.png)

------

# HOMEWORK2——向量的练习

## 题目

- 12题：存储从0～99的整数序列
- 13题：逆序存储从0～99的整数序列
- 14题：偶数存false，奇数存true
- 15题：判断vector是否升序
- 16题：找到vector中的值的范围

## 代码

```c++
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
```

## 执行

![image-20210106181249934](/Users/yaney/Library/Application Support/typora-user-images/image-20210106181249934.png)
