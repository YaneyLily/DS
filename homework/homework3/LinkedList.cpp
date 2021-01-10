//
// Created by Yaney on 2021/1/7.
//
#include<iostream>
#include<cassert>
using namespace std;

#include"LinkedList.h"

List::List()//构造函数------------------------
        :first(0),mySize(0)
{}

List::~List()//析构函数------------------------
{
    nodePointer currPtr=first,//定义指向节点的指针
    nextPtr;
    while(currPtr!=0)//当前指针非0
    {
        nextPtr=currPtr->next;
        delete currPtr;  //删除当前指针
        currPtr=nextPtr;
    }
    mySize=0;//链表大小置为0
}

List::List(const List & origList)//复制构造函数-----------------------
        :mySize(origList.mySize)
{
    if(!origList.empty())//传进来的链表非空
    {
        nodePointer ptr=origList.first;//ptr指向参数链表的头部，以便后续进行复制操作
        first=new node(ptr->data);//复制参数链表的头指针
        nodePointer	currPtr=first,//当前指针，这两个指针将完成对新链表的复制与连接
        nextPtr;//下一个指针
        for(int i=0;i<mySize-1;i++)//循环mySize-1次操作
        {
            ptr=ptr->next;//ptr指向参数链表的下一个指针
            nextPtr=new node(ptr->data);//nextPtr指向新节点并且复制ptr（参数链表）的数据
            currPtr->next=nextPtr;//currPtr指针的指针域存放nextPtr指向的节点的地址，完成节点的连接
            currPtr=nextPtr;//currPtr指针指向nextPtr指向的节点
        }
    }
    else//链表为空，提示并退出
    {
        cerr<<"***List is empty, exit this program***\n";
        exit(1);//退出程序
    }
}

const List & List::operator=(const List & rightHandSide)//赋值构造函数--------------------------
{
    if(this!=&rightHandSide)//确认不是自我赋值
    {
        if(rightHandSide.empty())//参数链表非空
        {
            cerr<<"***List is empty, exit this program***\n";
            exit(1);
        }

        nodePointer ptr=rightHandSide.first;//ptr指向参数链表的第一个节点
        first=new node(ptr->data);//复制参数链表的头指针
        nodePointer	currPtr=first,//当前指针，这两个指针将完成对新链表的复制与连接
        nextPtr;//下一个指针
        if(mySize!=rightHandSide.mySize)//如果需要，分配一个新链表
        {
            this->~List();//调用析构函数，销毁原链表
            for(int i=0;i<mySize-1;i++)//循环mySize-1次操作
            {
                ptr=ptr->next;//ptr指向参数链表的下一个指针
                nextPtr=new node(ptr->data);//nextPtr指向新节点并且复制ptr（参数链表）的数据
                currPtr->next=nextPtr;//currPtr指针的指针域存放nextPtr指向的节点的地址，完成节点的连接
                currPtr=nextPtr;//currPtr指针指向nextPtr指向的节点
            }
        }
        else//此时，不需要重新创建链表，将在原链表上操作
        {
            for(int i=0;i<mySize-1;i++)//循环mySize-1次操作
            {
                currPtr=currPtr->next;//currPtr指针指向下一个节点
                ptr=ptr->next;//ptr指针指向参数链表的下一个节点
                currPtr->data=ptr->data;//将参数链表的节点数据复制到currPtr指针的数据域
            }
        }
    }
    return *this;//返回新链表对象
}

bool List::empty() const//判空函数-----------------------
{
    return first==0;
}

int List::size() const//链表的大小（长度）------------------------
{
    return mySize;
}

void List::insert(ElementType item,int pos)//插入到第pos个节点之后的位置----------
{
    assert(pos>=0);//保证插入位置非负
    nodePointer ptr=first,
            newPtr=new node(item);//定义一个带数据的节点
    if(pos==0)//表示插入到第一个节点位置
    {
        newPtr->next=first;
        first=newPtr;
    }

    else if(pos<=mySize)//表示插入到第1到mySize节点之后位置
    {
        for(int i=1;i<pos;i++)
            ptr=ptr->next;//循环结束时，ptr指向第pos个节点
        newPtr->next=ptr->next;//插入新节点操作
        ptr->next=newPtr;//插入新节点操作
    }
    else//pos位置越界报错
    {
        delete newPtr;//将未使用的新节点返还给堆
        cerr<<"***The position out of range***\n";
        return;
    }
    mySize++;//链表长度加一
}

void List::import(const ElementType *array,int size)//将数组元素导入链表的函数-----------------
{
    if(size>0)//保证数组元素个数大于0
    {
        nodePointer currPtr,newnode;//这两个指针将完成对数组数据的导入
        first=new node(*array);//头指针指向第一个节点，同时将数组元素初始化在节点的数据域
        currPtr=first;
        for(int i=1;i<size;i++)//将数组剩余数据导入链表中
        {
            newnode=new node(*(array+i));//数组数据从前往后导入链表
            currPtr->next=newnode;//连接操作
            currPtr=newnode;//后移操作
        }
    }
    else//数组元素小于等于0进行异常报错
    {
        cerr<<"The size of the array should be greater than 0"<<endl;
        return;
    }
    mySize=size;//更新链表长度
}

