#include <iostream>
#include "miniVector.h"
using namespace std;
int main() {
    miniVector v(3);
    cout<<"定了一个大小为3的vector:"<<endl;
    v.display(cout);

    for (int i = 1; i < 11; i++) {
        v.push_back(i);
    }
    cout<<"给v push_back 1~10过后："<<endl;
    v.display(cout);

    miniVector v2(v);
    cout<<"使用v作为形参的v2 ："<<endl;
    v2.display(cout);

    v2.pop_back();
    cout<<"使用pop_back()后的v2:"<<endl;
    v2.display(cout);

    v2.insert(5,100);
    cout<<"在v2第5个位置insert 100："<<endl;
    v2.display(cout);

    v2.Delete(100);
    cout<<"在v2中delete值为100的元素："<<endl;
    v2.display(cout);


    cout<<"v2的大小："<<endl;
    cout<<v2.size()<<endl;

    cout<<"v2的容量："<<endl;
    cout<<v2.capacity()<<endl;

    cout<<"v2是否为空："<<endl;
    cout<<boolalpha<<v2.empty()<<endl;

    cout<<"v2最后一个元素："<<endl;
    cout<<v2.back()<<endl;

    v[15]=v2[3];

    return 0;
}
