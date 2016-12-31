## 链接


https://leetcode.com/problems/zigzag-conversion/


## 题目





## 释义






## 补充描述
Another python solution:
```python
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        lens = len(s)
        if lens <= numRows or numRows <= 1:
            return s
        else:
            strre = ""
            lenstr = (numRows - 1) * 2
            i = j = k = m = 0
            lenstrre = 0
            while lenstrre < lens:
                strre = strre + s[j]
                lenstrre += 1
                if not j % (lenstr / 2):
                    j += lenstr
                else:
                    m += 1
                    k = lenstr - j if m == 1 else lenstr + k
                    if k >= lens:
                        i += 1
                        j = i
                        m = 0
                    else:
                        strre = strre + s[k]
                        lenstrre += 1
                        j += lenstr
                if j >= lens:
                    i += 1
                    j = i
                    m = 0
        return strre
```





## 代码






```c++

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= s.length())
            return s;
        string result = "";
        int maxStep = numRows * 2 - 2;
        for (int i = 1; i <= numRows; i++){
            int j = i - 1;
            int step = (i < numRows) ? (numRows - i) * 2 : maxStep;
            while (j < s.length()) {
                result += s[j];
                if (result.length() == s.length())
                    return result;
                j += step;
                if (step < maxStep) {
                    step = maxStep - step;
                }
            }
        }
        return result;
    }
};



```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
