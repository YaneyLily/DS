#include<iostream>
#include<vector>
using namespace std;
/*************************************************
Function:       // 输出存储在一个vector中的值到一个ostream，使用一个常迭代器在vector中移动
Input:          // T是一个类型形参T，已经为类型T定义了<<操作符，ostream 已经被打开
Output:         // 储存在aVector中到值被输出到out中
*************************************************/
template <typename T>
void display_Vector(ostream & out,const vector<T> & aVector)//aVector是一个常引用形参，这样就不会被display函数所修改
{
    for(typename vector<T>::const_iterator it=aVector.begin();it!=aVector.end();it++)//it是一个常迭代器，也不能改变
    {
        out<<*it<<' ';
    }
    out<<endl;
}
void display_Array(int *a,int n);
void BubbleSort_Vector(vector<int> &aVector) {
    int temp=0;
    for (int i = 0; i < aVector.size()-1; i++)
    {
        for (int j = 0; j < aVector.size() -1- i; j++)
        {
            if (aVector[j] > aVector[j + 1])
            {
                temp = aVector[j];
                aVector[j] = aVector[j + 1];
                aVector[j+1] = temp;
            }
        }
    }
}
void BubbleSort_Array(int *a, int size)
{//size为数组a的元素个数
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (a[j]>a[j + 1])
            { //大的沉底，小的冒泡（从小到大排序）
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    cout<<"用vector实现冒泡排序："<<endl;
    vector<int> v = { 6,1,2,7,9,3,4,5,10,8 };//vector初始化
    cout<<"原始数据："<<endl;
    display_Vector(cout,v);

    cout<<"进行冒泡排序过后："<<endl;
    BubbleSort_Vector(v);
    display_Vector(cout,v);

    cout<<endl<<"用数组实现冒泡排序"<<endl;
    int a[10]={ 6,1,2,7,9,3,4,5,10,8 };;
    cout<<"原始数据："<<endl;
    display_Array(a,10);

    cout<<"进行冒泡排序过后："<<endl;
    BubbleSort_Array(a,10);
    display_Array(a,10);
    return 0;
}
void display_Array(int *a,int n) {
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
