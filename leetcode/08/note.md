## 链接


https://leetcode.com/problems/string-to-integer-atoi/


## 题目





## 释义






## 补充描述






## 代码






```c++

//代码放在这个块里面，可以高亮关键字
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign, MAX = 0;
        long long val = 0;
        for (i = 0; isspace(s[i]); i++); //remove spaces from left
        sign = (s[i] == '-' ? -1 : 1);
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (val = 0; isdigit(s[i]); i++){
            val = 10 * val + (s[i] - '0');
            if (val > INT_MAX)
                return (sign == 1 ? INT_MAX : INT_MIN);
        }
        return val * sign;
    }
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
