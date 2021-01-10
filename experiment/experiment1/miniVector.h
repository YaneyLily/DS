//
// Created by Yaney on 2021/1/6.
//

#ifndef EXPERIMENT1_MINIVECTOR_H
#define EXPERIMENT1_MINIVECTOR_H

#include <iostream>
using namespace std;

class miniVector {
public:
    explicit miniVector(int size=0); //构造函数
    miniVector(const miniVector & obj); //以对象为形参的构造函数
    ~miniVector();  //析构函数
    miniVector & operator=(const miniVector & rhs);//重载运算符=，实现对象与对象之间的赋值
    int & back();   //返回数组最后一个元素的值
    const int& back() const;//返回数组最后一个元素的值，且为只读
    int & operator[](int i);//重载下标运算符
    const int & operator[](int i)const;//重载下标运算符，且为只读
    void push_back(const int & item);//从数组尾部压入一个值为item的元素
    void pop_back();    //删除数组最后一个元素
    int size() const;//返回数组元素大小，且为只读
    bool empty() const;//判空，且为只读
    int capacity() const;//返回数组容量，且为只读

    //增加成员
    void display(ostream & out) const;//输出vector的元素，且为只读模式
    void insert(int pos,int item);//在第pos个位置处插入item
    void Delete(const int value);//删除vector中值为value的函数


private:
    int vCapacity;//数组容量
    int vSize;//数组数量
    int *vArr;//动态数组指针
    void reserve(int n,bool copy);//调整数组容量，且可以保存数组原数据
};


#endif //EXPERIMENT1_MINIVECTOR_H
