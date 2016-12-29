

## 链接


https://leetcode.com/problems/roman-to-integer/


## 题目
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.

## 释义
1、罗马数字有部分规则如下：
* 当小数处于大数左边时，大数减去小数；
* 当小数处于大数右边时，两数相加；
* 对于大数减去小数这种情况，小数只能有1位；
* 对于大数减去小数这种情况，小数只能比大数低一个进位；
* 数字必须从高进位到低进位顺序书写；

2、从上方的几个规则中，可以得出以下推论：
* 大数减去小数，可视为小数的负数数值加上大数的正数数值；
* 对于大数减去小数这种情况，小数只能比大数低一个进位，就表示：
> 对于个位数，只能由`I、V、X`组成
> 对于十位数，只能由`X、L、C`组成
> 对于百位数，只能由`C、D、M`组成

* 由于大数减去小数这种情况下，小数只能有1位。那么就可以把某一进位(比如十进位）的所有情况都枚举出来：
> `X`
> `XX`
> `XXX`
> `XXXX`或`XL`
> `L`
> `LX`
> `LXX`
> `LXXX`
>` LXXXX`或`XC`

* 观察十进位的所有数字，可以发现：
> - 在某一进位内部，除最后一个字母外，其余字母代表的数字要视作正数还是负数，只要比较它和它的后驱字母的大小即可判断；
> - 在某一进位内部，最后一个字母必须视为正数。

* 由于数字要以`(千)(百)(十)(个)`这样的顺序书写，那下一步再来考虑进位衔接处的情况。
从上文枚举出的十进位所有数字中可以发现：`C`不可能出现在十进位的第一位，十进位的首字母只能是`L`或`X`。而如果我们枚举出百进位的所有数字，就能发现百进位的数字只能以`C、D`或`M`结束，那就意味着：__在进位衔接处，高进位的末字母肯定大于低进位的首字母。__那么“一个字母代表的数字要视作正数还是负数，只要比较它和它的后驱字母的大小即可判断”这个推论在进位衔接处也是成立的。
由此可得这个结论在整个罗马数字里都是成立的：
> __一个字母代表的数字是正数还是负数，只要判断它的后驱字母是否比它大即可。__

## 补充描述　
* 有了上文的结论，就可以来编写代码了。
* 声明一个整型数result，然后遍历罗马数字内的所有字母，对于每一个字母都判断它和它的后驱字母之间的大小关系：如果它大于后驱字母，则result加上它；如果它小于后驱字母，则result减去它。
* 最终的result就是罗马数字转化过来的整型数。。

## 代码
```c++
class Solution {
public:
    int romanToInt(string s) {
        if (!s.length()) {
            return 0;
        }
        
        int rusult = 0;
        char c;
        char nextC;
        
        for (int i = 0; i < s.length(); i++) {
            c = s[i];
            if (i < s.length()-1) {
                nextC = s[i+1];
                
            } else {
                nextC = NULL;
            }
            
            if (this->convertSingleRoman(c) >= this->convertSingleRoman(nextC)) {
                rusult += convertSingleRoman(c);
                
            } else {
                rusult -= convertSingleRoman(c);
            }
        }
        
        return rusult;
    }
    
    int convertSingleRoman(char n) {
        switch (n) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
                
            default: return 0;
        }
    }
};
```

## 更多
![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)
PS: 请保留二维码链接，以便更多人参与进来。谢谢。
