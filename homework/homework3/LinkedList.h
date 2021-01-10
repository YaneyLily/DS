//
// Created by Yaney on 2021/1/7.
//
#include<iostream>

#ifndef HOMEWORK3_LINKEDLIST_H
#define HOMEWORK3_LINKEDLIST_H
typedef int ElementType;
class List//定义一个List类
{
//--------------------内部定义一个node类-------------------------
private:
    class node//定义一个node类
    {
    public:
        ElementType data;//节点的数据
        node *next;//节点的指针域

        node(ElementType value=0,node *link=0)//node类的构造函数
                :data(value),next(link)
        {}
    };
    typedef node *nodePointer;
//--------------------成员函数以及成员变量-------------------------
public:
    List();//构造函数
    ~List();//析构函数
    List(const List & origList);//复制构造函数
    const List & operator=(const List & rightHandSide);//赋值构造函数
    bool empty() const;//判空函数
    int size() const;//链表的大小（长度）
    void insert(const ElementType item,int pos);//插入函数
    void display(ostream & out) const;//输出函数
    //-------------------------------------------
    void import(const ElementType *array,int size);//将数组元素导入链表的函数
    List sort();//排序函数
    List merge(const List & aList);//归并链表函数

private:
    nodePointer first;//定义一个头指针
    int mySize;//链表大小（长度）
};
ostream & operator<<(ostream & out,const List & aList);//重载输出操作符
#endif //HOMEWORK3_LINKEDLIST_H
