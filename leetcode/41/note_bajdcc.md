## 链接

41.First Missing Positive(Hard)

## 题目

Given an unsorted integer array, find the first missing positive integer.

For example,
Given `[1,2,0]` return `3`,
and `[3,4,-1,1]` return `2`.

Your algorithm should run in *O*(*n*) time and uses constant space.



## 方法一：排序查缺法

思路：将原数组排序，然后从前向后查找缺漏的，不过此方法复杂度为线性对数阶，不满足题意，但也能AC。


```c++

//代码放在这个块里面，可以高亮关键字

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        auto min = 1;
        for (auto &n : nums) {
            if (n > 0) {
                if (n == min)
                    min++;
                else if (n > min)
                    return min;
            }
        }
        return min;
    }
};
```

## 方法二：按位置换法

听说过希尔伯特旅馆悖论吧？那么这里，从前往后遍历nums，数组大小len，设当前为n。

这时思考，如果n<=0或者n>len，那么n必然是无效的。在这个范围内(1~len)的n，把它们放到nums[n-1]的位置上。

问题来了：新的位置上又有其他数字怎么办呢？答案是用递归去解决。递归解决后然后再置换。


```c++

//代码放在这个块里面，可以高亮关键字

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        for (auto &n : nums) {
            firstMissingPositive(nums, n);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != -2333)
                return i + 1;
        }
        return nums.size() + 1;
    }

    void firstMissingPositive(vector<int> &nums, int& n) {
        if (n > 0 && n <= nums.size()) {
            auto j = nums[n-1], &k = nums[n-1];
            if (j < 1) {
                k = -2333;
            } else if (j != -2333) {
                k = -666;
                firstMissingPositive(nums, j);
                k = -2333;
            }
        }
    }
};
```


## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。