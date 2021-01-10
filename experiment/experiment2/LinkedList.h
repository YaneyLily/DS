//
// Created by Yaney on 2021/1/7.
//
#include<iostream>
#include "node.h"
#ifndef EXPERIMENT2_LINKEDLIST_H
#define EXPERIMENT2_LINKEDLIST_H

typedef node<int> *NodePointer;
class List//定义一个List类
{
//--------------------成员函数以及成员变量-------------------------
public:
    List();//构造函数
    ~List();//析构函数
    List(const List & origList);//复制构造函数
    const List & operator=(const List & rightHandSide);//赋值构造函数
    bool empty() const;//判空函数
    int size() const;//链表的大小（长度）
    void insert(const int item,int pos);//插入函数
    void display(ostream & out) const;//输出函数
    //-------------------------------------------
    void import(const int *array,int size);//将数组元素导入链表的函数
    List sort();//排序函数
    List merge(const List & aList);//归并链表函数

    void changeFirst(NodePointer Pfirst);
    NodePointer getFirst();
    void getSize(int size);

private:
    NodePointer first;//定义一个头指针
    int mySize;//链表大小（长度）
};
ostream & operator<<(ostream & out,const List & aList);//重载输出操作符
#endif //EXPERIMENT2_LINKEDLIST_H
