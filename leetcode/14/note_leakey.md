## 链接


https://leetcode.com/problems/longest-common-prefix/


## 题目





## 释义






## 补充描述






## 代码






```c++

//代码放在这个块里面，可以高亮关键字
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return string();
        int i, j;
        for (i = 0; i < strs[0].length(); i++) 
            for (j = 1; j < strs.size(); j++) 
                if (strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
        return strs[0].substr(0, i);
    }
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
