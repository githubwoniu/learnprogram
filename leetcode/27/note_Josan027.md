## 链接


https://leetcode.com/problems/remove-element/


## 解题思路

非常简单的一个题目。删除数组中指定的值。


## 代码


```c++
class Solution
{
	public:
	int removeElement(vector<int>& nums, int val)
	{
		int index = 0;
		for(int i = 0; i != nums.size(); ++i)
		{
			if(nums[i] != val)
			{
				nums[index++] = nums[i];
			}
		}
		return index;
	}
};
```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
