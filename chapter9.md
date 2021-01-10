[TOC]

# 🌟9.2 函数通用性——重载和模板

## ✨9.2.1 重载

- 只要两个函数的定义**不完全相同的特性**（函数的特性就是形参列表），**函数名就可以被重载**
- 重载函数被调用时，编译器通过比较实参的类型和函数集合中函数的特性来决定使用重载函数集合中的哪一个具体函数。若没有，则返回一个错误信息结束调用。

## ✨9.2.2 函数模板

- 模板是通过**声明类型形参**并在函数原型和定义中**使用这些形参**来代替特定的类型而工作的。

```c++
/*************************************************
Function:       // 一种用于交换类型都为DataType的任意两个对象的swap模板，在这种类型上已经定义了赋值运算符
Output:         // first和second的值被交换
*************************************************/
template <typename DataType>//类型形参,可以将DataType看作要被交换的值的类型的"占位符"
void swap(DataType & first,DataType & second)
{
    DataType temp=first;
    first=second;
    second=temp;
}
```

- `template <typename DataType>`要告诉编译器两件事情：
  - 这是一个函数模板：一个有次可以创建函数的模式。
  - 标志符DataType是这个函数模板的一个类型形参的名字，当函数被调用时，将被指定给一个值。
- 需要注意的是，使用类型形参DataType代替了某个特定的类型，定义的剩余部分则简单的规定了程序的行为。在函数模板的内部和外部，它没有做任何事情。只是简单的存储了这个模板，没有产生机器指令。需要时才会产生实际的函数定义。
- 

## ✨9.2.3 另一个例子：显示一个数组

# 🌟9.4 vector容器

1. vector容器是一个**内容可扩展**并且具有**大量内建操作**的数组类模板，强大且有用。
2. vector类模版的声明（简化形式）：

```C++
template <typename T>
class vector
{
  public:
  //===== 大量函数成员
  private:
  //===== 数据成员，其中一个是动态数组
  T * myArray；//T是容器要存储的值的类型所对应的形参
}
```

3. vector类模版是在标准的<vector>库中声明的，因此要使用，必须包含`#include <vector>`,允许如下声明：

- `vector <double> vec1;`
- `vector <string> vec2;`
  -  编译器将创建类vector的一个实例，并用double来替换每个T
  - 然后使用这个类来创建一个对象vec1，其元素为double型的

------



## ✨9.4.1 定义vector容器

```c++
//ElementType是任意数据类型，initCap是整型表达式，initVal的类型为ElementType，firstPtr和lastPtr是指向ElementType类型对象的指针
vector <element_type> objectName;//创建一个空vector
vector <ElementType> objectName(initCap);//创建一个容量为initCap的vector，其元素由ElementType的默认构造函数初始化
vector <ElementType> objectName(initCap,initVal);//与上一个构造函数类似，但是讲每个元素都初始化为initVal
vector <ElementType> objectName(firstPtr,lasPtr);//创建一个vectr，其内容由从firstPtr开始到lastPtr结束（但不包括lastPtr）的内存空间初始化
```

**定义1**

这表示初始化时容量为0，但其容量后续还可以增长的。

```c++
vector<double> dubVector(n);//创建了一个空的vector<double>对象dubVector
```



**定义2**

这表示初始化时容量为n，初始化元素为0（double型）

```C++
int n;
cin>>n;
vector<double> dubVector;
```



**定义3**

这表示初始化时容量为n，初始化元素为dubValue（double型）

```c++
int n;
double dubValue;
cin>>n>>dubValue;
vector(double) dubVector(n,dubVector);
```



**定义4**

这表示对象使用从地址first_ptr到last_ptr结束在内的内存单元的内容初始化（不包括last_ptr）

```c++
double a[]={1.1, 2.2, 3.3, 4.4};
vector<double> dubVector(a,a+4);//完成了a[0],a[1],a[2],a[3]的拷贝
```

------



## ✨9.4.2 一些vector操作

```c++
//v、v1、v2是某种类型T的vector；value的类型为T，i和n是非负整数
v.capacity();//返回v当前所具有的存储单元的数量
v.size();//返回当前存储在v中的值的个数
v.max_size();//返回v所能具有的存储单元的最大个数
v.empty();//当且仅当v中不包含值时返回true（如v的大小时0）
v.reserve(n);//增大v使得其容量为n（不影响v的大小）
    
v.push_back(value);//添加value到v的尾部
v.pop_back();//删除v的最后一个元素
    
v.front();//返回指向v的第一个元素的引用
v.back();//返回指向v的最后一个元素的引用
    
v[1];//返回v中下标为i的元素——没有对下标是否越界进行检查
v.at(i);//返回v中下标为i的元素——执行对下标是否越界检查——如果下标越界的话掏出越界异常
    
v1=v2;//将v2的拷贝赋予v1
v1.swap(v2);//交换v1和v2的内容
   
v1==v2;//当且仅当v1具有和v2一样的值，同时值的顺序也一样，才返回true。
v1<v2;//当且仅当v1在字典顺序上小于v2时返回true

```

