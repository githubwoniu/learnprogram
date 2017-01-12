## 链接

【中等难度】12. Integer to Roman（数字转罗马文）

https://leetcode.com/problems/integer-to-roman/


## 题目

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

*Tags: Hash Table or Syntax-directed Translation(Advanced)*

## 释义

题目很直白，就是数字转罗马数字
## 补充描述


使用了辅助数组进行求解。当然这个辅助数组具有一定的特征，可以使用函数进行求解。然而，我们一般还是用空间来换时间。
这里使用了一个特征，就是789——对应罗马数字的（7【百位】+8【十位】+9【个位】）。




## 代码






```c++


//辅助数组
string str[4][10] = {
	{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
	{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
	{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
	{ "", "M", "MM", "MMM" }
};

class Solution
{
	public:
	string intToRoman(int num)
	{
		if(num <= 0 || num > 3999)  return string();

		string res;
    //这样提前分配空间可以适当优化时间		
    res.reserve(200);

		stack<int> st;
    
		int digits = 0;//digits表示num的位数		
    while(num)
		{
			st.push(num % 10);
			num /= 10;
			++digits;
		}
		while(!st.empty())
		{
			int temp = st.top();
			res += str[--digits][temp];
			st.pop();
		}
		return res;
	}
};

```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
