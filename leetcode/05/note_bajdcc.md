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

求给定串的最长回文子串

### 简单思路

从左往右找回文串，最后给个最长的。

简单方法不简单。。怎么找回文串是个问题，从边上往中间找肯定不行，回文串的特点是两边对称，所以应该从对称方面着手。

### 优化思路

首先，一个回文串的字符频度应该是：中点频度最低为1，其他字符频度最低为2。

那么，**如果串中有频度是1的字符，它肯定位于回文串的中心，不然就不属于任何回文串**。

因此，按频度可以筛选掉一定量的多余字符，将母串进行**分割**。分割的好处是**子串有界**。

最懒方法：遍历整串，从中心向两侧扩张并做比较，取得长度，最后返回最大长度所在的串。

优化：

- 在遍历整串过程中，最大长度maxlen会**时刻增加**，那么，当分割后的**有界子串**长度小于最大长度maxlen时，就不需要再去判断了。
- 如果串的某个连续子串(len>=2)它们的频度都是1，那么它们就**不属于任何回文串**，可以快速剔除，节省时间。这是关键。
- 其他方法还没想到，欢迎补充。

## 补充描述

debug两天，time=9ms https://leetcode.com/submissions/detail/87484290/

代码是为了验证思路是正确的。不得不吐槽leetcode的test case了，它对代码中的优化方法视而不见 :(


## 代码






```c++

//代码放在这个块里面，可以高亮关键字

#include <iostream>

using namespace std;

class Solution {
    int count[256];

public:
    string longestPalindrome(string str) {
        int start = 0, end = str.length() - 1;
        if (longestPalindromePartition(str.c_str(), start, end, 1) > 1) {
            return str.substr(start, end - start + 1);
        } else {
            return str.substr(0, end < start ? 0 : 1);
        }
    }

    int longestPalindromePartition(const char *str, int &start, int &end, int maxLen) {
        if (end - start + 1 <= maxLen)
            return 1;
        int maxStart, maxEnd, len = maxLen;
        int reserve = (maxLen + 1) / 2;
        int reserveEnd = end - reserve + 1;
        for (int i = start + reserve - 1, j, k; i <= reserveEnd; ++i) {
            if (str[i] == str[i + 1]) {
                for (j = i + 1, k = 1; i - k >= start && j + k <= end; ++k) {
                    if (str[i - k] != str[j + k])
                        break;
                }
                k--;
                if (j - i + 1 + k * 2 > len) {
                    len = j - i + 1 + k * 2;
                    reserve = (len + 1) / 2;
                    reserveEnd = end - reserve + 1;
                    maxStart = i - k;
                    maxEnd = j + k;
                }
            }
            for (j = reserve; j > 0; --j) {
                if (str[i - j] != str[i + j])
                    break;
            }
            if (j == 0) {
                for (j = reserve + 1; i - j >= start && i + j <= end; ++j) {
                    if (str[i - j] != str[i + j])
                        break;
                }
                reserve = --j;
                reserveEnd = end - reserve;
                if (j * 2 + 1 > len) {
                    len = j * 2 + 1;
                    maxStart = i - j;
                    maxEnd = i + j;
                }
            }
        }
        if (maxLen < len) {
            start = maxStart;
            end = maxEnd;
            return len;
        }
        return 1;
    }

    int longestPalindrome(const char *str, int &start, int &end) {
        if (start == end)
            return 1;
        for (int i = 0; i <= 26; ++i) {
            count['a' + i] = 0;
        }
        int len = end - start + 1;
        for (int i = start; i <= end; ++i) {
            count[str[i]]++;
        }
        auto dups = new int[len];
        int dupCount = 0;
        for (int i = start; i <= end; ++i) {
            dups[i] = count[str[i]] > 1 ? (dupCount++, 1) : 0;
            if (dups[i] == len)
                return len;
        }
        int tmpStart = -1, tmpEnd = -1, maxStart = -1, maxEnd = -1, tmpLen, maxLen = 1;
        for (int i = start; i <= end; ++i) {
            if (dups[i]) {
                tmpStart = i++;
                for (; i <= end; ++i) {
                    if (!dups[i]) {
                        tmpEnd = i - 1;
                        break;
                    }
                }
                if (i-- > end) {
                    tmpEnd = end;
                }
                if ((tmpLen = longestPalindromePartition(str, tmpStart, tmpEnd, maxLen)) > maxLen) {
                    maxLen = tmpLen;
                    maxStart = tmpStart;
                    maxEnd = tmpEnd;
                }
            } else {
                tmpStart = i;
                for (; i <= end; ++i) {
                    if (dups[i]) {
                        tmpEnd = i - 1;
                        break;
                    }
                }
                if (i-- > end) {
                    tmpEnd = end;
                }
                if (tmpStart == tmpEnd) {
                    while (tmpStart >= start && tmpEnd <= end && str[--tmpStart] == str[++tmpEnd]);
                    tmpLen = (--tmpEnd) - (++tmpStart) + 1;
                    if (tmpLen > maxLen) {
                        maxLen = tmpLen;
                        maxStart = tmpStart;
                        maxEnd = tmpEnd;
                    }
                }
            }
        }
        start = maxStart;
        end = maxEnd;
        delete[]dups;
        return maxLen;
    }
};
```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。