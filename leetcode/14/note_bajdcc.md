## 链接


https://leetcode.com/problems/longest-common-prefix/


## 题目

求给定字符串数组的最大公共前缀。



## 释义

### 常规解法

双重for循环，将strs看作二维数组，按列推进。

### 另类解法

脑洞出没：只能从左往右遍历？错了！还可以二分遍历~

该方法纯属娱乐，其实貌似大约也许可能并不能提高效率，摔！不过尝试一种新方法未尝不可？

### 二分遍历法

来熟悉一下二分查找~

1. 设定下界lower和上界upper，设定中点mid=(lower+upper)/2
2. 若中点值较大，则范围缩小为lower~mid-1
3. 若中点值较小，则范围缩小为mid+1~upper
4. 若中点值相等，则查找成功
5. 若lower>upper，则查找失败

那么这里的二分遍历是怎样呢？

1. 设定下界lower和上界upper，设定中点mid=(lower+upper)/2
2. 若中点值匹配，这时要看lower~mid-1部分；如果lower~mid-1全部匹配，则结果取决于mid+1~upper的值，否则结果取决于lower~mid-1的值
3. 若中点值不匹配，这时只要看lower~mid-1部分


### 多线程优化

真实情况中，我猜，strs应该是一个G级别的庞然大物。。

为了解决效率的问题，需要进行多线程优化。

常规解法：按最短长度len，假如我有4个线程，那么每个线程分配len/4长度的任务。

问题来了——很不幸，3个线程都做了无用功。。

- 线程1：i'm the first!!! oh, 2500000 strings are true! 蛤蛤蛤!
- 线程2：false on 1st, excuse me???
- 线程3：false on 1st, r u crazy???
- 线程4：false on 1st, what the %^&$???
- CPU：r u kidding me??? remind me of lian-fa-ke...

尴尬：当线程2-4集体罢工的时候，线程1还在嘿咻嘿咻地工作，杀人的心都有了。这里线程A不能打扰线程B工作。

这个尴尬的问题是无法解决的，要么您老分配任务的时候好好想想？？

好吧，**减小任务粒度**，可以解决问题。

——————————

（二分解法）

思路：先画一个lower-upper的饼，让某个线程去分饼。它从中间开始分，将饼分成两块（左边一块大的，右边一块小的），如果运气不好，两块还得继续分；运气好，只需要分前面一块，后面一块可以不要了。运气好的情况不讨论。运气不好的时候，问题来了，右边一块匹配！然而左边一块失败！处理右边一块的线程：excuse me???不过、、、右边一块饼并不是由单独一个线程去分的（递归嘛），也就是说，如果任务失败，那么相当于所有线程都白白干了一件蠢事；当然了，如果任务顺利，线程们都会欢欣鼓舞。

所以二分法有一个人情味的好处：**同甘共苦**，仿佛线程们有了生命一样。每个线程都知道自己的任务范围在变得越来越小，这样就能看到希望！

从快速定界方面看，常规解法是一次性出上界，而二分解法可以渐渐缩小上界范围。

从多线程方面看，二分法粒度是1，常规法可以>=1。

总结，二分法比常规法多做了一件事件：**探测上界范围**，**适用于快速估算**。为什么写二分法，因为闲。。

——————————

假如要做个进度条，用常规解法，从左到右读条，不知道什么时候突然就满了，等待时间去问薛定谔的猫吧；用二分解法，参考xp的磁盘碎片整理，可以在没有遍历结束前缩小范围。

## 补充描述

运行时间看人品系列：https://leetcode.com/submissions/detail/87863222/




## 代码


```c++

//代码放在这个块里面，可以高亮关键字
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs[0];
        long min_len = -1;
        int min_idx = -1;
        int i = 0;
        for (auto &s : strs) {
            if (s.length() < min_len) {
                min_len = s.length();
                min_idx = i;
            }
            i++;
        }
        if (min_len == 0)
            return "";
        auto min_str = strs[min_idx];
        return min_str.substr(0, 1 + getMax(strs, min_str, 0, min_len - 1));
    }

    long getMax(const vector<string> &vec, const string &str, long lower, long upper) {
        if (lower == upper)
            return can(vec, str[lower], lower) ? lower : -1;
        auto mid = (lower + upper) / 2;
        if (!can(vec, str[mid], mid)) {
            return lower == mid ? -1 : getMax(vec, str, lower, mid - 1);
        }
        if (lower == mid) {
            auto up = getMax(vec, str, mid + 1, upper);
            return mid == upper ? upper : (up == -1 ? mid : up);
        }
        auto lo = getMax(vec, str, lower, mid - 1);
        if (lo == mid - 1) {
            auto up = getMax(vec, str, mid + 1, upper);
            return mid == upper ? upper : (up == -1 ? mid : up);
        }
        return lo;
    }

    bool can(const vector<string> &vec, const char &ch, long idx) {
        for (auto &s : vec) {
            if (s[idx] != ch)
                return false;
        }
        return true;
    }
};
```

## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
