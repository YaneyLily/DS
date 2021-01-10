//
// Created by Yaney on 2021/1/6.
//

#include "miniVector.h"
/*************************************************
Function:       // 调整数组容量
Input:          // n为要调整的容量大小，copy为是否将原来的值复制过来
Output:         // 一个新的容量为n的vector
*************************************************/
void miniVector::reserve(int n, bool copy)
{
    int *newArr;
    newArr = new int[n];//  申请一个内存空间为n的新的动态数组
    if(newArr== nullptr)//      判断内存是否申请成功
        throw range_error("miniVector reserve():memory allocation failure");
    if(copy)    //如果允许，将原来数组的值都复制到新的数组中。
        for(int i=0;i<vSize;i++)
            newArr[i]=vArr[i];
    if(vArr!= nullptr) delete []vArr;   //如果原来的数组不为空，则释放其内存空间
    vArr=newArr;    //将数组指针指向新的数组
    vCapacity=n;    //并将容量改为n
}

/*************************************************
Function:       // 构造函数，定义一个大小为size的vector，且默认条件下是一个大小和容量都为0，且数组指针指向null的空vector
Input:          // size是要定义的vector的大小
Output:         // 定义一个大小为size的vector
*************************************************/
miniVector::miniVector(int size) :vSize(0),vCapacity(0),vArr(nullptr)
{
    if(size==0) return;//如果大小为0，返回一个默认的空vector
    reserve(size, false);//给vector分配一个容量为size的内存空间
    vSize=size; //将vector的大小给设置好
    for (int i = 0; i < vSize; i++) //将vector的每一个元素初始化为0值
    {
        vArr[i]=0;
    }
}

/*************************************************
Function:       // 以对象为形参的构造函数，且默认条件下是一个大小和容量都为0，且数组指针指向null的空vector
Input:          // boj是那个作为形参的vector，且为只读模式
Output:         // 定义一个和obj一样的vector
*************************************************/
miniVector::miniVector(const miniVector & obj):vSize(0),vCapacity(0),vArr(nullptr)
{
    if (obj.vSize==0)   return; //如果boj的大小为0，则返回一个空vector
    reserve(obj.vSize, false);//给vector分配一个和obj的大小一样的内存空间。
    vSize=obj.vSize;    //将vector的大小设置为和obj一样
    for (int i = 0; i < vSize; i++) //将obj的元素值都复制到vector中
    {
        vArr[i]=obj.vArr[i];
    }
}

/*************************************************
Function:       // 析构函数，释放内存空间
Input:          // 空
Output:         // 释放内存空间
*************************************************/
miniVector::~miniVector()
{
    //如果vector不为空，则delete掉，释放内存
    delete []vArr;
}

/*************************************************
Function:       // 重载赋值运算符
Input:          // rhs是用于赋值的vector
Output:         // 返回一个已经赋好值的vector
*************************************************/
miniVector &miniVector::operator=(const miniVector &rhs) {
    if (rhs.vSize>vSize)//如果rhs的大小大了，则不能进行赋值操作（小于vector的可以用于赋值）异常退出。
    {
        cerr<<" size is not match,too long~";
        exit(1);
    }
    for (int i = 0; i < rhs.vSize; i++)//将rhs的元素都赋值到vector中去
    {
        vArr[i]=rhs.vArr[i];
    }
    vSize=rhs.vSize;//将rhs的大小也复制给vector
    //return vArr;
    //return miniVector(vSize);
}

/*************************************************
Function:       // 返回数组最后一个元素的值
Input:          // 无
Output:         // 返回数组最后一个元素的值
*************************************************/
int & miniVector::back()
{
    if (vSize==0)//如果vector的大小为空，抛出错误信息并结束
        throw underflow_error("miniVector back():vector empty");
    return vArr[vSize-1];//返回vector的最后一个元素（注意，vector的下标是从0开始的）
}

/*************************************************
Function:       // 返回数组最后一个元素的值，且为只读模式
Input:          // 无
Output:         // 返回数组最后一个元素的值，且为只读模式
*************************************************/
const int &miniVector::back() const {
    if (vSize==0)//如果vector的大小为空，抛出错误信息并结束
        throw underflow_error("miniVector back():vector empty");
    return vArr[vSize-1];//返回vector的最后一个元素（注意，vector的下标是从0开始的）
}

