## 链接


https://leetcode.com/problems/palindrome-number/


## 题目





## 释义






## 补充描述






## 代码






```c++

//代码放在这个块里面，可以高亮关键字

//代码一
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        vector<int> v;
        int num_sum = 0; //没必要了，直接用vector的size就可以
	while(x != 0){
            v.push_back(x % 10);
            x /= 10;
            ++num_sum;
        }
        for(int i=0; i<(num_sum/2); ++i){
            if(v[i] != v[num_sum-1-i])
                return false;
        }
        return true;
    }
};

//代码二
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
		return false;
	int c = 0;
	int temp = x;
	while(temp > 0){
		c = c * 10 + (temp % 10);
		temp /= 10;
	}
	if(c == x)//return可以简化
		return true;
	else
		return false;
    }
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
