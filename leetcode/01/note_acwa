## 链接


https://leetcode.com/problems/two-sum/


## 题目





## 释义






## 补充描述






## 代码






```c++

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        map<int, int> loc;
        map<int, int> c;//记录数字出现次数
        for(int i=nums.size()-1; i>=0; i--)
        {
            loc[nums[i]]=i;
            c[nums[i]]++;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(c[target-nums[i]]==1 && nums[i]*2!=target)
            {
                v.push_back(i);
                v.push_back(loc[target-nums[i]]);
                return v;
            }
            if(c[target-nums[i]]>1)
            {
                v.push_back(i);
                if(nums[i]*2!=target)
                {
                    v.push_back(loc[target-nums[i]]);
                }
                else
                {
                    int f=0;
                    for(int j=i+1; j<v.size(); j++)
                    {
                        if(nums[j]==nums[i])
                        {
                            v.push_back(j);
                        }
                    }
                }
            }
        }
        return v;
    }
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
