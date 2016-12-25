## 链接


https://leetcode.com/problems/two-sum/


## 题目





## 释义






## 补充描述






## 代码






```c++

//代码放在这个块里面，可以高亮关键字
class Solution { 
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, n = nums.size();
        unordered_map<int, int> idx; 
        while (i < n && idx.find(target - nums[i]) == idx.end()) { // find the other number and not same with the current number
            idx[nums[i++]] = i;
        }
    return {idx[target - nums[i]] - 1, i};
    }
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
