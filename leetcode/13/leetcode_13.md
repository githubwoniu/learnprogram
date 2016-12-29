跟着小马哥刷LeetCode算法。这边是小马哥的专栏——[马志峰的编程笔记](https://zhuanlan.zhihu.com/mazhifeng)

**题目**[leetcode_13](https://leetcode.com/problems/roman-to-integer/)

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

给一个罗马数字将其转换成整数。保证输入在1到3999之间。

**解体思路**

刚看到题目一脸蒙蔽啊，什么意思，roman是什么啊。没办法先去作弊看了一下其他人的博客。然后恍然大悟啊。

具体roman数字表示如下

|  I   |  V   |  X   |  L   |  C   |  D   |  M   |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: |
|  1   |  5   |  10  |  50  | 100  | 500  | 1000 |



7个字母分别代表不同的数字，用这7个字母排列组成可以组成所有的整数。

简单规则如下：

1、相同的字母或者小的字母在大字母前就是相加。III = 3   IV =6 ;

2、大的字母在小的字母前面就是想减。VI  = 4  CM = 900;

roman数字还有许多组合规则这边就不做详细介绍了，感兴趣的童鞋可以自己去找，我比较赖啦。

最后那个输入必须在1到3999之间我们不做考虑。毕竟测试交给OJ去做就可以了。

既然存在一一对应的关系首先想到的是用map容器来做。这样的话直接将7个字母对应的数字表示了出来，十分的方便。

```c++
 map<char,int> mymap;
        mymap.insert(pair<char,int>('I',1));
        mymap.insert(pair<char,int>('V',5));
        mymap.insert(pair<char,int>('X',10));
        mymap.insert(pair<char,int>('L',50));
        mymap.insert(pair<char,int>('C',100));
        mymap.insert(pair<char,int>('D',500));
        mymap.insert(pair<char,int>('M',1000));
```

将所有的对应的关系全部放入mymap中。

接下来的问题就好解决了遍历罗马数字string s;如果前面的大于或者等于后面的就相加，小于后面的就相减。

**代码**

```c++
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mymap;
        mymap.insert(pair<char,int>('I',1));
        mymap.insert(pair<char,int>('V',5));
        mymap.insert(pair<char,int>('X',10));
        mymap.insert(pair<char,int>('L',50));
        mymap.insert(pair<char,int>('C',100));
        mymap.insert(pair<char,int>('D',500));
        mymap.insert(pair<char,int>('M',1000));
        
        auto isize = s.size();
        int res = 0;
        for(int i = 0; i < isize; ++i)
            {
                if(mymap[s[i]]>=mymap[s[i+1]])
                {
                    res += mymap[s[i]];
                }
                else
                {
                    res -= mymap[s[i]];
                }
            }
        return res;
    }
};
```

*Tips*

之前提交给小马哥的代码，被小马哥说没有养成好的编码风格。虚心接受，自己感觉写代码是挺随意。思路还保留在大一的那种水平之中。这边也贴出来给大家参考一下

1. 尽量多的添加花括号，即使if后面只有一句话
2. 变量声明和定义尽量靠近使用的地方



