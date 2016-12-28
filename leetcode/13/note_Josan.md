## 链接

https://leetcode.com/problems/roman-to-integer/

## 题目

将罗马数字转换为整形，输入范围是1-3999

## 释义

1-3999的罗马数，用到的符号和对应的十进制数如下：

I → 1

V → 5

X → 10

L → 50

C → 100

D → 500

M → 1000



## 补充描述




## 代码

利用hash进行快速读取，然后从头到尾因此遍历，如果第一次遍历的数，比接下来遍历的数小，则减掉第一次遍历的数值，否则加上。对于最后一位，则是直接加上相应的数值。

```c++
class Solution
{
    public:
    int romanToInt(string s)
    {
        map<char, int> rmaMap = {
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 }
        };
        int res = 0;
        for(string::size_type i = 0; i != s.size(); ++i)
        {
            auto j = i + 1;
            int val = rmaMap[s[i]];
            if(j != s.size() && val < rmaMap[s[j]])
            {
                res -= val;
            }
            else
            {
                res += val;
            }
        }
        return res;
    }
};

```


## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
