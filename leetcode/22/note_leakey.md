## 链接

【中等难度】22. Generate Parentheses（生成括号）

https://leetcode.com/problems/generate-parentheses/


## 题目

Given *n* pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given *n* = 3, a solution set is:

```
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
```

*Tags: Backtracking*

## 释义






## 补充描述
A python solution:
```python
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        B = [i for i in xrange(n)]
        p = ""
        for k in xrange(0, 2 * n):
            p += "(" if k in B else ")"
        A = [p]
        j = i = n - 1
        while True:
            if B[j] != 2 * j: # adjustment b
                B[j] += 1
            else:
                while j != 0:
                    j -= 1
                    if B[j] != 2 * j:
                        B[j] += 1
                        for m in xrange(j + 1, n):
                            B[m] = B[m - 1] + 1
                        j = n - 1
                        break
                if j <= 0:
                    return A
            p = "" 
            for k in xrange(0, 2 * n):
                p += "(" if k in B else ")"
        A.append(p)

```





## 代码






```c++

class Solution { 
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parenTable;
        if (n == 0)
            return parenTable;
        string s;
        int pl = n, pr = n;
        for (int i = 0; i < n; i++) s += "(";
        for (int i = 0; i < n; i++) s += ")";  //s = "(((...()...)))"
        while (s != ""){
            parenTable.push_back(s);
            while (s != "" && (s.back() == ')' || pl - 1 <  pr + 1)){
                s.back() == ')' ? pr-- : pl --;
                s.pop_back();
            }
            if (s != ""){
                s.back() = ')';
                pl--, pr++;
                while (pl < n){
                    s += '(';
                    pl++;
                }
                while (pr < n){
                    s += ')';
                    pr++;
                }
            }
        }
        return parenTable;
    }
};



```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
