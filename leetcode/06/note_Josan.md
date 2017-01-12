## 链接


https://leetcode.com/problems/zigzag-conversion/


## 题目

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

```c++
class Solution {
public:
    string convert(string s, int numRows) {
        
    }
};
```

## 释义






## 补充描述

一开始认为题目很简单，但是实际操作起来，发现自己的思路实现起来并没有那么简单。似乎这种感觉经常会出现。所以，不能眼高手低，一定要实现出来，绝不能想当然。
思路：
首先，将zigzag图案的每行的列数算出来；如下，

```c++
P   A   H   N  …………………………………………  col[0]=4
A P L S I I G   …………………………………………  col[1]=7
Y   I   R       …………………………………………  col[2]=3
```

然后计算结果res；依次从每行开始遍历，然后对于每行的每一列进行遍历，运用相应的行列对应公式就可以得出结果。
总评：对应公式比较复杂，期间调试很久。这真是一个糟糕的算法。


## 自己的收获

对边界条件（Boundary Conditions）加深理解


自己写的程序，一开始没有考虑边界条件。总是，直接提交，然后再看通不过的测试案例，然后再修改。虽然最后也能通过，但是在CCF认证考试，浙大的PAT考试，找工作的机试都是只能提交代码的。偶尔的系统还会告诉你，这个程序有没有全部通过测试案例，但是几乎全不会像LeetCode这么人性化还给你错误的案例。因此，必须对此加以重视，否则要找不到工作的节奏。
总结一下：这次犯的错误。
边界条件，主要就是对输入的把控。


如果程序中，有除法运算，一定要记得考虑是否除数为0的情况。


对于string，考虑size()为0的情况。对于int，考虑为0  以及正负数的情况。


本题，没有考虑到负数的情况，说明我的程序还是有漏洞的，需要重视。别人的程序就有考虑。


对于string部分的初始化、size以及capacity理解更深。

```C++
string a(10);            //no exist such initialization    but vector<int> a(10) is okay
string a(10,’\0’)      //but you can do like this
对于一个string a;需要时刻考虑他的size以及capacity。
eg:    string a;
       a.reserve(10);   //PS: reserve()的效果是只增不减
       a[6]=’x’;    //就是会报错的，reserve只是改变了capacity,而不是size
```


## 代码

分享一个连我自己都觉得呕心的代码。





```c++

//代码放在这个块里面，可以高亮关键字

class Solution
{
	public:
	string convert(string s, int numRows)
	{
		if (s.size() == 0)
		{
			return string();
		}
		else if (numRows == 1)
		{
			return string(s.begin(), s.end());
		}
		
		int sz = s.size();
		string res(sz,'\0');

		vector<int> col(numRows, 0);

		

		col[ 0 ] = ( sz - 1 ) / ( (numRows << 1) - 2 ) + 1;

		for (int i = 1; i < numRows - 1; ++i)
		{
			if (sz - ( ( numRows - 1 )*(( col[ 0 ] - 1 ) << 1) + 1 + i ) < 0)
			{
				col[ i ] = (col[ 0 ]-1) << 1;
			} 
			else if (sz - ( ( numRows - 1 )*(( col[ 0 ] - 1 ) << 1) + (numRows << 1) - i - 1 ) < 0)
			{
				col[ i ] = (col[ 0 ] << 1) - 1;
			}
			else
			{
				col[ i ] = col[ 0 ]<< 1;
			}
		}

		//compute col[numRows-1]
		if (sz - ( ( numRows - 1 )*(( col[ 0 ] - 1 ) << 1) + numRows  ) < 0)
		{
			col[ numRows - 1 ] = col[ 0 ] - 1;
		}
		else
		{
			col[ numRows - 1 ] = col[ 0 ];
		}


		for (int index = 0, i = 0; i < numRows&&index != sz; ++i)
		{
			if (i == 0 || i == numRows - 1)
			{
				for (int j = 0; j != col[ i ]; ++j)
				{
		
					res[ index++ ] = s[ ( ( ( numRows - 1 )*j ) << 1 ) + i ];
				}
			}
			else
			{
				for (int j = 0; j != col[ i ]; ++j)
				{
					if (j % 2 == 0)
					{
						res[ index++ ] = s[ ( j >> 1 )*( ( numRows - 1 ) << 1 ) + i ];
					}
					else
					{
						res[ index++ ] = s[ ( j >> 1 )*( ( numRows - 1 ) << 1 ) + ( numRows << 1 ) - i - 2 ];
					}
				}
			}
		}
		return res;
	}
};
```


## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
