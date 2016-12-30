## 链接


https://leetcode.com/problems/zigzag-conversion/

## 解题思路

这道题目让按`z`型输出。根据样例，我们可以得出实现方法。

1. 有几行，我们就需要几个字符串记录每一行都是什么字符。我们可以采用`vector<string>`来记录每一行都有什么字符
2. 遍历原字符串，将每个字符，记录到他应该属于的字符串中。
3. 将每个字符串连接起来




## 代码






```c++
string convert(string s, int numRows) {
	if (s.empty())
		return "";
	vector<string> tres(numRows);
	vector<string>::size_type index;
	string res;
	auto len = s.size();
	for (index = 0; index < len; ) {
		for (int i = 0; i < numRows && index < len; i++)
			tres[i] = tres[i] + s[index++];
		for (int j = numRows - 2; j > 0 && index < len; j--)
			tres[j] = tres[j] + s[index++];
	}
	for (const string e : tres)
		res = res + e;

	return res;
}


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。