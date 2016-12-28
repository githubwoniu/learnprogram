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
第一反应是直观的写个双重循环，外层i从0到size，内层j从i+1到size，执行次数是n*(n+1)/2次，也就是O(n^2)……太可怕了，肯定过不了。

那么就得想办法优化了，优化效率的第一反应就是万恶的**打表法**……

假设数组中最小的数是1，最大的数是n，那么，我们是不是可以做一个长度为n的数组，初始为false，用输入数据作为下标，对应位置为true。

然后，我们只需要遍历一轮输入数据就行了，对于每个num，查询下target - num对应的布尔值是不是true，是的话就找到了。

这样的话，b的寻找不需要遍历，只需要一次索引查询，是常量级的，整体算法时间开销O(n)。



然而这么做的话，这个数组太大了，有办法优化么？

答案是用hash，也就是unordered_map，这东东同样提供常量级(一般情况)的查询。

所以解决方案就出来了，做一个hash，key是num，value是index。然后遍历一下nums，对每个a，求它对应的b，查询下b在不在hash里，若存在就找到了。

然后为了提高效率，还可以把hash的初始化合并到查询中。

本来是这样的：

1. 遍历nums，初始化hash
2. 遍历nums，查询hash，得到答案

现在可以写成这样：

- 遍历nums，针对每一个num，查询hash
  - 若存在则返回答案
  - 若不存在，则将num和其index插入hash。则下次遍历到它对应的b时，自然就能找到答案了。

这样的话，首先可以少一轮遍历，其次hash成员更少，查询效率更高，就酱。



## 代码

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_index;
        vector<int> ret;
        for(int index=0;index<nums.size();++index) {
            int num = nums.at(index);
            int anotherNum = target - num;
            if(num_index.find(anotherNum) != num_index.end()) {
                return { index, num_index.at(anotherNum) };
            }
            num_index.insert( { num, index } );
        }
        return {};
    }
};
```
跑了两次，都是打败了80.02%，也足够了，不需要再抠细节了。

## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