- 与C风格数组相比，vector是自我包含的对象，可以提供关于自身的信息：和C一样，vector中第一个值的下标总是0，但是不同的是，C没有提供确认其最后一个值的方法，而第一个vector对象v的最后一个值的下标总是`v.size()-1` 。
- `v.empty()`是比`v.size()==0`更加简单的方法。
- `v.push_back(value)`:如果有必要的话，V的容量会增加以适应新的值。如后面将要解释的，增加的容量取决于目前的容量。
- `v.pop_back()`销毁v的最后一个值（如果这个值是一个对象的话，还将调用它的析构函数），但是容量不变。
- 尽量使用`v.push_back(value)`和`v.pop_back()`,因为这两种办法不仅可以改变元素值还可以更新vector的大小，并且在需要时可以触发vector容量的增长。如果使用下标运算符则不会改变vector的size和capacity（在容量满时）。也就是说这些方法也可以正确地更新end()返回的迭代器，但是下标运算符做不到，如果使用下标将值添加到一个vector中，那么STL算法将不能正确工作。
- `v.front()`和`v.back()`访问v的第一个和最后一个值，且返回的是引用而不是拷贝，即可以通过`v.front()`和`v.back()`改变v的首尾元素值。
- 下标运算符的使用的方式和数组以及string对象很相似。
- 没有检查是否越界的功能，可以使用`at()`方法，他可以抛出`out_of_range`异常，再配合try-catch语句，完美～

```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector<double> v;
    cout<<v.capacity()<<' '<<v.size()<<' '<<v.max_size()<<endl;

    vector<double> v1(3);
    cout<<v1.capacity()<<' '<<v1.size()<<endl;

    vector<double> v2(3,4.0);
    cout<<v2.capacity()<<' '<<v2.size()<<' '<<endl;
    v2.reserve(6);
    cout<<v2.capacity()<<' '<<v2.size()<<endl;

}
```

![image-20210105163642895](/Users/yaney/Library/Application Support/typora-user-images/image-20210105163642895.png)

```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<double> v;
    v.push_back(1.1);
    v.push_back(2.2);
    v.push_back(3.3);
    cout<<v.front()<<' '<<v.back()<<endl;
    v.pop_back();
    cout<<v.front()<<' '<<v.back()<<endl;
    v.front()=4.4;
    v.back()=5.5;
    cout<<v.front()<<' '<<v.back()<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<' ';
    }
    cout<<endl;
    try
    {
        for(int i=0;i<10;i++)
        {
            cout<<"v.at("<<i<<")="<<v.at(i)<<endl;
        }
    }
    catch (out_of_range ex)
    {
        cerr<<"Index out of range\n";
    }
}
```

![image-20210105192848792](/Users/yaney/Library/Application Support/typora-user-images/image-20210105192848792.png)

```c++
/*************************************************
Function:       // 从一个istream读取值到一个vector中
Input:          // T是一个类型形参T，已经为类型T定义了<<操作符；instream in 已经被打开
Output:         // 值被从in中提取出来并添加到aVector中
*************************************************/
template <typename T>
void read(istream & in,vector<T> & aVector)
{
    T inputValue;
    for(;;)
    {
        in>>inputValue;
        if(in.eof())break;
        aVector.push_back(inputValue);
    }
}
/*************************************************
Function:       // 将储存在vector中到值输出到一个ostream中
Input:          // T是一个类型形参T，已经为类型T定义了<<操作符，ostream out 已经被打开
Output:         // 储存在vector中到值被输出到out中
*************************************************/
template <typename T>
void Print(ostream & out,const vector<T> & aVector)
{
    for(int i=0;i<aVector.size();i++)
        out<<aVector[i]<<' ';
}
```

### 1. 赋值和交换

- 赋值操作符（=）：`v1=v1`：先销毁任何先赋给v1的值，然后将v1改变为v2的拷贝
- 交换两个变量的值：`swap（v1,v2）`

```c++
vector<T> temp=v1;
v1=v2;
v2=temp;
```

### 2. 关系运算符

- 相等运算符（==）：size相等，value相同
- 小于运算符（<）：逐个元素的比较直到发生了一个失配，如果左边的失配元素小于右边的，返回true，否则返回false。

