## 链接


https://leetcode.com/problems/remove-duplicates-from-sorted-array/

##解题思路

1. 定义两个迭代器`s1`,`s2`,` s1`用来记录不重复元素的位置，s2用寻找不重复的元素。
2. 当`s2` 发现了不是重复的元素的时候，就将`s2`所指的元素插入到`s1`下一个所指的位置。
3. 最后删除`s1`到数组结束的元素


## 代码






```c++
int removeDuplicates(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	vector<int>::size_type  len = nums.size();
	vector<int>::iterator s1 = nums.begin();
	vector<int>::iterator s2 = nums.begin() + 1;
	vector<int>::iterator e = nums.end();
	while (s2 != e) {
		if (*s1 == *s2)
			s2++;
		else {
			s1++;
			*s1 = *s2;
			s2++;
		}
	}
	nums.erase(s1 + 1, e);
	return nums.size();
}

```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。