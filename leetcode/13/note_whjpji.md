## 链接

https://leetcode.com/problems/roman-to-integer/

## 题目

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

## 释义

罗马数字由以下几种符号构成，各个符号所代表的数值如下表所示：

| 符号 | 数值 |
|------|------|
| I    | 1    |
| V    | 5    |
| X    | 10   |
| L    | 50   |
| C    | 100  |
| D    | 500  |
| M    | 1000 |

将所有符号对应的数值相加，便可得到整个罗马数字的值。但有以下几种例外情况：

| 符号 | 数值 |
|------|------|
| IV   | 4    |
| IX   | 9    |
| XL   | 40   |
| XC   | 90   |
| CD   | 400  |
| CM   | 900  |

即当某个符号对应的数值小于下一个符号对应的数值时，该符号对整个数字的贡献为负。

## 补充描述

用迭代器遍历字符串，将每位字符对应的数值相加即可，若遇到上述特殊情况，则应减去
该位字符的数值。

字符串能提供随机迭代器，支持以下操作：（详见 [Random Access
Iterator](http://www.cplusplus.com/reference/iterator/RandomAccessIterator/)）

<h4>Is default-constructible, copy-constructible, copy-assignable and
destructible</h4>
```
X a;
X b(a);
b = a;
```
<h4>Can be compared for equivalence using the equality/inequality operators
(meaningful when both iterator values iterate over the same underlying
sequence).</h4>
```
a == b
a != b
```
<h4>Can be dereferenced as an rvalue (if in a dereferenceable state).</h4>
```
*a
a->m
```
<h4>For mutable iterators (non-constant iterators):
Can be dereferenced as an lvalue (if in a dereferenceable state).</h4>
```
*a = t
```
<h4>Can be incremented (if in a dereferenceable state).
The result is either also dereferenceable or a past-the-end iterator.
Two iterators that compare equal, keep comparing equal after being both
increased.</h4>
```
++a
a++
*a++
```
<h4>Can be decremented (if a dereferenceable iterator value precedes it).</h4>
```
--a
a--
*a--
```
<h4>Supports the arithmetic operators + and - between an iterator and an integer
value, or subtracting an iterator from another.</h4>
```
a + n
n + a
a - n
a - b
```
#### Can be compared with inequality relational operators (`<`, `>`, `<=` and `>=`).
```
a < b
a > b
a <= b
a >= b
```
#### Supports compound assignment operations `+=` and `-=`
```
a += n
a -= n
```
#### Supports the offset dereference operator (`[]`)
```
a[n]
```
#### Lvalues are swappable.
```
swap(a,b)
```

## 代码

作者：@whjpji

```c++
class Solution {
 public:
  int get_value(char ch) {
    switch (toupper(ch)) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default : return 0;
    }
  }
  int romanToInt(string s) {
    int value = 0;
    for (auto iter = s.begin(); iter < s.end(); ++iter) {
      int current_value = get_value(iter[0]);
      if (iter + 1 < s.end() && current_value < get_value(iter[1])) {
        value -= current_value;
      } else {
        value += current_value;
      }
    }
    return value;
  }
};
```

## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
