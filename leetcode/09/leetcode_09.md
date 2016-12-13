继续跟小马哥刷LeetCode的算法，微信的学习群人数过百有一个百人学习活动。小马哥的专栏——[马志峰的编程笔记](https://zhuanlan.zhihu.com/mazhifeng)

**题目** [leetcode_09](https://leetcode.com/problems/palindrome-number/) 

就是计算一个整数是不是回文数，题目很简单。话说我也就只能做做这种题目了。

**解题思路**

对题意中的 without extra space不太理解。我如果重新int 一个b算不算啊。求问

> [小马哥]我对这句也不太理解，不过应该不至于连个变量都不让用吧，哈哈

首先负数肯定不存在回文数，所以负数的情况排除。另外考虑内存溢出的情况，如果一个数反转以后内存溢出，那么肯定不会是回文数，因为两个数不相等了。如果一个数本身就溢出，那么根本不可能输入进去，所以内存溢出问题在代码上是可以不用考虑的。最后一个特殊情况0，单独说明。

我是用反转做的反转代码：

```c++
while(val)
  {
     b = b*10+val%10;
  	 val=val/10;
  }
```

这个反转思想就最普通的思想，好像看见的反转数都是用这个思想来写的。有更好的可以教我一下。

完整代码如下：

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        int b = 0,val = x;
        if(x == 0)
         return true;
        if(x < 0)
            return false;
      
        else
        {
        while(val)
          {   
            b = b*10+val%10;
            val = val/10;
          }
         if(x == b)
            return true;
         else
            return false;
        }
    }
       
};
```

> [小马哥]思路很好，稍微简化了一下代码，如下

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
          return false;
        }

        int iTemp = x, b = 0;

        while (iTemp)
        {
          b = b * 10 + iTemp % 10;
          iTemp /= 10;
        }

        return x == b;
    }
};
```

**遇到的问题**

之前是直接把x放入循环，然后进行比较的，然后得出的答案就一直是false，一脸懵逼。然后发现当把x输入进去的时候x的值会改变，无论如何x都是0。所以将x赋值给val。对val进行计算。是不是违反了题意啊。

> [小马哥] 因为你后面还要用x的原值与反转后的b进行比较，循环里面又改变了x，所以才会一直false

**其他思路**

在群里看见一个同学用的是迭代器做的代码如下：

```c++
for(auto it = b.rbegin(); it != b.rend(); ++it) //将之前的数从尾到头读取
    n.push_back(*it);							//每读取一个压入新的数中，然后比较将新数跟就数比较。
```

其实就相当于申请一个空间将数放进去然后从最后开始读取。这个虽然肯定违反了题意，但是C++中有现成的轮子提供给了我们，我们为什么不用呢。自己虽然已经学过这个部分，但是为什么没有想到这个现成的呢？所以还是要好好看书，活学活用的。