------



## ✨9.4.3 内部实现一瞥——增加容量

当vector变满时，即`v.size()=v.capacity()`，通过`push_back()`或`insert()`添加一个新对象时，vector会自动的增加以适应新的元素。

1. **分配一个新数组来存储vector的元素。**
   - 当我们需要更多的空间的时候，capacity就会两倍的增加，这是一种要分配较大还是较小的内存块的一种折中。
   - 还能使得我们可以通过定义**具有预分配容量**的vector对象或是通过使用`reserve()`来**控制容量以什么量来增长**。

```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<double> v;
  cout<<v.capacity()<<' '<<v.size()<<endl;
  for(int i=0;i<20;i++)
  {
      v.push_back(i+0.5);
      cout<<v.capacity()<<' '<<v.size()<<endl;
  }
  return 0;
}
```

![image-20210106102004278](/Users/yaney/Library/Application Support/typora-user-images/image-20210106102004278.png)

将`vector<double> v;`改为`vector<double> v(3,0);`时，运行结果如下：

![image-20210106102234884](/Users/yaney/Library/Application Support/typora-user-images/image-20210106102234884.png)

2. **将所有现有的元素（使用T的复制构造函数）复制到新数组中。**
   - 如果插入点不在尾部，则将插入点之前的元素（不包括插入点）复制到新的存储空间。
   - 接着复制所有从插入点到vector尾部的元素
   - 最后在新的vector中空出一个元素，给新的对象留下了位置。

3. **将要添加的项存储到新数组中。**
   
- 使用T的肤质构造函数将要添加的项存储到新分配的块的尾部。
   
4. **销毁vector<T>中的旧数组。**

   使用T的析构函数销毁存储在旧数组中的元素，并释放内存。

5. **使新数组成为vector<T>的存储数组。**
   
   - 更新v的数据乘员，使得新数组成为用来存储v的元素的数组数据乘员。

------



## 9.4.4 对迭代器的第一次探讨

### 1. 为什么要使用迭代器?

- 尽管下标运算符可以用来访问一个vector元素，但是这不是一种通用的访问容器中元素的方法（比如不能用来访问一个list），如果要使一个STL算法能够在任何STL容器上工作，需要一些访问一个容器中元素的真正通用的方法。

- STL提供了被称为迭代器的对象，可以指向容器中的一个元素并访问他的值，以及从一个元素移动到另一个元素。

### 2. 迭代器是什么？

- 迭代器是指针的一种通用实行，可以使C++程序以一种统一的形式工作在不同的数据结构（容器）上。

### 3.迭代器怎么用？

- 每个STL容器都提供了一个iterator类型以及最少两个返回迭代器的方法。
  - `begin()`:返回指向容器中第一个元素的迭代器。
  - `end()`:返回指向容器中最后一个元素的迭代器。

```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> v;
  v.push_back(9);
  v.push_back(8);
  v.push_back(7);
  vector<int>::iterator vecIter1=v.begin();
  vector<int>::iterator vecIter2=v.end();
  cout<<*vecIter1<<' '<<*vecIter2<<endl;
    return 0;
}
```

![image-20210106105940267](/Users/yaney/Library/Application Support/typora-user-images/image-20210106105940267.png)

- 对于通用迭代器：

  | 运算符            | 描述                                     |
  | ----------------- | ---------------------------------------- |
  | 自增运算符（++）  | 当前位置移动到下一个位置，可前缀也可后缀 |
  | 自减运算符（--）  | 当前位置移动到前一个位置，可前缀可后后缀 |
  | 去引用运算符（*） | 访问迭代器所指向的位置的值，只可前缀     |

- 对于随机访问迭代器（如vector）：

  | 运算符                                     | 描述                                                         |
  | ------------------------------------------ | ------------------------------------------------------------ |
  | 赋值（=）                                  | 对于同类型的迭代器，`it1=it2`:将it1的位置设置为it2的位置一样 |
  | 相等比较（==和!=）                         | 对于同类型的迭代器，`it1==it2`为true：it1和it2指向同一个元素 |
  | 加（+）减（-）以及相应的复合赋值（+=，-=） | `it+n`:返回一个指向it的当前位置之后第n个元素的迭代器（n为整数，可以为负） |
  | 下标运算符（[ ]）                          | `it[n]`:返回一个指向it的当前位置之后第n个元素的**引用**（n为整数，可以为负） |

