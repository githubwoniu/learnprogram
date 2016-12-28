## 链接


https://leetcode.com/problems/string-to-integer-atoi/


## 题目

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

```C++
class Solution {
public:
    int myAtoi(string str) {
        
    }
};
```

## 释义

将对应的String转换成相应的整数形式

## 补充描述

string format: [whitespace] [sign] [0] [x] [digits/letters]
凡是不符合这个格式的string都是非法的

## 代码

很简单，就是依次转存。但是，我测试不通过了4次，只考虑string为空的情况，其他情况都没有考虑。可见，对于程序的健壮性这点，以及程序测试这块，我的水平很差，需要继续不断注意训练。


```c++


class Solution
{
    public:
    int myAtoi(string str)
    {
        long long res = 0;
        if(0 == str.size())
        {
            return res;
        }
        auto i = str.begin();
        //remove the whitespace 
        while(i != str.end() && isspace(*i))
        {
            ++i;
        }
        if(i == str.end())
        {
            return res;
        }
        bool flag = true;
        int sign = 1;
        for(; i != str.end(); ++i)
        {
            if(flag&&*i == '-')
            {
                sign = -1;
                flag = false;
                continue;
            }
            else if(flag&&*i == '+')
            {
                flag = false;
                continue;
            }
            if(*i >= '0'&&*i <= '9')
            {
                res = res * 10 + (*i - '0');
            }
            else
            {
                break;
            }
            if(res > INT_MAX)
            {
                break;
            }
        }
        res = sign*res;
        if(res > INT_MAX)
        {
            res = INT_MAX;
        }
        else if(res < INT_MIN)
        {
            res = INT_MIN;
        }
        return static_cast<int>(res);
    }
};



```


再分享一个比较接近官方文件的代码，官方文件采用一个trick,就是pre-check技术，下面这个代码就是用了这个技术。
```C++
int myAtoi(string str)
{
    int ret = 0, sign = 1, i = str.find_first_not_of(' '), base = INT_MAX / 10;
    if(str[i] == '+' || str[i] == '-') sign = str[i++] == '+' ?: -1;
    while(isdigit(str[i]))
    {
        if(ret > base || (ret == base && str[i] - '0' > INT_MAX % 10))          return sign > 0 ? INT_MAX : INT_MIN;
        ret = 10 * ret + (str[i++] - '0');
    }
    return sign * ret;
}

```
## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
