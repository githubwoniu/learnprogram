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






## 补充描述






## 代码






```c++

//代码放在这个块里面，可以高亮关键字
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {

    vector<int> result(2);
    map<int,int>dic;
    int len = nums.size();

    for(int i = 0; i < len; i++)
      {
          if(dic.find(nums[i]) == dic.end())
          {
              dic[target - nums[i]] = i;
          }
          else
          {
              result[0] = dic[nums[i]];
              result[1] = i;
          }
      }
    return result;
  }
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
