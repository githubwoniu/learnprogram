## 链接


https://leetcode.com/problems/palindrome-number/


## 题目





## 释义






## 补充描述






## 代码






```c++

class Solution {
public:
    bool isPalindrome(int x) {
    if (x < 0)
        return 0;
    int sum = 0, temp = x;
    while (x){
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return temp == sum;
    }
};



```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
