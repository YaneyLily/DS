#include <iostream>
#include <vector>
using namespace std;
template <typename T>
void display(ostream & out,const vector<T> & aVector)//aVector是一个常引用形参，这样就不会被display函数所修改
{
    for(typename vector<T>::const_iterator it=aVector.begin();it!=aVector.end();it++)//it是一个常迭代器，也不能改变
    {
        out<<*it<<' ';
    }
    out<<endl<<endl;
}
int main() {
    vector<int> v(3);
    display(cout,v);

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    display(cout,v);
}
