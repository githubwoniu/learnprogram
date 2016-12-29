## 链接

https://leetcode.com/problems/two-sum/

## 题目

Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.

You may assume that each input would have **exactly** one solution.

**Example:**

```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

**UPDATE (2016/2/13):**
 The return format had been changed to **zero-based** indices. Please read the above updated description carefully. 



## 释义

输入一个整形数组nums，和目标数字c，要求在nums中找到满足a+b=c的两个数，并返回它们的下标。



## 补充描述
看到好多写成Hash格式，主要目的就是快速查找。我这边来一个使用“Two-pointers Technology”技术的解法。

首先，大致的思想就是对数组进行排序，然后设置两个指针，一个指向头一个指向尾，前后逼近，就能判断是否找到对应的值。

但是这个题目返回原来的序号，所以进行排序的时候，原来的序号就发生改变，因此我引入了一个辅助数组vector<Node>，进行存放对应的序号。


## 代码

```c++
class Solution
{
	public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		struct Node
		{
			int index;       //原来的序号
			int num;         //对应序号的数值
		};
		vector<Node> n_vec;
		n_vec.reserve(nums.size());

		//初始化n_vec
		for(int i = 0; i != nums.size(); ++i)
		{
			n_vec.push_back(Node{ i, *(nums.begin() + i) });
		}

		//将n_vec按num进行排序
		sort(n_vec.begin(), n_vec.end(), [](Node lh, Node rh) { return lh.num < rh.num; });


		int i = 0, j = static_cast<int> (nums.size() - 1);
		while(i < j)
		{
			int temp = (n_vec.begin() + i)->num + (n_vec.begin() + j)->num;
			if(temp<target)
			{
				++i;
			}
			else if(temp>target)
			{
				--j;
			}
			else
			{
				break;
			}
		}


		if(i < j)
		{
			int tem1 = (n_vec.begin() + i)->index, tem2 = (n_vec.begin() + j)->index;
			if(tem1 < tem2)
			{
				return  { tem1, tem2 };
			}
			else
			{
				return { tem2, tem1 };
			}
		
		}
		return vector<int>();
	}
};
```
跑了两次，一次9ms;一次12ms    速度还可以
## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
