## 链接


https://leetcode.com/problems/valid-parentheses/

## 解题思路

典型的stack的符号配对问题。

注意一些特殊的测试用例就好
()(   )    ()()    [


## 代码

```c++
class Solution {
public:
	bool isValid(string s) {
		if(s.size( ) == 0)
		{
			return false;
		}
		stack<char>  st;
		int i = 0;
		//加入@主要是为了当stack为空时，以防出现取st.top()的报错
		//相应测试用例，eg:  )
		st.push('@');
		while(!st.empty( )&&i!=s.size()){
			switch(s[i]){
			case '(':
			case '[':
			case '{':
				st.push(s[i++]); 
				break;
			case ')':
				if(st.top( ) != '('){
					return false;
				}
				else{
					st.pop( );
					++i;
				}
				break;
			case ']':
				if(st.top( ) != '['){
					return false;
				}
				else{
					st.pop( );
					++i;
				}
				break;
			case '}':
				if(st.top( ) != '{'){
					return false;
				}
				else{
					st.pop( );
					++i;
				}
				break;
			//出现其他无效字符
			default: return false;
			}
		}
		return (st.size( ) == 1) ? true : false;
	}
};
```

上面的程序比较繁琐，而且对case ]})的案例无法进行统一

可以参考这个改进版
```c++
class Solution {
public:
	bool isValid(string s){
		//suppose null string is illegal
		if(s.size( ) == 0){
			return false;
		}
		stack<char> st;
		map<char, char> cm{ {')','(' },{']','[' },{'}','{' } };
		for(int i = 0; i != s.size( ); ++i){
			switch(s[i]){
			case '(':
			case '[':
			case '{':
				st.push(s[i]);
				break;
			case ')':
			case ']':
			case '}':
				if(st.empty( ) || st.top( ) != cm[s[i]]){
					return false;
				}
				else{
					st.pop( );
					break;
				}
			//if illegal character appears, like @ # $ % a ... , return false
			default:
				return false;
			}
		}
		return st.empty( );
	}
};
```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
