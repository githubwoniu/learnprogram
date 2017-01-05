## 链接

[https://leetcode.com/problems/longest-common-prefix/](https://leetcode.com/problems/longest-common-prefix/)

## 题目

题目是要求出一个string序列中，所有字符串共有的前缀。

比如 ["aa", "ab"], 那么结果就是"a"

## 释义

N.A.

## 补充描述



#自己的解题思路（纵向）

依次比较每个字符串的相同序号的字符，如果都相同，比较下一个；如果不同，跳出循环。


#别人的解题思路（横向）

每两个字符串找出最长的公共子串，然后得出最长的公共子串。


## 代码

1、自己的程序：
```C++
class Solution
{
    public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int n = strs.size();
        if(n == 0)  return{};
        string res;
        int min = INT_MAX;
        for(int i = 0; i != n; ++i)
        {
            min = int((strs.begin() + i)->size()) < min
                ?int((strs.begin() + i)->size()):min;
        }
        for(int i = 0; i < min; ++i)
        {
            int j = 1;
            for(; j < n; ++j)
            {
                if(strs[j - 1][i] != strs[j][i])
                {
                    break;
                }
            }
            if(j < n) { break; }
            else
            {
                res.push_back(strs[0][i]);
            }
        }
        return res;
    }
};
```

自己改进版，速度有所提升。去掉临时存储字符串的res，因为只需要最后一次取出就行。
```C++
class Solution
{
    public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int n = strs.size();
        if(n == 0)  return{};
        int min = INT_MAX;
        for(int i = 0; i != n; ++i)
        {
            min = int((strs.begin() + i)->size()) < min
                ?int((strs.begin() + i)->size()):min;
        }
        int i = 0;
        for(; i < min; ++i)
        {
            int j = 1;
            for(; j < n; ++j)
            {
                if(strs[j - 1][i] != strs[j][i])
                {
                    break;
                }
            }
            if(j < n) { break; }
        }
        return strs[0].substr(0, i);
    }
};
```

2、别人的程序

```C++
class Solution
{
    public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if(strs.empty()) return "";
        int right_most = strs[0].size() - 1;
        for(size_t i = 1; i < strs.size(); i++)
            for(int j = 0; j <= right_most; j++)
                if(strs[i][j] != strs[0][j])
                    right_most = j - 1;
        return strs[0].substr(0, right_most + 1);
    }
};
```





## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
