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

最长回文子串


## 补充描述

自己采用的是Brute Force，然后通过不断优化算法，强行AC。一次次优化的过程，真的很有成就感。
思路很简单，就是采用两指针，从尾开始判别，如果是回文数，哪肯定是那次循环当作最长的回文子字符串，因此直接break;进入下个循环。




## 代码

一开始程序如下：这些都会出现LTE错误，主要是测试用例给的string很大。

```c++
class Solution
{
	public:
	string longestPalindrome(string s)
	{
		if(s.size() == 0) { return{}; }
		int max = 0;
		string res;
		for(int i = 0; i != s.size(); ++i)
		{
//由于j每次都是查看最后一个位置，其实只需要从等于s[i]的最后一个位置开始
			for(auto j = s.size(); j != i; --j)
			{
				if(isPalindrome(s, i, j))
				{
					if(j - i > max)
					{
						max = j - i;
//可以不需要每次取出substr,可以直接记录起始位置就行；因为有个max，所以可以就记开始位置就好
						res = s.substr(i, j - i);
					}
					break;
				}
			}
		}
		return res;
	}
    //这个可以优化，不需要全部倒序就能判别是否是回文字符串
	bool isPalindrome(string s, int beg, int end)
	{
		string tem = s.substr(beg, end - beg);
		reverse(tem.begin(), tem.end());
		return s.substr(beg, end - beg) == tem?true:false;
	}
};

之后，改为
//NOTE：对于字符串的取值，可以直接s[beg],这样显得很整洁，虽然也是符号重载为迭代器实现的
bool isPalindrome(string s, int beg, int end)
	{
		while((end > beg) && *(s.begin() + beg) == *(s.begin() + end - 1))
		{
			++beg;
			--end;
		}
		if(end > beg) return false;
		else
		{
			return true;
		}
	}
```
通过几次优化，可以勉强通过程序，不过时间花费比较大，509ms.

```c++ 
class Solution
{
	public:
	string longestPalindrome(string s)
	{
		if(s.size() == 0) { return{}; }
		int max = 0;
		int beg = 0;
		for(int i = 0; i != s.size(); ++i)
		{
			for(auto j = s.size(); j != i; --j)
			{
				j = s.find_last_of(s[i], j);
				//肯定会找到j的，最坏的情况j==i;对于找到的子字符串如果长度<=max,那么直接跳出循环
				if(j + 1 - i <= max) { break; }
				if(isPalindrome(s, i, j + 1))
				{
					max = j + 1 - i;
					beg = i;
					break;
				}
			}
		}
		return s.substr(beg, max);
	}
	bool isPalindrome(string s, int beg, int end)
	{
		while((end > beg) && s[beg] == s[end - 1])
		{
			++beg;
			--end;
		}
		if(end > beg) return false;
		else
		{
			return true;
		}
	}
};
``` 


## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
