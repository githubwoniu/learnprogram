## 链接


https://leetcode.com/problems/remove-element/


## 题目





## 释义






## 补充描述






## 代码






```c++

//代码放在这个块里面，可以高亮关键字
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator n;
        for (n = nums.begin(); n != nums.end();)
            if (*n == val)
                n = nums.erase(n); // del the element and return to the next position of deleted element
            else
                n++;
        return nums.size();
    }
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
