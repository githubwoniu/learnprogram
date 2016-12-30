## 链接


https://leetcode.com/problems/reverse-integer/




## 思路

1. 将每位上的数字拿出来，存到`vector`中，从低位开始拿
2. 再将每一位加起来




## 代码






```c++
int reverse(int x) {
	vector<int> ivct;
	//2147483647
	vector<int> maxInt{ 2,1,4,7,4,8,3,6,4,7 };
	int flag = 1;
	int res = 0;
	if (x == 0 || x == -2147483647 - 1)
		return 0;
	if (x < 0) {
		x = -x;
		flag = -1;
	}
	while (x != 0) {
		ivct.push_back(x % 10);
		x = x / 10;
	}
	decltype(ivct.size()) len = ivct.size();
	if (len == 10) {
		if (ivct > maxInt)
			return 0;
	}
	for (decltype(ivct.size()) index = 0; index < ivct.size(); index++)
		res = res * 10 + ivct[index];
	res = res * flag;
	return res;
}
```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。