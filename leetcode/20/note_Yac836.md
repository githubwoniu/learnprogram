## 链接


https://leetcode.com/problems/valid-parentheses/

## 解题思路

1. 利用stack
2. 如果栈顶元素和字符串中下一个元素相等，则栈顶元素出栈，如果不能，则下一个元素入栈。




## 代码






```c++
bool isValid(string s) {
	if (s.empty())
		return true;
	auto len = s.size();
	string::size_type index;
	stack<char> cs;
	cs.push(s[0]);
	for (index = 1; index < len; index++) {
		if (cs.empty())
			if (s[index] != ')'&&s[index] != '}'&&s[index] != ']') {
				cs.push(s[index]);
				continue;
			}
			else {
				return false;
			}
			char e = cs.top();
			if (e == '(') {
				if (s[index] == ')')
					cs.pop();
				else
					cs.push(s[index]);
			}
			else if (e == '{') {
				if (s[index] == '}')
					cs.pop();
				else
					cs.push(s[index]);
			}
			else if (e == '[') {
				if (s[index] == ']')
					cs.pop();
				else
					cs.push(s[index]);
			}
	}
	if (cs.empty())
		return true;
	else
		return false;
}


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。