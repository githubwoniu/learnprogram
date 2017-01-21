## 链接

4.Median of Two Sorted Arrays(Hard)

## 题目

There are two sorted arrays **nums1** and **nums2** of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

**Example 1:**

```
nums1 = [1, 3]
nums2 = [2]

The median is 2.0

```

**Example 2:**

```
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```

## 释义

将两个有序数列进行归并，找到其中位数。

先计算中位数：

- 对总长n为奇数而言，中位数位置为n/2
- 对总长n为偶数而言，中位数位置为(n-1)/2和(n-1)/2+1

问题在于如何求出指定位置的数。

### 特例

特例肯定有，想一想：

- 其中一个数列为空，那么问题简单，在另一个数列中找即可
- 一个数列的最大值小于另一数列的最小值，即数列1最末位小于数列2最前位，这时将数列1和2看作整体，再进行查找

### 另外情况

这时只能从前面开始一个个比较。设当前需要找到第index位。

分别用两个指针记录当前数列1和2的位置。哪边的值较小，就将相应的位置前进一位，index递减。不断循环。

什么时候跳出循环：

- 某个数列被遍历到末尾了，这时只需要根据剩余的index在另外一个数列中查找即可
- index为-1了，即相应的位置已被找到

下面有几种情况：

- 其中一个数列遍历到末尾。若此时index为-1，那么位置就是这个数列的最末位，如果是奇数（中位数只要1位），就直接返回了；如果是偶数，就算上另一个数列的当前位置。若此时index不为-1，那么说明还要再往前面找几位，那么已遍历完的那个数列就out了，接下来只要在另一数列中查找即可。
- 若不是上面的情况，就是最典型的情况了。先根据first知道上一个值是在哪一个数列中，然而找出这个值num[ptr-1]，为什么要减一呢，这是因为在while循环中ptr需要向前移一位。如果是奇数，那么直接返回这个值；如果是偶数，那需要找出下一个值，下一个值在当前值后面一位和另外一数列当前位置中以较小值选择出来。

为什么这题难度为hard，我想不是因为思路想不到（归并），而是因为其中的步骤很烦，什么+1什么-1还要各种判断。

当然，还有可以优化的地方。如其中一数列元素只有一个，那么归并就变成了二分插入，能节省时间。


## 补充描述

83.14% https://leetcode.com/submissions/detail/89933853/




## 代码






```c++

//代码放在这个块里面，可以高亮关键字
#define MIN(a,b) (((a)<(b))?(a):(b))

class Solution {
public:
    static double findIdx(const vector<int> &nums1, const vector<int> &nums2, int index, bool odd)
    {
        int len1 = nums1.size(), len2 = nums2.size();
        auto ptr1 = 0, ptr2 = 0;
        if (len1 == 0)
        {
            return odd ? nums2[index] : ((nums2[index] + nums2[index + 1]) / 2.0);
        }
        if (len2 == 0)
        {
            return odd ? nums1[index] : ((nums1[index] + nums1[index + 1]) / 2.0);
        }
        if (nums1.back() <= nums2.front())
        {
            if (odd)
                return index < len1 ? nums1[index] : nums2[index - len1];
            if (index < len1 - 1)
                return (nums1[index] + nums1[index + 1]) / 2.0;
            if (index > len1 - 1)
                return (nums2[index - len1] + nums2[index - len1 + 1]) / 2.0;
            return (nums1[index] + nums2[0]) / 2.0;
        }
        if (nums2.back() <= nums1.front())
        {
            if (odd)
                return index < len2 ? nums2[index] : nums1[index - len2];
            if (index < len2 - 1)
                return (nums2[index] + nums2[index + 1]) / 2.0;
            if (index > len2 - 1)
                return (nums1[index - len2] + nums1[index - len2 + 1]) / 2.0;
            return (nums2[index] + nums1[0]) / 2.0;
        }
        auto first = true;
        while (ptr1 < len1 && ptr2 < len2 && index-- >= 0)
        {
            first = nums1[ptr1] <= nums2[ptr2];
            first ? ptr1++ : ptr2++;
        }
        if (index == -1)
        {
            if (ptr1 == len1)
            {
                return odd ? nums1.back() : (nums2[ptr2] + nums1.back()) / 2.0;
            }
            if (ptr2 == len2)
            {
                return odd ? nums2.back() : (nums1[ptr1] + nums2.back()) / 2.0;
            }
        }
        if (ptr1 == len1)
        {
            return odd ? nums2[ptr2 + index] : (nums2[ptr2 + index] + nums2[ptr2 + index + 1]) / 2.0;
        }
        if (ptr2 == len2)
        {
            return odd ? nums1[ptr1 + index] : (nums1[ptr1 + index] + nums1[ptr1 + index + 1]) / 2.0;
        }
        if (first)
        {
            if (odd)
                return nums1[ptr1 - 1];
            return (nums1[ptr1 - 1] + MIN(nums1[ptr1], nums2[ptr2])) / 2.0;
        }
        if (odd)
            return nums2[ptr2 - 1];
        return (nums2[ptr2 - 1] + MIN(nums2[ptr2], nums1[ptr1])) / 2.0;
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        auto count = nums1.size() + nums2.size();
        auto idx = (count - 1) / 2;
        return findIdx(nums1, nums2, idx, count % 2 == 1);
    }
};

```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。