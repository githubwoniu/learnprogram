## 链接

10.Regular Expression Matching(Hard)

## 题目

Implement regular expression matching with support for `'.'` and `'*'`.

```
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
```




## 方法一：回溯法

这是最容易想到的方法。

设模式串为pat，要匹配的串为str。

如果pat和str当前全是字母，那就一位位匹配即可。但这里有难点，也就是pat的字母后面可能跟\*，这个\*非常的特殊。

比如a\*，它可以匹配连续的a，也可以什么都不匹配，这是比较难的地方。接触过编译原理就会知道，这个\*对应的是epsilon串，这使得整个状态机变成不确定的，不确定状态机的后果就是需要不断回溯。回溯其实可以避免，看方法二。

因此，**假如知道当前的字符，万一它后面跟了*呢？**所以，需要**向前看一个字符**，设为ahead。

思路就出来了。设遍历pat的指针为i，遍历str的指针为j。

- 假如当前字母是单纯的字母，即后面没有跟着\*，那么就比对pat[i]和str[j]
- 假如当前是单纯的匹配单字符"."，后面没有跟着\*，那么不需要对比，i++
- 特殊情况，即单纯字母"a~z"或是匹配单字符"."后面带了个\*，那么就进入回溯模式，递归调用isMatch并且j++，isMatch能返回真，那么匹配成功，否则继续匹配
- 以上情况，若跳出循环时i和j都到了pat和str的末尾，则匹配成功

为了辨别当前字符的类型，用了查找数组patMap。

下面是代码，但还有另外一种形式即全递归的，由于两者功能相同，因此略。


```c++

//代码放在这个块里面，可以高亮关键字
class Solution {
    enum Pat
    {
        OTHER = 0,
        ALPHABET,
        DOT,
        STAR,
        END
    };
    Pat patMap[0xff] = { OTHER }; // map pattern character

public:
    Solution()
    {
        for (auto i = 'a'; i <= 'z'; i++)
        {
            patMap[i] = ALPHABET; // [a-z]
        }
        patMap['.'] = DOT; // .
        patMap['*'] = STAR; // *
        patMap['#'] = END; // #
    }

    bool isMatch(string s, string p) {
        return isMatchImpl(s.c_str(), p.c_str(), s.length(), p.length()); // add stop(look ahead)
    }

    using pstr = const char *;

    bool isMatchImpl(pstr s, pstr p, int slen, int plen) {
        if (plen == 0)
            return slen == 0;
        auto c = '$', next = p[0];
        auto pat = OTHER, nextPat = patMap[next]; // look ahead
        auto j = 0, i = 0, prev = -1;
        for (; i < plen && j <= slen;)
        {
            if (prev == i - 1)
            {
                c = next;
                pat = nextPat;
                next = i + 1 == plen ? '#' : p[i + 1];
                nextPat = patMap[next];
                prev = i;
            }
            else if (prev < i)
            {
                c = p[i];
                pat = patMap[c];
                next = i + 1 == plen ? '#' : p[i + 1];
                nextPat = patMap[next];
                prev = i;
            }
            switch (pat)
            {
            case OTHER:
                throw "invalid character";
                break;
            case ALPHABET:
                switch (nextPat)
                {
                case OTHER:
                    throw "invalid character";
                    break;
                case ALPHABET:
                case DOT:
                case END:
                    if (c != s[j])
                        return false; // [a-z] not match
                    i++; j++;
                    break;
                case STAR:
                    if (c != s[j])
                        i += 2; // [a-z]* not match, skip pattern [a-z]*
                    else
                    {
                        // [a-z]* match, got epsilon, backtracking
                        if (isMatchImpl(s + j, p + i + 2, slen - j, plen - i - 2))
                            return true;
                        j++;
                        if (j == slen)
                            i += 2;
                    }
                    break;
                default:
                    break;
                }
                break;
            case DOT:
                switch (nextPat)
                {
                case OTHER:
                    throw "invalid character";
                    break;
                case ALPHABET:
                case DOT:
                case END:
                    i++; j++; // match .
                    break;
                case STAR:
                    // got epsilon, use backtracking
                    if (i + 1 == plen)
                    {
                        return true; // .* match all
                    }
                    if (isMatchImpl(s + j, p + i + 2, slen - j, plen - i - 2))
                        return true;
                    j++;
                    if (j == slen)
                        i += 2;
                    break;
                default:
                    break;
                }
                break;
            case STAR:
                throw "invalid character"; // single *
                break;
            default:
                break;
            }
        }
        return i == plen && j == slen;
    }
};

```



