## 链接

【中等难度】5. Longest Palindromic Substring （最长回文子串）

https://leetcode.com/problems/longest-palindromic-substring/


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
Input: "cbbd"

Output: "bb"
```



## 释义






## 补充描述






## 代码






```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int sLen = s.length(), maxLen = 0, maxStart = 0;
        int pi = 0, pl = 0, pr = 0, subLen = 0;
        while (pi <= sLen - maxLen / 2){
            pl = pr = pi;
            while (pr < sLen - 1 && s[pr + 1] == s[pr])
                pr++;
            pi = pr + 1;
            while (pl > 0 && pr < sLen - 1 && s[pr + 1] == s[pl - 1]){
                pl--;
                pr++;
            }
            subLen = pr - pl + 1;
            if (maxLen < subLen){
                maxLen = subLen;
                maxStart = pl;
            }
        }
        return s.substr(maxStart, maxLen);
    }
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
