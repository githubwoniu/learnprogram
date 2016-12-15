## 链接


https://leetcode.com/problems/roman-to-integer/


## 题目

罗马数字转换为整数



## 释义

有两种方法：

- 从前往后扫描
- 从后往前扫描

其中，从后往前的方法比较简单，因此略。

主要是从前往后一次性扫描一遍。




## 补充描述

根据罗马数字的特点，左<右是减法，左>右是加法。

举例：

- 15 = XV
- 109 = CIX

那么有没有 CIXL？即 C | IX | L = 100 | 9 | 50 = 141？

答案是否，因为141 = 100 + 40 + 1 = C + XL + I = CXLI。

也就是说，罗马数字的特点是：

**千位 百位 十位 个位**

即：

**千位：1000 及以上 | 百位：100 ~ 999 | 十位：10 ~ 99 | 个位：0 ~ 9**

接下来分析：

### 个位

- 1     I
- 2     II
- 3     III
- 4     IX
- 5     V
- 6     VI
- 7     VII
- 8     VIII
- 9     IX

**方法：判断是否以I或V开头，否则判定该数字非法**

### 十位

- 10     X
- 20     XX
- 30     XXX
- 40     XL
- 50     L
- 60     LX
- 70     LXX
- 80     LXXX
- 90     XC

**方法：判断是否以X或L开头，否则判定该数字非法**

### 百位

- 100     C
- 200     CC
- 300     CCC
- 400     CD
- 500     D
- 600     DC
- 700     DCC
- 800     DCCC
- 900     CM

**方法：判断是否以D或C开头，否则判定该数字非法**

###  千位

有多少个M，就代表多少个1000。

## 词法规则

上下文无关文法：

- RomanNumeral -> Thousand Hundreds Tens Ones
- Thousands -> M Thousands | ε
- Hundreds -> LowHundreds | CD | D LowHundreds | CM
- LowHundreds -> ε| C | CC | CCC
- Tens -> LowTens | XL | L LowTens | XC
- LowTens -> ε | X | XX | XXX
- Ones -> LowOnes | IV | V LowOnes | IX
- LowOnes -> ε | I | II | III


## 代码

LL1词法分析：


```c++

//代码放在这个块里面，可以高亮关键字

class Solution {
    string str;
    int index;

public:
    Solution() {

    }

    int romanToInt(string s) {
        str = s;
        index = 0;
        return RomanNumeral();
    }

private:
    bool available() const {
        return index < str.length();
    }

    char get() const {
        return str[index];
    }

    void next() {
        index++;
    }

    bool match(char c) const {
        if (!available())
            return false;
        return get() == c;
    }

    int RomanNumeral() {
        if (!available()) {
            return 0;
        }
        return Thousand() + Hundreds() + Tens() + Ones();
    }

    int Thousand() {
        if (!available()) {
            return 0;
        }
        if (match('M')) {
            next();
            return RomanNumeral() + 1000;
        }
        return 0;
    }

    int Hundreds() {
        if (!available()) {
            return 0;
        }
        return Caculate('C', 'D', 'M', 100);
    }

    int Tens() {
        if (!available()) {
            return 0;
        }
        return Caculate('X', 'L', 'C', 10);
    }

    int Ones() {
        if (!available()) {
            return 0;
        }
        return Caculate('I', 'V', 'X', 1);
    }

    int Caculate(char one, char five, char ten, int power) {
        if (match(one)) {
            next();
            if (match(one)) {
                next();
                if (match(one)) {
                    next();
                    return 3 * power;
                }
                return 2 * power;
            }
            if (match(five)) {
                next();
                return 4 * power;
            }
            if (match(ten)) {
                next();
                return 9 * power;
            }
            return 1 * power;
        }
        if (match(five)) {
            next();
            if (match(one)) {
                next();
                if (match(one)) {
                    next();
                    if (match(one)) {
                        next();
                        return 8 * power;
                    }
                    return 7 * power;
                }
                return 6 * power;
            }
            return 5 * power;
        }
        return 0;
    }
};
```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
