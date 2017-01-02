## 链接

[https://leetcode.com/problems/longest-common-prefix/](https://leetcode.com/problems/longest-common-prefix/)

## 题目

题目是要求出一个string序列中，所有字符串共有的前缀。

比如 ["aa", "ab"], 那么结果就是"a"

## 释义

N.A.

## 补充描述

开始写代码之前可以先设计一些测试用例

### 集合长度

```
["aa"]-->""
[]-->""
```

### 集合内容

```
["aa", "ab"]-->"a"
["aaa", "aab"]-->"aa"
["aa", "bb"]-->""
```

## 代码

比较容易想到的是遍历第一个string中的字符，确认后序string中是否也包含这些字符

```c++
string longestCommonPrefix(vector<string>& strs)
{
    if( !strs.size() )
    {
        return "";
    }
    
    if( strs.size() ==1 )
    {
        return strs.at(0);
    }
    
    string sFirst = strs.at(0);

    for( int i = 0; i < sFirst.size(); ++i)
    {
        for( int j = 1; j < strs.size(); ++j )
        {
            string sTemp = strs.at(j);
            if( sTemp.size() <= i || sTemp[i] != sFirst[i] )
            {
                return i == 0 ? "" : sFirst.substr(0, i);
            }
        }

    }
    
    return sFirst;
}
```

运行之后是13ms，查看细节会发现大部分人的解题时间都控制在了10ms以内。

我们需要再看一下哪里能省出些时间来

`size()`操作进行了多次，缓存起来试一下? **大神帮忙解答下这里有必要吗？**

循环内部取到`strs.at(j)`是没必要缓存的，顺序容器的下标操作都是常量级的。

同样的，sFirst我们也不缓存了

```c++
string longestCommonPrefix(vector<string>& strs) 
{
    auto vecSize = strs.size();
    
    if( !vecSize )
    {
        return "";
    }
    
    if( vecSize ==1 )
    {
        return strs.at(0);
    }
    

    for( int i = 0; i < strs.at(0).size(); ++i)
    {
        for( int j = 1; j < vecSize; ++j )
        {
            if( strs.at(j).size() <= i || strs.at(j)[i] != strs.at(0)[i] )
            {
                return i == 0 ? "" : strs.at(0).substr(0, i);
            }
        }

    }
    
    return strs.at(0);
}

```

6ms，只能击败17.75%。因为大多数人都在6ms

自己想不出哪里可以优化了，来和高票答案对比一下

[https://discuss.leetcode.com/topic/20991/accepted-c-6-lines-4ms/2](https://discuss.leetcode.com/topic/20991/accepted-c-6-lines-4ms/2)

主要的一个区别应该是在substr上，我们也用他的方式来试下

```
string longestCommonPrefix(vector<string>& strs) {
    auto vecSize = strs.size();
    
    if( !vecSize )
    {
        return "";
    }
    
    string sPrefix = "";
    for( int i = 0; i < strs.at(0).size(); ++i)
    {
        for( int j = 1; j < vecSize; ++j )
        {
            if( strs.at(j).size() <= i || strs.at(j)[i] != strs.at(0)[i] )
            {
                return sPrefix;
            }
        }
        sPrefix += strs.at(0)[i];
    }
    
    return strs.at(0);
}
```

还是6ms，再改的话代码可读性就变差了。

果然大神是无法靠近的。。。就这样吧。。。

## 更多

我们用新学的`string.find`练练手

```c++
string longestCommonPrefix(vector<string>& strs) {
    auto vecSize = strs.size();
    
    if( !vecSize )
    {
        return "";
    }
    
    string sPrefix = "";
    for( int i = 0; i < strs.at(0).size(); ++i)
    {
        sPrefix += strs.at(0)[i];
        for( int j = 1; j < vecSize; ++j )
        {
            if( strs.at(j).find(sPrefix) != 0 )
            {
                return sPrefix.erase(i,1);
            }
        }
    }
    
    return strs.at(0);
}
```
