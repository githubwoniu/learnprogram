## 链接


https://leetcode.com/problems/longest-common-prefix/



## 补充描述

1. 以第一个字符串为基准开始比较，去第一个字符串中每个字符开始与后面的字符串中的字符开始比较
2. 如果相同，则继续比较第二个，第三个，... 并且将每次相同结果进行累加
3. 如果不同，则结束
4. 返回累加结果


## 代码


```c++
string longestCommonPrefix(vector<string>& strs) {
	if (strs.empty())
		return "";
	if (strs.size() == 1)
		return strs[0];
	vector<string>::size_type begin;
	int	index;
	int len = strs[0].size();
	vector<string>::size_type strsLen = strs.size();
	string res;
	bool flag = true;
	for (index = 0; index < len; index++) {
		for (begin = 1;begin < strsLen; begin++) {
			if (strs[0][index] != strs[begin][index]) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			break;
		}
		else {
			res = res + strs[0][index];
		}
	}
	return res;
}


```

## mzf评审

1. 缓存的东西有点多了，跑下来是多少ms？
2. flag没必要，看下我的提交，或者discuss

## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