## 方法二：动态规划法

由于方法一存在多余的回溯问题，因此要避免回溯，采用DP方法。

DP方法的优点：不需要递归（不复制string），思路清晰，由状态转移方程推导出（先逻辑验证，不易出错），效率高，其结果是简化的状态机

DP方法的缺点：推导过程复杂

二维DP的一般步骤：

1. 两个相关变量的表述，须为数字，这里是原串和模式串的长度，同时也决定了dp表的大小以及算法的复杂度
2. dp表的值类型，这里是bool
3. 根据题意总结规则
4. 根据规则写出详尽的状态转移方程
5. 在双重for循环中实现状态转移
6. 返回dp表的最右下值

设模式串为pat，要匹配的串为str。因此dp数组的大小是(patlen+1) x (strlen+1)，大小为子串的长度。

推导规则：

1. 空串匹配空串：dp(0,0)=true 
2. '.\*'组合匹配空串：消除'.\*'并匹配，dp(0,j)=dp(0,j-2)
3. '.\*'或'a\*'匹配：看上次结果dp(i-1,j)，若真则真；若假则看dp(i,j-2)
4. 'a\*'匹配：看上次结果dp(i-1,j)，若真则比较最新匹配位s(i-1)=p(j-2)；若假则看dp(i,j-2)
5. 非'\*'匹配空串：dp(0,j)=false
6. '.'匹配：看上次结果dp(i-1,j-1)
7. 'a'：看上次结果dp(i-1,j-1)，同时比较最新匹配位s(i-1)=p(j-1)

代码如下，耗时是回溯法的1/3左右。


```c++

//代码放在这个块里面，可以高亮关键字
class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length(), plen = p.length();
        // dp[i,j] -> str[0..i-1] 是否被 pat[0..j-1] 匹配
        vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
        // 二重循环构建dp数组，按部就班
        // dp[i,j] -> pat[0..j-1] matches str[0..i-1]
        dp[0][0] = true; // empty matches empty
        for (auto i = 0; i <= slen; i++)
        {
            // 这里省略了j从0开始的部分，因为pat为空时，除非str为空否则匹配失败
            for (auto j = 1; j <= plen; j++)
            {
                if (p[j - 1] == '*') // '*'不应该在第一位，因此j>1
                {
                    // 当前为'*'，这里情况稍显复杂
                    if (p[j - 2] == '.')
                    {
                        if (i > 0 && dp[i - 1][j])
                            // '.*' matches 'abc' => '.*' == 'ab'
                            dp[i][j] = true;
                        if (!dp[i][j]) // else
                            // 'a.*' matches 'ab' => 'a.*' == 'a'
                            dp[i][j] = dp[i][j - 2];;
                    }
                    else
                    {
                        if (i > 0 && dp[i - 1][j])
                            // 'a*' matches 'aa' => 'a*' == 'a' && 'a' == 'a'
                            dp[i][j] = s[i - 1] == p[j - 2];
                        if (!dp[i][j]) // else
                            // 'ab*' matches 'a' => 'a' == 'a'
                            dp[i][j] = dp[i][j - 2];;
                    }
                }
                else
                {
                    // 当前pat[i]是[a-z]或者'.'，则单字符匹配
                    if (i == 0)
                        // 非空模式串不能匹配空串
                        dp[0][j] = false;
                    else
                    {
                        if (p[j - 1] == '.')
                        {
                            // 当前为'.'
                            // 'a.' matches 'aa' => 'a' == 'a'
                            dp[i][j] = dp[i - 1][j - 1];
                        }
                        else
                        {
                            // 当前为[a-z]
                            // 'ab' matches 'ab' => 'a' == 'a' && 'b' == 'b'
                            dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
                        }
                    }
                }
            }
        }
        return dp[slen][plen];
    }
};
```


## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。