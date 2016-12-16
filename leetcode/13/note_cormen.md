## 链接


https://leetcode.com/problems/roman-to-integer/


## 题目
Roman to Integer




## 释义
最简单直观的方法，没什么需要解释的




## 补充描述

无




## 代码






```c++

//代码放在这个块里面，可以高亮关键字
class Solution {
public:
    int romanCharToInt(char ch)
    {
        int ival = 0;
        switch(ch)
        {
            case 'I':
                ival = 1;
                break;
            case 'V':
                ival = 5;
                break;
            case 'X':
                ival = 10;
                break;
            case 'L':
                ival = 50;
                break;
            case 'C':
                ival = 100;
                break;
            case 'D':
                ival = 500;
                break;
            case 'M':
                ival = 1000;
                break;
        }
        return ival;
    }

    int romanToInt(string s) {
        if(s.size() < 0) return 0;

        int result = romanCharToInt(s[0]);

        for(int i = 1; i < s.size(); ++i)
        {
            int prev = romanCharToInt(s[i-1]);
            int currv = romanCharToInt(s[i]);

            if(prev < currv)
                result = result - prev + (currv - prev);
            else
                result += currv;
        }

        return result;
    }
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
