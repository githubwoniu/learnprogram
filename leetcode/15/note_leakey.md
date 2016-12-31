## 链接

【中等难度】15. 3Sum

https://leetcode.com/problems/3sum/


## 题目

Given an array *S* of *n* integers, are there elements *a*, *b*, *c* in *S* such that *a* + *b* + *c* = 0? Find all unique triplets in the array which gives the sum of zero.

**Note:** The solution set must not contain duplicate triplets.

```
For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

## 释义






## 补充描述
Simple python solution:
```python
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """ 
        nums.sort()
        C, maxi = set(), len(nums) - 2 # maxi: max index of pointer i backward
        for i in xrange(maxi):
            for j in xrange(i + 1, maxi + 1):
                if -nums[i] - nums[j] in nums[j + 1: ]:
                    C.add((nums[i], nums[j], -nums[i] - nums[j]))
        return list(C)
```





## 代码






```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> idx;
        int numsLen = nums.size();
        for (int pl = 0; pl < numsLen; pl++){
            if (pl > 0 && nums[pl] == nums[pl - 1])
                continue;  // jump duplicate number from left
            int pm = pl + 1, pr = numsLen - 1;
            while (pm < pr){
                int sum = nums[pl] + nums[pm] + nums[pr];
                if (sum > 0)
                    pr--;  // get a smaller number
                else if (sum < 0)
                    pm++;  // get a bigger number
                else{
                    idx.push_back(vector<int> {nums[pl], nums[pm], nums[pr]});
                    while (pm + 1 < pr && nums[pm] == nums[pm + 1]) pm++;  // pass dup
                    while (pr - 1 < pm && nums[pr] == nums[pr - 1]) pr--;
                    pm++;
                    pr--;
                }
            }
        }
        return idx;
    }
};
```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
