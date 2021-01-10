#include<iostream>
using namespace std;

#include"LinkedList.h"
#include "node.h"
List import(const int *array,int size);
int main()
{
    cout<<"----------------------The program test is begin---------------------"<<endl;
    cout<<endl;
    cout<<"Constructing intList1 and intList2\n";
    List intList1,intList2;//定义两个链表
    cout<<"List1 is empty? "<<boolalpha<<intList1.empty()<<endl;//测试判空函数
    cout<<"Display the intList1's size:"<<intList1.size()<<endl;//测试size函数
    cout<<"List2 is empty? "<<boolalpha<<intList2.empty()<<endl;//测试判空函数
    cout<<"Display the intList2's size:"<<intList2.size()<<endl;//测试size函数
    cout<<"---------------------------------------------------------------------"<<endl;

    int a[10]={1,2,3,4,5,6,7,8,9,10};//初始化两个数组
    int b[10]={11,12,13,14,15,16,17,18,19,20};//初始化两个数组
    cout<<"There are two arrays now:";
    cout<<"a[10]={1,2,3,4,5,6,7,8,9,10};b[10]={11,12,13,14,15,16,17,18,19,20};"<<endl;
    intList1=import(a,10);
    //intList1.import(a,10);//测试导入函数
    intList2.import(b,10);//测试导入函数

    cout<<"After importing the data of the array into the linked list"<<endl;
    cout<<"List1 is empty? "<<boolalpha<<intList1.empty()<<endl;//再次测试判空函数
    cout<<"Display the intList1's size:"<<intList1.size()<<endl;//再次测试size函数
    cout<<"List2 is empty? "<<boolalpha<<intList2.empty()<<endl;//再次测试判空函数
    cout<<"Display the intList2's size:"<<intList2.size()<<endl;//再次测试size函数
    cout<<"---------------------------------------------------------------------"<<endl;

    cout<<"Display the data in the linked list:"<<endl;
    cout<<"intList1 :"<<endl; intList1.display(cout);//显示导入数组数据后的结果
    cout<<"intList2 :"<<endl; intList2.display(cout);//显示导入数组数据后的结果
    cout<<"---------------------------------------------------------------------"<<endl;

    cout<<"After sorting the data in the list from large to small"<<endl;
    cout<<"intList1 :"<<endl;
    List A3=intList1.sort();//排序后的结果返回给A3链表
    A3.display(cout);//显示将第一个链表排序后的结果
    cout<<"intList2 :"<<endl;
    List B3=intList2.sort();//排序后的结果返回给B3链表
    B3.display(cout);//显示将第二个链表排序后的结果
    cout<<endl;

    cout<<"The data in the original list"<<endl;
    cout<<"The original intList1 :"<<endl;
    intList1.display(cout);//显示将第一个链表排序前的结果，观察是否数据被破坏
    cout<<"The original intList2 :"<<endl;
    intList2.display(cout);//显示将第二个链表排序前的结果，观察是否数据被破坏
    cout<<"---------------------------------------------------------------------"<<endl;

    cout<<"After merging two linked lists"<<endl;
    List C=A3.merge(B3);//将排序已完成的A3链表与B3链表归并，并将结果返回给新链表C
    cout<<"intList C :"<<endl;
    C.display(cout);//输出归并链表后的结果
    cout<<endl;

    cout<<"The data in the original list"<<endl;
    cout<<"The original A3 :"<<endl;
    A3.display(cout);//显示将第一个链表归并前的数据，观察是否数据被破坏
    cout<<"The original B3 :"<<endl;
    B3.display(cout);//显示将第二个链表排序前的数据，观察是否数据被破坏

    cout<<"Insert a node into the linked list"<<endl;//检验插入函数是否正确
    C.insert(2017,10);//将2017插入到第十个节点之后
    C.display(cout);//输出结果

    /*排序函数中已经使用复制构造函数，归并函数中已经使用赋值构造函数，
      主要作用是生成新链表，相关操作在新链表上进行，以防止原有链表数据被破坏，
      在此，不再进行验证*/

    cout<<"----------------------The program test is end--------------------------"<<endl;
    return 0;
}
List import(const int *array,int size)//将数组元素导入链表的函数-----------------
{
    List L1;
    if(size>0)//保证数组元素个数大于0
    {
        NodePointer currPtr,newnode;//这两个指针将完成对数组数据的导入
        NodePointer first;
        L1.changeFirst(new node<int>(*array));//头指针指向第一个节点，同时将数组元素初始化在节点的数据域
        currPtr=L1.getFirst();
        //L1.getFirst(currPtr);
        for(int i=1;i<size;i++)//将数组剩余数据导入链表中
        {
            newnode=new node<int>(*(array+i));//数组数据从前往后导入链表
            currPtr->next=newnode;//连接操作
            currPtr=newnode;//后移操作
        }
    }
    else//数组元素小于等于0进行异常报错
    {
        cerr<<"The size of the array should be greater than 0"<<endl;
    }
    L1.getSize(size);//更新链表长度
    return L1;
}