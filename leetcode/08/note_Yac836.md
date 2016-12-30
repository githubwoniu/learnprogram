## 链接


https://leetcode.com/problems/string-to-integer-atoi/


## 解题思路
1. 找出开始数字和结束数字然后装换

***注意***
1. int 最小值
2. 正负数



## 代码






```c++
int myAtoi(string str) {
	int i = 0;
	int flag = 0;
	double res = 0;
	int sign = 1;
	for (auto c : str) {
		if (!isdigit(c)) {
			i++;
		}
		else
			break;
	}
	int temp = i - 1;
	for (int index = 0; index < temp; index++) {
		if (isspace(str[index]))
			continue;
		else {
			flag = 1;
			break;
		}
	}
	if (flag)
		return 0;
	if (i > 0) {
		if (str[i - 1] == '+' || isspace(str[i - 1]))
			sign = 1;
		else if (str[i - 1] == '-')
			sign = -1;
		else
			return 0;
	}
	for (decltype(str.size()) index = i; index < str.size(); index++)
		if (isdigit(str[index]))
			res = res * 10 + (str[index] - '0');
		else
			break;
	res = res * sign;
	if (res > 2147483647)
		return 2147483647;
		// -2147483648 直接写 vs2015 会报错 codeblocks 不会
	if (res < -2147483647 - 1)
		return -2147483647 - 1;
	return res;
}

```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。