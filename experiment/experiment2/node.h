//
// Created by Yaney on 2021/1/7.
//

#ifndef EXPERIMENT2_NODE_H
#define EXPERIMENT2_NODE_H
//--------------------内部定义一个node类-------------------------
template <typename T>
class node//定义一个node类
{
public:
    T data;//节点的数据
    node<T> *next;//节点的指针域
    node() : next(NULL){}
    node(T value=0,node *link=0)//node类的构造函数
            :data(value),next(link)
    {}

};
#endif //EXPERIMENT2_NODE_H
