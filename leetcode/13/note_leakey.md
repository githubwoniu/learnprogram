## 链接


https://leetcode.com/problems/roman-to-integer/


## 题目





## 释义






## 补充描述






## 代码






```c++

class Solution {
public:
    int romanToInt(string s) {//use hash table
        unordered_map<char, int> dict = {{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};
        int num = dict[s.back()], i = s.length() - 1;
        while (--i >= 0)
            num = num + (dict[s[i]] < dict[s[i + 1]] ? -dict[s[i]] : dict[s[i]]);
        return num;
    }
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
