## 链接


https://leetcode.com/problems/roman-to-integer/


## 题目
罗马数字转换为整数
## 释义

了解罗马数字的表示方法墨迹了一会

## 补充描述






## 代码






```c++

#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
    map<char,int> intOfRoman;
    intOfRoman['I']=1;
    intOfRoman['V']=5;
    intOfRoman['X']=10;
    intOfRoman['L']=50;
    intOfRoman['C']=100;
    intOfRoman['D']=500;
    intOfRoman['M']=1000;

    int res = 0;
    int j;
    for(int i=s.length()-1; i>=0; i=j)    //从后向前遍历
    {
        for(j=i-1; ;j--)
        {
            if(s[j]!=s[j+1] || j<0)
            {
                break;    //与前一个字符不相同就停止，进行加或减法运算
            }
        }
        int tempRes = intOfRoman[s[i]]*(i-j);    //i-j为相同的字符个数
        if(res<=tempRes)
        {
            res+=tempRes;
        }
        else
        {
            res-=tempRes;
        }
    }
    return res;
    }
};




```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
