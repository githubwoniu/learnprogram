## 链接


https://leetcode.com/problems/palindrome-number/


## 题目


判断一个32位整型是否是回文数。


## 释义

据题意，有如下方法：

1. 【C】全递归计算
2. 【C++】的设计模式

规定负数皆不是回文数，但零是回文数。

测试数据：

```c++
isPalindrome(-1)
isPalindrome(10)
isPalindrome(0)
isPalindrome(0x7fffffff)
isPalindrome(0x80000000)
isPalindrome(131)
isPalindrome(12321)
isPalindrome(1321)
```


## 补充描述


### 方法一：全递归形式

#### 顶层设计

```c
int power(int x, int n); // 求x的n次方
int getBit(int x, int n); // 得到x的第n位数字（从右往左，以1为开始）
int getFirstBit(int x, int n); // 得到x的第一个非零位（从右往左数，以1为开始）
isPalindrome(int x, int m, int n); // 判断x的第m位和第n位是否相同
isPalindrome(int x); // 解
```

#### 解释
太过简单，不解释了。

### 方法二：设计模式

这部分重点介绍。

#### 顶层设计

设计如下接口：

- IStream - 流，方法有检测非空、从流中取值、拷贝
- IComparator - 比较器，返回0（相等），负值（小于），正值（大于）

设计如下类：

- DefaultType - 类型默认值、判断、空值
- Stream - 流
- DecimalSteram - 十进制位数流
- ReverseStream - 反转流，将流的数据全部翻转，再逐个输出
- DecimalComparator - 十进制比较器，负责实现十进制比较
- Builder - 构造器，负责以链形式构造对象
- DecimalBuilder - 基于十进制位数的构造器，相关方法有输入流进栈、栈上复制流、栈顶流反转（流指十进制位数流，由于未实现BIgInteger，所以这里的类型都是int）

#### 相关知识

##### 模版

有了模版，就不用写多个仅类型不同的类了。模版节省了代码和时间。

库里的vector等都是模版类。

##### 模版特化

只要特化某些类型即可，没有特化的类型是编译不通过的。

这样可以根据类型定制相应的模版类。

比如检测一个结构是否是POD，可以用特化解决。

##### 流

流是java里很经典的概念。

流有通用的接口，如：

- 检测流可用（是否到末尾）
- 流中取值（相当于pop）
- 拷贝
- 装饰

其中需要介绍拷贝和装饰。

**拷贝流**，分两种情况：

- 正向拷贝
- 反向拷贝

其中，**正向拷贝**，说明原始流和拷贝的流方向相同，需要用装饰者模式（IStream接口）。

**反向拷贝**，原始流和拷贝的流方向相反，这时需要在构造函数中**一次性把流全部读取**，保存到类中，然后供外界使用。

结论：正向拷贝（惰性取值），反向拷贝（立即取值）。

**装饰流**，有两种方式：

- 将流接口保存在内部，嵌套调用，但这样会降低效率
- 在构造函数中将嵌套调用简化，或在读取流的所有内容时将嵌套调用简化，但如何简化，这比较复杂

一般采用第一种方式——嵌套。

##### 构造者

这也是java中的一种模式。

简单来说，就是每次方法调用后返回对象本身，构成链式调用。

### 总结

