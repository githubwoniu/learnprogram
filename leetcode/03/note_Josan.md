## 链接

【中等难度】3. Longest Substring Without Repeating Characters （最长不重复子串）

https://leetcode.com/problems/longest-substring-without-repeating-characters/


## 题目

Given a string **s**, find the longest palindromic substring in **s**. You may assume that the maximum length of **s** is 1000.

**Example:**

```
Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.

```

**Example:**

```
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

*Tags: Hash Table, Two Pointers*

## 释义

最长不重复子串


## 补充描述

运用动态规划进行求解。
dp[i]是指字符串从头到s[i]所找到的最长无重复子字符串长度。因此，答案dp[s.size()-1]就是所要的结果。期间用到了辅助数组标记访问位。
时间复杂度为O(n*n)。



## 代码

```C++
int flag[128] = { 0 };
int getMax(int x, int y)
{
    return x > y?x:y;
}
void init(int* flag, int num)
{
    for(int i = 0; i != num; ++i)
    {
        flag[i] = 0;
    }
}
class Solution
{
    public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.size() == 0) { return 0; }
        vector<int> dp(s.size(), 1);
        for(int i = 1; i != s.size(); ++i)
        {
            int j = i;
            int len = 0;
            //向前开始查找，找到以s[i]结尾的最长无重复子序列
            for(; (j >= 0) && (flag[s[j]] == 0); --j)
            {
                flag[s[j]] = 1;
                ++len;
            }
            dp[i] = getMax(dp[i - 1], len);
            init(flag, 128);
        }
        return dp[s.size() - 1];
    }
};
```


## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
