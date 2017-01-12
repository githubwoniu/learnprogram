## 链接


https://leetcode.com/problems/reverse-integer/


## 题目

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

```c++
class Solution {
public:
    int reverse(int x) {
        
    }
};
```

## 释义

翻转一个整数，如果是123，结果就是321；如果输入是-123，结果就是-321。

## 补充描述

主要的注意项就是12345 67899，翻转之后就是99876 54321；会发生溢出的情况。


## 代码






```c++

class Solution {
public:
   int reverse(int x) {
    long long r = 0;
    while (x) r = r*10 + x%10, x /= 10;
    return (int(r) == r) * r;
}
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