List List::sort()//排序函数-------------------------
{
    List newList(*this);//调用复制构造函数，将原链表对象复制于新链表，防止破坏原链表
    if(mySize<=0)//链表非空
    {
        cerr<<"***The linked list has no node,exit this program***"<<endl;
        exit(1);
    }
    ElementType tem;//交换变量
    nodePointer currPtr,nextPtr;//这两个指针将完成链表数据的排序
    for(int i=0;i<mySize-1;++i) //冒泡排序
    {
        for(int j=0;j<mySize-i-1;j++)//内层循环
        {
            currPtr=newList.first;//当前指针指向第一个节点
            for(int k=0;k<j;k++)//循环结束后，当前指针指向第j+1个节点
                currPtr=currPtr->next;
            nextPtr=currPtr->next;//nextPtr指向第j+2个节点
            if(currPtr->data<nextPtr->data)//若第j+1个节点的数据小于第j+2个节点的数据，则交换数据
            {
                tem=currPtr->data;
                currPtr->data=nextPtr->data;//交换语句
                nextPtr->data=tem;
            }
        }
    }
    return newList;//返回新链表，此时原链表并未被破坏
}

List List::merge(const List & aList)//归并链表函数------------------------
{
    List newList1=*this,//调用复制构造函数，将第一个链表（*this）复制于新链表，防止破坏原链表
    newList2=aList;//调用复制构造函数，将第一个链表（aList）复制于新链表，防止破坏原链表
    List mergeList;//定义归并链表

    mergeList.mySize=(*this).mySize+aList.mySize;//归并链表的大小进行更新
    mergeList.first=new node(0);//归并链表的头指针指向一个数据域为0节点（此节点不是真正的头节点）
    nodePointer ptr1=newList1.first,//ptr1指向第一个链表的头节点
    ptr2=newList2.first,//ptr2指向第二个链表的头节点
    currPtr=mergeList.first,//currPtr指向归并链表的头节点
    nextPtr,//nextPtr与currPtr将完成归并链表各个节点的生成与连接
    tempPtr=mergeList.first;//指向归并链表的（伪）头指针，最后进行删除

    while(ptr1!=0&&ptr2!=0)//ptr1与ptr2均不为0
    {
        if(ptr1->data>ptr2->data)//ptr1指向的数据大于ptr2指向的数据
        {
            nextPtr=new node(ptr1->data);//生成一个数据等于ptr1->data的节点
            currPtr->next=nextPtr;//currPtr指针的指针域存放新节点地址，完成前后节点的连接
            currPtr=nextPtr;//currPtr指针指向新节点
            ptr1=ptr1->next;//ptr1指向第一个链表原节点的后一个节点
        }
        else
        {
            nextPtr=new node(ptr2->data);//生成一个数据等于ptr2->data的节点
            currPtr->next=nextPtr;//currPtr指针的指针域存放新节点地址，完成前后节点的连接
            currPtr=nextPtr;//currPtr指针指向新节点
            ptr2=ptr2->next;//ptr2指向第一个链表原节点的后一个节点
        }
    }
    if(ptr1==0)//第一个链表的所有数据都已导入归并链表中
    {
        if(ptr2!=0)//第二个链表有部分数据未导入归并链表中
        {
            while(ptr2!=0)//ptr2未读取完第二个链表的所有数据
            {
                nextPtr=new node(ptr2->data);//生成一个数据等于ptr2->data的节点
                currPtr->next=nextPtr;//currPtr指针的指针域存放新节点地址，完成前后节点的连接
                currPtr=nextPtr;//currPtr指针指向新节点
                ptr2=ptr2->next;//ptr2指向第一个链表原节点的后一个节点
            }
        }
    }
    else//否则,第二个链表的所有数据都已导入归并链表中，而第一个链表仍有数据未导入
    {
        while(ptr1!=0)//ptr1未读取完第一个链表的所有数据
        {
            nextPtr=new node(ptr1->data);//生成一个数据等于ptr1->data的节点
            currPtr->next=nextPtr;//currPtr指针的指针域存放新节点地址，完成前后节点的连接
            currPtr=nextPtr;//currPtr指针指向新节点
            ptr1=ptr1->next;//ptr1指向第一个链表原节点的后一个节点
        }
    }
    mergeList.first=tempPtr->next;//归并链表的头节点指向下一个节点（真正的头节点）
    tempPtr=0;//临时指针置为0
    delete tempPtr;//删除（伪）头节点
    return mergeList;//返回归并链表
}

void List::display(ostream & out) const//输出函数-----------------------
{
    nodePointer ptr;
    for(ptr=first;ptr!=0;ptr=ptr->next)//从头到尾遍历并输出链表数据
        out<<ptr->data<<" ";
    out<<endl;
}

ostream & operator<<(ostream & out,const List & aList)//重载输出操作符------------------
{
    aList.display(out);//调用display（）成员函数
    return out;
}