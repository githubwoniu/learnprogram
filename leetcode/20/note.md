## 链接


https://leetcode.com/problems/valid-parentheses/


## 题目





## 释义






## 补充描述






## 代码






```c++

//代码放在这个块里面，可以高亮关键字
class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for (char& c : s)
            p.empty() ? p.push(c) : (c == p.top() + 2 || c == p.top() + 1 ? p.pop() : p.push(c));
        return p.empty();
    }
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
