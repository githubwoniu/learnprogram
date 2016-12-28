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

给定一个数组，找出所有的3元组，这些3元组之和为0，并且没有重复的元组。而且按顺序输出

## 补充描述

一开始打算用两个指针技术，进行求解。但是遇到“下一步怎么走“问题。
最后用了一个重复查询的方法，进行搜索。





## 代码






```c++


vector<vector<int>> threeSum(vector<int>& nums)
{
    bool myComp(vector<int> & a, vector<int> & b);
    sort(nums.begin(), nums.end());
    vector<int> temp(3);
    vector<vector<int>> res;
    res.reserve(100);
    auto size = nums.size();
    if(size >= 3)
    {
        decltype(size) st = 0;
        decltype(size) ed = size - 1;
        while((ed - st) >= 1 && nums[st] <= 0 && nums[ed] >= 0)
        {
            while((ed - st) >= 1 && nums[ed] >= 0)
            {
                int wt = -(nums[st] + nums[ed]);
                auto mid = find(nums.begin() + st + 1, nums.begin() + ed, wt);
                if(mid != nums.begin() + ed)
                {
                    temp[0] = nums[st];
                    temp[1] = *mid;
                    temp[2] = nums[ed];
                    res.push_back(temp);
                }
                //寻找下一个不重复的数值num[ed]
                while((ed - st) >= 1 && nums[ed] == nums[ed - 1])
                {
                    --ed;
                }
                --ed;
            }
            //寻找下一个不重复的数值num[st]
            while((ed - st) >= 1 && nums[st] == nums[st + 1])
            {
                ++st;
            }
            ++st;
            //更新ed
            ed = size - 1;
        }
    }
    return res;
}



```

别人比较好的程序，很简短。使用的是Two-pointer Tech 

```c++
vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> triples;
    triples.reserve(200);
    sort(nums.begin(), nums.end());
    int i = 0, last = nums.size() - 1;
    while(i < last)
    {
        int a = nums[i], j = i + 1, k = last;
        while(j < k)
        {
            int b = nums[j], c = nums[k], sum = a + b + c;
            if(sum == 0) triples.push_back({ a, b, c });
            if(sum <= 0) while(nums[j] == b && j < k) j++;
            if(sum >= 0) while(nums[k] == c && j < k) k--;
        }
        while(nums[i] == a && i < last) i++;
    }
    return triples;
}


```


## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