```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<double> v;
    for(int i=2;i<=5;i++)
    {
        v.push_back(2.2*i);
    }
    vector<double>::iterator it,it1,it2;
    for (it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<"<--- original vector\n";

    it1=v.begin(),it2=v.end();
    *it1=1.1;
    *(it2-1)=9.9;
    for (it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<"<---modify first & last via iterators\n";

    it1+=3;
    it2-=3;
    cout<<*it1<<' '<<*it2<<"<---jump\n";

    it1--;
    ++it2;
    cout<<*it1<<' '<<*it2<<' '<<"<--- inc & dec\n";
    cout<<it1[1]<<' '<<it1[-1]<<"<---subscript\n";
    return 0;
}
```

![image-20210106121916105](/Users/yaney/Library/Application Support/typora-user-images/image-20210106121916105.png)

![image-20210106122058237](/Users/yaney/Library/Application Support/typora-user-images/image-20210106122058237.png)

### 4. 使用迭代器进行dispaly

- 使用`const_iterator`对**aVector**进行display。

```c++
/*************************************************
Function:       // 输出存储在一个vector中的值到一个ostream，使用一个常迭代器在vector中移动
Input:          // T是一个类型形参T，已经为类型T定义了<<操作符，ostream 已经被打开
Output:         // 储存在aVector中到值被输出到out中
*************************************************/
template <typename T>
void display(ostream & out,const vector<T> & aVector)//aVector是一个常引用形参，这样就不会被display函数所修改
{
    for(typename vector<T>::const_iterator it=aVector.begin();it!=aVector.end();it++)//it是一个常迭代器，也不能改变
    {
        out<<*it<<' ';
    }
}
```

- 通用的可以对**STL容器**中的值进行display

```c++
/*************************************************
Function:       // 输出存储在一个容器cont中的值到一个ostream，使用一个常迭代器在cont中移动
Input:          // Container是一个类型形参，它提供了一个常迭代器，已经为类型Container定义了<<操作符，ostream 已经被打开
Output:         // 储存在cont中到值被输出到out中
*************************************************/
template <typename Container>
void display(ostream & out,const Container &cont)
{
    for(typename Container::const_iterator it=cont.begin();it!=cont.end();it++)
    {
        out<<*it<<' ';
    }
}
```

------



## ✨9.4.5 一些牵涉到迭代器的vector函数成员

```c++
//v是一个给定类型T的vector，value是T类型的，b是一个整数，iter，iter1和iter2是迭代器
v.begin();//返回指向v的第一个元素的第一个迭代器
v.end();//返回指向v的最后一个元素之后的第一个迭代器
    
v.rbegin();//返回指向v的最后一个元素的一个逆迭代器
v.rend();//返回指向v的第一个元素之前的一个逆迭代器
    
v.insert(iter,value);//将value插入v中iter制定的位置
v.insert(iter,n,value);//将value的n个拷贝插入到v中由iter给定的位置
    
v.erase(iter);//删除v中由iter给定的位置处的值
v.erase(iter1,iter2)//删除v中从iter1～iter2处的值
```

- 最后两组说明了vector和数组一样可以在任何位置中删除或插入数据，但是和数组一样在插入新元素时需要移动元素来腾出位置，在删除元素时需要消除间隙（注意`v.end()`和`v.size()`的值都会改变）。
- 使用逆迭代器进行dispaly

```c++
/*************************************************
Function:       // 输出存储在一个vector中的值到一个ostream，使用一个常迭代器在vector中移动
Input:          // T是一个类型形参T，已经为类型T定义了<<操作符，ostream 已经被打开
Output:         // 储存在aVector中到值被输出到out中
*************************************************/
template <typename T>
void display(ostream & out,const vector<T> & aVector)//aVector是一个常引用形参，这样就不会被display函数所修改
{
    for(typename vector<T>::reverse_iterator it=aVector.rbegin();it!=aVector.rend();it++)//it是一个常迭代器，也不能改变
    {
        out<<*it<<' ';
    }
}
```

------



## ✨9.4.6 综合比较：vector VS 数组

| vector                                     | 数组                        |
| ------------------------------------------ | --------------------------- |
| 容量可以增长                               | ❌                           |
| 自我包含的参数                             | ❌（需要更多参数）           |
| 类模版，编译器可以将其生成所需要的任何实例 | ❌（需要绑定某个给定的类型） |
| 函数成员提供了很多常用的函数的实现         | ❌（需要自己动手编写）       |

- 使用数组和vector：需要直接访问元素，并且插入和删除都不频繁或限制在列表的尾部
- 使用链表：处理期间大小会变化很大，在不定位置平凡插入或删除，顺序访问已经足够用。

------

## ✍️~~测试~~

## ✍️~~练习~~

# 📖~~9.5 案例学习：计算机系统登陆统计~~

# 