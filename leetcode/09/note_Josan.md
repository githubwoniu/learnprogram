## 链接


https://leetcode.com/problems/palindrome-number/


## 题目


判断一个32位整型是否是回文数。


## 补充描述

首先取出前后两个数字，然后比较这两个数字；之后，去掉这两个数字后，继续比较。这样可以防止出现溢出现象。




## 代码

1、自己的程序：
```C++
class Solution
{
    public:
    bool isPalindrome(int x)
    {
        if(x < 0)  return false;
        if(x == 0) return true;
        int digits = 0;
        int tem = x;
        digits = int(log10(x));
        tem = x;
        while((digits > 0) &&
              (tem % 10) == (tem / int(pow(10, digits))))
        {
            tem -= tem % 10 + (tem % 10)*int(pow(10, digits));
            tem /= 10;
            digits -= 2;
        }
        return (digits <= 0)?true:false;
    }
};
```

2、别人的程序
对自己程序的改进版

```C++
class Solution
{
    public:
    bool isPalindrome(int x)
    {
        if(x < 0) return false;
        int d = 1; // divisor
        while(x / d >= 10) d *= 10;
        while(x > 0)
        {
            int q = x / d; // quotient
            int r = x % 10; // remainder
            if(q != r) return false;
            x = x % d / 10;
            d /= 100;
        }
        return true;
    }
};
```

这题最好的解题方法，一个只需要遍历一半，就可以
```C++
class Solution
{
    public:
    bool isPalindrome(int x)
    {
//一个边界条件都不能少
        if(x < 0 || (x != 0 && x % 10 == 0)) return false;
        int sum = 0;
        while(x > sum)
        {
            sum = sum * 10 + x % 10;
            x = x / 10;
        }
        return (x == sum) || (x == sum / 10);
    }
};
```


## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
