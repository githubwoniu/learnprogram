## 链接

【中等难度】22. Generate Parentheses（生成括号）

https://leetcode.com/problems/generate-parentheses/


## 题目

Given *n* pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given *n* = 3, a solution set is:

```
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
```

*Tags: Backtracking*

## 释义

遇到中等难度的题目，就要像很久。这题还是看着答案，码了一遍。

应该是回溯的方法。Backtraking

## 代码

```c++
class Solution
{
	private:
	//lhs表示path里面左括号个数，rhs表示path里面左括号个数
	//res用来记录返回结果，path记录当前字符串；
	void generate(int n, int lhs, int rhs, vector<string>& res, string& path)
	{
		//lhs达到最大值，那么只能继续加入右括号
		if(n == lhs)
		{
			string s(path);
			res.push_back(s.append(n - rhs, ')'));
			return;
		}
		path.push_back('(');
		generate(n, lhs + 1, rhs, res, path);
		path.pop_back();
		
		//左括号个数大于右括号个数，才可以插入）
		if(lhs > rhs)
		{
			path.push_back(')');
			generate(n, lhs, rhs + 1, res, path);
			path.pop_back();
		}
	}

	public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> res;
		string path;
		if(n > 0) generate(n, 0, 0, res, path);
		return res;
	}
};

```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
