## 链接


https://leetcode.com/problems/remove-element/


## 解题思路

1. 定义一个计数器，作用有二

+ 记录有几个目标值
+ 将不同与目标值的数字，移动到数组前面








## 代码






```c++
int removeElement(vector<int>& nums, int val) {
	vector<int>::size_type i = 0, j = 0;
	for (;i != nums.size();i++) {
		if (nums[i] == val)
			continue;
		nums[j] = nums[i];
		j++;
	}
	return j;
}
```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。