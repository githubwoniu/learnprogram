## 链接


https://leetcode.com/problems/remove-duplicates-from-sorted-array/


## 题目





## 释义






## 补充描述






## 代码






```c++

//代码放在这个块里面，可以高亮关键字
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, n = nums.size();
        for (int j = 1; j < n; j++)
            if (nums[i] != nums[j])
                nums[++i] = nums[j];
        return n <= 1 ? n : i + 1;
    }
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
