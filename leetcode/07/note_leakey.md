## 链接


https://leetcode.com/problems/reverse-integer/


## 题目





## 释义






## 补充描述






## 代码






```c++

//代码放在这个块里面，可以高亮关键字
class Solution {
public:
    int reverse(int x) {
        long long y = 0;
        while (x) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y < INT_MIN || y > INT_MAX ? 0 : y;
    }
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
