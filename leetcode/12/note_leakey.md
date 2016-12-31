## 链接

【中等难度】12. Integer to Roman（数字转罗马文）

https://leetcode.com/problems/integer-to-roman/


## 题目

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

*Tags: Hash Table or Syntax-directed Translation(Advanced)*

## 释义






## 补充描述
Similar python solution:
```python
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        :ref: http://www.cnblogs.com/dosxp/archive/2008/08/13/1266781.html
        """
        hrom = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        trom = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        rom = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
        intdex = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
        hdic = dict(zip(intdex, hrom))   
        tdic = dict(zip(intdex, trom))
        dic = dict(zip(intdex, rom))
        
        rostr = ""
        k = num // 1000
        num = num % 1000
    
        h = num // 100
        num = num % 100
        
        t = num // 10
        num = num % 10
        
        rostr = "M"*k + hdic[h] + tdic[t] + dic[num]
        return rostr

```





## 代码






```c++

class Solution {
public: // Use dict to convert 0 - 3999 to Roman
    string intToRoman(int num) {
        char* rom3[4] = {"", "M", "MM", "MMM"};                                        //0XXX - 3XXX
        char* rom2[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}; //0XX - 9XX
        char* rom1[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}; //0X - 9X
        char* rom0[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; //0 - 9
        string s;
        s += rom3[num / 1000];  //X...
        s += rom2[num % 1000 / 100];  //.X..
        s += rom1[num % 100 / 10];  //..X.
        s += rom0[num % 10];  //...X
        return s;
    }
};

```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
