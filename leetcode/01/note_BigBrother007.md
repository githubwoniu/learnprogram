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
       int n = nums.size();
        int first = 0, second = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
                if (nums[i] + nums[j] == target)
                {
                    first = i;
                    second = j;
                    break;
                }
        }
        return vector<int> {first, second};
    }
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