好久没写C++了，这次编译器报错N次，总共花了四小时，醉了。上一次认真写是写GUI（vczh的gaclib），见[https://github.com/bajdcc/CCGuiFoundation](https://github.com/bajdcc/CCGuiFoundation)，说其话，写GUI是最锻炼C++姿势水平的，（逃

## 代码






```c++
#include <iostream>
#include <vector>
#include <memory>

#define USE_C

template <class T>
struct DefaultType {
};

template <>
struct DefaultType<int> {
    static int getDefaultValue() {
        return 0;
    }

    static int getNullValue() {
        throw "NULL";
    }

    static int compare(const int& left, const int& right) {
        return left - right;
    }

    static int clone(const int& origin) {
        return origin;
    }
};

template <class T>
class IStream {
public:
    virtual bool isEmpty() const = 0;
    virtual T get() = 0;
    virtual IStream* clone() const = 0;
};

typedef IStream<int> IDecimalStream;

template <class T>
class Stream : public IStream<T> {
private:
    T obj;

public:
    Stream(T obj) {
        this->obj = obj;
    }

    virtual bool isEmpty() const = 0;
    virtual T get() = 0;
    virtual IStream<T>* clone() const = 0;
};

class DecimalStream : public Stream<int> {
private:
    int m_iNumber;

public:
    DecimalStream(int number): Stream(number) {
        m_iNumber = number;
    }

    bool isEmpty() const override {
        return m_iNumber == 0;
    }

    int get() override {
        if (isEmpty()) return -1;
        int value = m_iNumber % 10;
        m_iNumber /= 10;
        return value;
    }

    IStream* clone() const override {
        return new DecimalStream(m_iNumber);
    }
};

template <class T>
class ReverseStream : public IStream<T> {
private:
    std::vector<T> m_vec;

    ReverseStream(const std::vector<T>& vec): m_vec(vec) {
    }

public:
    ReverseStream(IStream<T> *stream) {
        std::unique_ptr<IStream<T>> s(stream->clone());
        while (!stream->isEmpty()) {
            m_vec.push_back(stream->get());
        }
    }

    bool isEmpty() const override {
        return m_vec.empty();
    }

    T get() override {
        if (isEmpty()) return DefaultType<T>::getNullValue();
        T result = *m_vec.rbegin();
        m_vec.pop_back();
        return result;
    }

    IStream<T>* clone() const override {
        return new ReverseStream(m_vec);
    }
};

typedef ReverseStream<int> DecimalReverseStream;

class IComparator {
public:
    virtual int compare() = 0;
};

template <class T>
class Comparator : public IComparator {
private:
    IStream<T> *m_stream1, *m_stream2;

public:
    Comparator(IStream<T> *s1, IStream<T> *s2): m_stream1(s1->clone()), m_stream2(s2->clone()) {
    }

    int compare() override {
        int result;
        for (;;) {
            result = compareEmpty();
            if (result != 2) {
                return result;
            } else if ((result = compareNonEmpty()) != 0) {
                return result;
            }
        }
    }

private:
    int compareEmpty() {
        static int BinaryCompareArray[] = { 2, 1, -1, 0 };
        bool a = m_stream1->isEmpty(),b=m_stream2->isEmpty();
        return BinaryCompareArray[(m_stream1->isEmpty() << 1) | (m_stream2->isEmpty())];
    }

    int compareNonEmpty() {
        return DefaultType<T>::compare(m_stream1->get(), m_stream2->get());
    }
};

typedef Comparator<int> DecimalComparator;

template <class T>
class Builder {
private:
    std::vector<std::unique_ptr<T>> m_vecPtrs;

public:
    Builder() {
    }

    Builder(const Builder&) = delete;

    Builder& push(T* obj) {
        m_vecPtrs.push_back(std::unique_ptr<T>(obj));
        return *this;
    }

    Builder& pop() {
        m_vecPtrs.pop_back();
        return *this;
    }

protected:
    T* top() {
        return (*m_vecPtrs.rbegin()).get();
    }

    bool isEmpty() {
        return m_vecPtrs.empty();
    }
};

class DecimalBuilder : public Builder<IDecimalStream> {
public:
    DecimalBuilder() {
    }

    DecimalBuilder(const DecimalBuilder&) = delete;

    DecimalBuilder& pushDecimal(int number) {
        push(new DecimalStream(number));
        return *this;
    }

    DecimalBuilder& dup() {
        if (isEmpty()) throw "EMPTY";
        push(top()->clone());
        return *this;
    }

    DecimalBuilder& reverse() {
        if (isEmpty()) throw "EMPTY";
        IDecimalStream *ptr = new DecimalReverseStream(top());
        pop();
        push(ptr);
        return *this;
    }

    bool equal() {
        if (isEmpty()) throw "EMPTY";
        std::unique_ptr<IDecimalStream> s1(top()->clone());
        pop();
        if (isEmpty()) throw "EMPTY";
        std::unique_ptr<IDecimalStream> s2(top()->clone());
        pop();
        DecimalComparator comp(s1.get(), s2.get());
        return comp.compare() == 0;
    }
};

class Solution {
public:
    static int power(int x, int n) {
        return n == 0 ? 1 : (x * power(x, n - 1));
    }

    static int getBit(int x, int n) {
        return (x / (power(10, n - 1))) % 10;
    }

    static int getFirstBit(int x, int n) {
        return getBit(x, n) == 0 ? getFirstBit(x, n - 1) : n;
    }

    static bool isPalindrome(int x, int m, int n) {
        return m >= n ? true : (getBit(x, m) == getBit(x, n) ? (isPalindrome(x, m + 1, n - 1)) : false);
    }

    bool isPalindrome(int x) {
#ifdef USE_C
        return x <= 0 ? (x == 0) : isPalindrome(x, 1, getFirstBit(x, 10));
#else
        DecimalBuilder builder;
        return builder.pushDecimal(x)
                .dup()
                .reverse()
                .equal();
#endif
    }
};

```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。