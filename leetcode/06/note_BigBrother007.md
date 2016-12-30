## 链接


https://leetcode.com/problems/zigzag-conversion/


## 题目





## 释义






## 补充描述






## 代码






```c++

//代码放在这个块里面，可以高亮关键字
string result;
        vector<string> svec(numRows);
        int length = s.length();
        if(numRows == 1)
            return s;
        for (int i = 0; i < length ; ++i)
        {
            //这个公式有点二，把i 一次变换为 0, 1, ... numRows-1, numRows-2, ... 0, ...
            int j = abs(abs(i % (2 * numRows - 2)- numRows + 1) - numRows + 1);
            svec[j] += s[i];
        }
        for (int i = 0; i < numRows; ++i)
        {
            result += svec[i];
        }
        return result;


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