/*************************************************
Function:       // 重载下标运算符
Input:          // 用访问的第i个元素（从0开始）
Output:         // 返回第i个元素
*************************************************/
int & miniVector::operator[](int i)
{
    if (i<0||i>=vSize)//如果i不在：0<=i<vSize的范围内抛出错误信息
        throw  out_of_range("miniVector:index range error");
    return vArr[i];//返回该元素
}

/*************************************************
Function:       // 重载下标运算符,且为只读模式
Input:          // 用访问的第i个元素（从0开始）
Output:         // 返回第i个元素
*************************************************/
const int &miniVector::operator[](int i) const {
    if (i<0||i>=vSize)//如果i不在：0<=i<vSize的范围内抛出错误信息、i、vector的大小
        throw out_of_range("miniVector:index range error");
    return vArr[i];//返回该元素
}

/*************************************************
Function:       // 从数组尾部压入一个值为item的元素，且push_back不能改变item的值
Input:          // 要压入的item的值
Output:         // 无
*************************************************/
void miniVector::push_back(const int &item)
{
    if (vSize==vCapacity)//如果vector的大小等于容量有两种情况
    {
        if (vCapacity==0)   reserve(1, false);//第一种情况是，vector为空，则单单将vector的容量加1
        else    reserve(2*vCapacity,true);//第二种情况是，vector已满，则将vector的容量扩充到原来的两倍，并将之前的值拷贝一份过去
    }
    vArr[vSize]=item;//在vector的尾部压入元素
    vSize++;//vector的大小加一
}

/*************************************************
Function:       // 删除数组最后一个元素
Input:          // 无
Output:         // 无
*************************************************/
void miniVector::pop_back()
{
    if (vSize==0)//如果向量为空抛出错误信息
        throw underflow_error("miniVector pop_back():vector is empty");
    vSize--;//只要将vector的大小减1即可
}

/*************************************************
Function:       // 返回数组元素大小，且为只读
Input:          // 无
Output:         // 无
*************************************************/
int miniVector::size() const {
    return vSize;
}

/*************************************************
Function:       //判空，且为只读
Input:          // 无
Output:         // 无
*************************************************/
bool miniVector::empty() const
{
    return vSize==0;
}

/*************************************************
Function:       // 返回数组容量，且为只读
Input:          // 无
Output:         // 无
*************************************************/
int miniVector::capacity() const {
    return vCapacity;
}

/*************************************************
Function:       // 输出vector的元素，且为只读模式.
Input:          // 定义了<<操作符，ostream 已经被打开
Output:         // 输出vector的元素
*************************************************/
void miniVector::display(ostream & out) const {
    for (int i = 0; i < vSize; ++i) {
        out<<vArr[i]<<' ';
    }
    out<<endl<<endl;
}

/*************************************************
Function:       // 在第pos个位置处插入item
Input:          // pos为位置，item为要插入的函数
Output:         // 无
*************************************************/
void miniVector::insert(int pos, int item) {
    if (vSize==vCapacity)//如果vector的大小等于容量有两种情况
    {
        if (vCapacity==0)   reserve(1, false);//第一种情况是，vector为空，则单单将vector的容量加1
        else    reserve(2*vCapacity,true);//第二种情况是，vector已满，则将vector的容量扩充到原来的两倍，并将之前的值拷贝一份过去
    }
    if (pos<0||pos>vSize)
    {
        throw out_of_range("miniVector:index range error");
    }
    for(int j=vSize-1;j>=pos;j--){
        vArr[j+1]=vArr[j];

    }
    vArr[pos] = item;
    vSize++;
}

/*************************************************
Function:       // 删除值为value的元素
Input:          // value为要删除的元素的值，Delete不能改变
Output:         // 无
*************************************************/
void miniVector::Delete(const int value)
{
    bool exit= false;
    for (int i = 0; i < vSize; ++i)
    {
        if(vArr[i]==value)
        {
            exit=true;
            int pos=i;
            for (int j = pos; j < vSize; j++)  vArr[j]=vArr[j+1];
            vSize--;
        }
    }
    if (!exit) cerr<<"No Exit!!\n";
}
