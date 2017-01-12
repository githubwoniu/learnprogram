## 链接

https://leetcode.com/problems/remove-duplicates-from-sorted-array/

##解题思路

去掉重复的数字，其实就是erase()函数的内部实现。

我采用的pre-check技巧。

不过，这题还有更精简的做法。



## 代码






```c++
class Solution
{
	public:
	int removeDuplicates(vector<int>& nums)
	{
		int res = 0;
		for(int i = 0; i != nums.size();++i)
		{
			while((i+1)!=nums.size()&&nums[i+1] == nums[i])
			{
				++i;
			}
			nums[res++] = nums[i];
		}
		return res;
	}
};

```

与我的代码进行比较，感觉下面的代码更简洁一点
```c++
class Solution
{
	public:
	int removeDuplicates(vector<int>& nums)
	{
		//必须提前判断nums.empty()
		if(nums.empty()) { return 0; }

		int index = 0;
		for(int i = 1; i < nums.size(); ++i)
		{
			if(nums[index] != nums[i])
			{
				nums[++index] = nums[i];
			}
		}
		return index + 1;
	}
};
```


作弊法
```c++
class Solution
{
	public:
	int removeDuplicates(vector<int>& nums)
	{
		return distance(nums.begin(),unique(nums.begin(), nums.end()));
	}
};
```




## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
