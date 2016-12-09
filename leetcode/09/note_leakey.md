## 链接


https://leetcode.com/problems/palindrome-number/


## 题目





## 释义






## 补充描述


The second solution is a C++ version of Python 1 liner:
```python
return str(x).reverse == str(x)
```


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
    bool isPalindrome1(int x) {
        string s1 = to_string(x), s2 = s1;
        reverse(s1.begin(), s1.end());
        return s1 == s2;
    }
};



```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
