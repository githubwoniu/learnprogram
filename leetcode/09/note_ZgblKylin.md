## 链接

https://leetcode.com/problems/palindrome-number/

## 题目

## 释义

## 补充描述

原本以为是需要全程in_place计算，不能分配除了循环变量之外的临时对象，所以只想到了用位运算，但那个太烧脑子了。
然后试着写了个比较粗暴的解法，发现是可行的，原来只要不玩string这种太过丧病的就行……



代码优化过几次版本，初始版本是这样的：

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        long int pal = 0;
        int origin = x;
        
        while(x) {
            pal *= 10;
            pal += x % 10;
            x /= 10;
        };
        
        return pal == origin;
    }
};
```

注意这里pal用了long int，因为int逆转后有可能越界。

#### 版本二

提交报错——负数是不允许回文的，于是增加了开头这段代码

```c++
if(x < 0)
    return false;
```

运行通过了，效率打败了54%对手。

#### 版本三

据说个算法平台的主流编译方式是不开优化，那么多一行少一行代码对性能的提升会很明显，所以尝试着做点性能优化——虽然在实际工作中没啥卵用就是了。

把x /= 10提到while()内部，while语句后置，写成这样的

```c++
do {
    pal *= 10;
    pal += x % 10
} while(x /= 10);
```

这版效率打败了好像78%对手。

#### 版本四

把while循环体内两句合并，效率提升到89%，基本到极限了，也就是我最后的那个代码。

#### 版本五（雾

总觉得long int占的空间比int长会不会影响效率，作死把pal改成unsigned int，效率瞬间跌到40%……好吧符号数之间的转换果然更吃资源。

## 代码

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
            
        long int pal = 0;
        int origin = x;
        
        do {
            pal = pal * 10 + x % 10;
        } while (x /= 10);
        
        return pal == origin;
    }
};
```

## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
