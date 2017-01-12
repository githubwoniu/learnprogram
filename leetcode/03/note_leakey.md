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






## 补充描述
A similar python code:
```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        sLen = len(s)
        if sLen <= 1: return sLen  # s is shorter than 2 letters
        subStrLen, p1, p2 = 0, 0, 1  # use 2 pointers
        while p2 < sLen and subStrLen < 95:
            for p2 in xrange(p1, sLen):
                if s[p2] in s[p1:p2]:
                    break
                else:
                    p2 += 1
            subStrLen = max(p2 - p1, subStrLen) 
            p1 += 1
        return subStrLen
```





## 代码






```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sLen = s.size(), subStrLen = 0, p1 = 0, p2 = 1;
        if (sLen <= 1)
            return sLen;
        string subStr;
        while (p2 < sLen && subStrLen < 95){
            for (p2 = p1; p2 < sLen; p2++){
                subStr.assign(s, p1, p2 - p1); //substr is s[p1:p2]
                if (subStr.find(s[p2]) != -1) // s[p2] in substr
                    break;
            }
            subStrLen = max(p2 - p1, subStrLen);
            p1++;
        }
        return subStrLen;
    };
};

```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
