[TOC]

# 2.1 对ADT及其实现的第一瞥

1. ADT=数据元素集合+基本操作
2. ADT的实现=存储结构+算法
3. ADT的思想=定义+实现

# 2.2 C++的简单数据类型

1. 二进制<字节<字
2. int、float、double、char、bool
   1. 简单数据类型——原子性
   2. 抽象数据类型——值（存储单元作为存储结构）+值上面的操作（计算机的硬件或软件实现的）

## 2.2.1 整型数据

1. 无符号整数（也叫做基数或全数——ADT=非负整数+加减乘除判断大小等操作）
   1.  unsigned short (int)
   2. unsigned (int)
   3. unsigned long (int)

### code2-0.cpp

```c++
//
// Created by Yaney on 2021/1/4.
//--Program to get size of int
//
#include <iostream>
using namespace std;
int main()
{
    int len1=sizeof (unsigned short);
    int len2=sizeof (unsigned);
    int len3=sizeof (unsigned long);
    cout<<len1<<endl<<len2<<endl<<len3<<endl;
    return 0;
}
```

![image-20210104204120390](/Users/yaney/Library/Application Support/typora-user-images/image-20210104204120390.png)

2. 带符号整数
   1. short (int)
   2. int
   3. long (int)
   4. 补码存储（可用于相加减）
      1. 符号位：0位正，1位负
      2. 数值位：正数不变，负数数值位取反加1

3. 溢出

- 溢出过后的值虽然看起来像是随机的垃圾值，但是也是由一种很有机理的方式生成的。

### code2-1.cpp

```c++
//-- Program to demonstrate the effects of overflow 
#include <iostream>  
using namespace std; 
 
int main() 
{ 
   int number = 2; 
 
   for (int i = 1; i <= 15; i++) 
   { 
      cout << number << endl; 
      number *= 10; 
   } 
 }
```

![image-20210104205256717](/Users/yaney/Library/Application Support/typora-user-images/image-20210104205256717.png)

- 当一个整数的范围[INT_MIN,INT_MAX]达到某个断点时，他会简单的从另一个端点再次开始，就会出现一种环绕行为。
  - number=2147483647（2^31-1,是32位操作系统中最大的符号型整型常量）的二进制补码是**0**111 1111 1111 1111 1111 1111 1111 1111
  - 执行number++后，number的补码为**1**000 0000 0000 0000 0000 0000 0000 0000，此时number=-2147483648。因为1此时被视作符号位，此时为负（即进位丢失了1），其数值位要取反加一位为：1000 0000 0000 0000 0000 0000 0000 0000（2147483648）。
  - 以此类推就会形成一个环绕效果，这也是为什么现实中的操作不一定能够完全按照相应的ADT的操作一样的方式执行的原因。

### code2-2.cpp

```c++
//-- Program to demonstrate the effects of overflow
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int number = INT_MAX - 3;

    for (int i = 1; i <= 7; i++)
    {
        cout << number << endl;
        number++;
    }
}
```

![image-20210104205600265](/Users/yaney/Library/Application Support/typora-user-images/image-20210104205600265.png)

## 2.2.2 实型数据

1. 

