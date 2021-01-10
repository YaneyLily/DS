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

