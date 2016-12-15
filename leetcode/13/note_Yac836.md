### 题目

将罗马数字转化为数字

### 代码

```c++
int romanToint(string s) {
	int temp = 0;
	int sum = 0;
	int pre = 0;
	for (int index = s.size() - 1; index >= 0; index--) { // 从后面开始遍历
		switch (s[index]) {
		case 'M':
			temp = 1000;
			break;
		case 'D':
			temp = 500;
			break;
		case 'C':
			temp = 100;
			break;
		case 'L':
			temp = 50;
			break;
		case 'X':
			temp = 10;
			break;
		case 'V':
			temp = 5;
			break;
		case 'I':
			temp = 1;
			break;
		}
		if (pre > temp)
			sum = sum - temp;
		else
			sum = sum + temp;
		pre = temp;

	}
	return sum;
}
```

