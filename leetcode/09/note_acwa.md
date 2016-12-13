## 链接


https://leetcode.com/problems/palindrome-number/


## 题目





## 释义
笨方法，没有各位的那么巧妙。

> 【小马哥】没有笨方法哪来的巧方法，慢慢来

## 补充描述

## 代码

```c++
class Solution {
public:
	int pow_ten(int x)
	{
		int s=1;
		for(int i=1; i<=x; ++i)//使用前置递增
		s*=10;
		return s;
	}
    bool isPalindrome(int x) {
		if(x<0) return false;
        int n = 1;
        int xx=x;
        while(xx/10!=0)
        {
            n++;
            xx/=10;
        }
        if(n==1) return true;//这个判断不需要
	while(n>1)
        {
            int i=(x/(pow_ten(n-1)));
            int j=(x%10);
            if(i!=j)    return false;
            x/=10;
            x%=(pow_ten(n-2));
            n-=2;
        }
        return true;
    }
};




```

> 【小马哥】代码风格不太好，适当添加换行和大括号是好的习惯。通常即使if后面只有一句话也会加上大括号

## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。

