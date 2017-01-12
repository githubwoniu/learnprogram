## 链接

https://leetcode.com/problems/zigzag-conversion/

## 题目

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R
And then read line by line: `"PAHNAPLSIIGYIR"`
Write the code that will take a string and make this conversion given a number of rows:

    string convert(string text, int nRows);
`convert("PAYPALISHIRING", 3)` should return `"PAHNAPLSIIGYIR"`.

## 释义

已知输入为字串A和数字n，求输出为字串B。即B=fun(A,n)。

A和B之间存在映射关系f，即B[i]=A[f(i)]，问题在于求映射f。

    0   4   8
    1 3 5 7 9
    2   6

以上述为例，输入A=0123456789，n=3。

可以看出：一共n行。

- 第一行：起始行，以0开始，公差为4。
- 第二行：以1开始，公差为4，公差之内包括两个数字。
- 第三行：结束行，以2开始，公差为4。

经过不断推导，最终得出映射关系。

若串为A，长度为len，行数为numRows，则关系为：

- 第一行，从0开始，公差d=(numRows - 1)*2，下标超过len-1无效。
- 第二行到倒数第二行，设该行是k行，则该行从k开始，公差为d，公差内包括两个数字，第二个数字=第一个数字+d- (k*2)，下标越界作废。
- 最后一行，同第一行。

注：该法不用把zigzag矩阵罗列出来，直接写于结果当中。

## 补充描述

提交：https://leetcode.com/submissions/detail/87277753/

用时：12ms，beat：96%（运气好）


## 代码




```c++
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = (int) s.length();
        auto arr = new char[n];
        if (numRows <= 1) {
            return s;
        } else {
            int index, add, start;
            index = start = 0;
            add = (numRows - 1) << 1;
            for (int i = start++; i < n; i += add) {
                arr[index++] = s[i];
            }
            for (int k = 1, j; k < numRows - 1; ++k) {
                for (int i = start++; i < n; i += add) {
                    arr[index++] = s[i];
                    if (((j = i + add - (k << 1)) < n)) {
                        arr[index++] = s[j];
                    }
                }
            }
            for (int i = start; i < n; i += add) {
                arr[index++] = s[i];
            }
        }
        decltype(s) result(arr, s.length());
        delete[]arr;
        return result;
    }
};
```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
