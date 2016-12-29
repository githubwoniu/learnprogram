## 链接


https://leetcode.com/problems/two-sum/


## 题目

给定一个数组array和一个数n，求array中某两个元素（它们的和为n）的下标。

假定下标总是存在。

## 释义

### 方法一：穷举

最简单的方法，穷举法或暴力破解法（BF），两层for循环。

用伪代码表示：

```c
for (i,index_i in array) {
	for (j,index_j in array[index_i+1..]) {
     	if(i+j==n) return [i,j]
	}
}
//not found!
```

穷举法的**缺点是循环次数太多，复杂度为O(n^2)**，太高，所以需要优化策略。

**思考：**

穷举法的缺点：数组每增加一个元素，就需要多遍历n次（n为原来数组的长度）。

数组array为array=[a1,a2,a3...an]，假设要求和为k。

穷举法的思路是：

```c
for (i,index_i in array) {
	if (k-i 在 array 中且不和i重复) return 下标
}
//not found!
```

这就转变为**「如何在数组中查找一个特定值」**的问题。

对于这个问题的解决方案就是**散列表**（或称哈希表）。

最简单的思路：**打表法**。设查找的数字范围是0-n，那么只要构建n为大小的数组arr，判断arr[n]==1即可。缺点：以空间换时间，空间复杂度太高（占用很大的空间），需要权衡。

权衡结果（即我使用的方法）=打表法+散列查找。

### 方法二：散列

由于空间有限，我们只能将int32范围内的数字映射到0-255之间。

最简单的方法：取模运算。hash=n mod 256。

我采用的自己瞎掰的一套散列函数（仅供娱乐，其实用本题用取模就足够）：

```c++
    inline int hash(int key) const {
        int value = 0xabcdabcd;
        key += 0x12345678;
        int k = key;
        while (key) {
            value += key & 0x3;
            value = (value >> 1) ^ 0xbadbadcc;
            key >>= 2;
        }
        value ^= k;
        value ^= 0xccbadbad;
        value = (value & 0xff);
        value ^= (value & 0xff00) >> 8;
        value ^= (value & 0xff0000) >> 16;
        value ^= (value & 0xff000000) >> 24;
        for (int i = 0; i < k % 0xf; i++) {
            value = (k % 0xff) - value;
            value = (value & 0xff);
        }
        return value;
    }
```

问题来了：两个数的散列值一样怎么办？简单，用链表。

但是有人说了：链表太长了！那同样简单，一个结点保存5个值呗，用完再建。

最终就形成了下面的算法。

## 补充描述

提交：https://leetcode.com/submissions/detail/86803868/

用时：9ms，beat：96%（不用std就是快）


## 代码




```c++
#include <iostream>
#include <vector>

using namespace std;

static const int INVALID_NUM = INT32_MIN;

struct Pair {
    int key, value;
};

class Hash {
    static const int SEED = 0xbadbadcc;
    static const int CACHE_SIZE = 0x100;
    static const int CACHE_MIN = -CACHE_SIZE/2;
    static const int CACHE_MAX = CACHE_SIZE/2;
    int cache[CACHE_SIZE];
    static const int HASH_BITS = 8;
    static const int NODE_SIZE = 1 << HASH_BITS;
    static const int NODE_CHUNK_SIZE = 5;
    class Node {
        Pair data[NODE_CHUNK_SIZE];
        int index;
        struct Node *next;
    public:
        Node() {
            index = 0;
            next = nullptr;
        }

        ~Node() {
            if (next)
                delete next;
        }

        void add(int key, int value) {
            if (index >= NODE_CHUNK_SIZE) {
                if (!next) {
                    next = new Node();
                }
                next->add(key, value);
            } else {
                data[index].key = key;
                data[index].value = value;
                index++;
            }
        }

        int get(int key) const {
            for (int i = 0; i < index; i++) {
                if (data[i].key != INVALID_NUM && data[i].key == key) {
                    return data[i].value;
                }
            }
            if (next)
                return next->get(key);
            return INVALID_NUM;
        }
    };
    Node data[NODE_SIZE];

public:
    Hash() {
        for (int i = 0; i < CACHE_SIZE; i++) {
            cache[i] = INVALID_NUM;
        }
    }

    inline int hash(int key) const {
        int value = 0xabcdabcd;
        key += 0x12345678;
        int k = key;
        while (key) {
            value += key & 0x3;
            value = (value >> 1) ^ 0xbadbadcc;
            key >>= 2;
        }
        value ^= k;
        value ^= 0xccbadbad;
        value = (value & 0xff);
        value ^= (value & 0xff00) >> 8;
        value ^= (value & 0xff0000) >> 16;
        value ^= (value & 0xff000000) >> 24;
        for (int i = 0; i < k % 0xf; i++) {
            value = (k % 0xff) - value;
            value = (value & 0xff);
        }
        return value;
    }

    int get(int key) const {
        if (key >= -CACHE_MIN && key < CACHE_MAX) {
            return cache[key + CACHE_MIN];
        }
        return data[hash(key)].get(key);
    }

    void add(int key, int value) {
        if (key >= -CACHE_MIN && key < CACHE_MAX) {
            cache[key + CACHE_MIN] = value;
        } else {
            data[hash(key)].add(key, value);
        }
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        Hash hash;
        int i, index = 0, value;
        for (i = 0; i < nums.size(); i++) {
            if ((index = hash.get(target - (value = nums[i]))) != INVALID_NUM) {
                return vector<int>{index, i};
            }
            hash.add(value, i);
        }
        if (hash.get(target - nums[i]) != INVALID_NUM) {
            return vector<int>{index, i};
        }
        return vector<int>{-1, -1};
    }
};
```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。