## 链接


https://leetcode.com/problems/two-sum/


## 题目

Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.

You may assume that each input would have **exactly** one solution.



## 释义

从一个数组中给出找出两个整数，和等于所给的目标值。


## 补充描述
下标从零开始

## 代码
```c++
vector<int> twoSum(vector<int>& nums, int target) {
	decltype(nums.size()) len = nums.size();
	vector<int> res;
	for (decltype(nums.size()) i = 0; i < len; i++) {
		for (decltype(nums.size()) j = i + 1; j < len; j++) {
			if (nums[i] + nums[j] == target) {
				res.push_back(i);
				res.push_back(j);
			}
		}
	}
	return res;
}
```



## 更多

![d](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。