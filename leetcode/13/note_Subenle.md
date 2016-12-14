/*
	罗马数字共有7个，即I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000）
*/
class Solution {
public:
/*
    本解法从后往前遍历字符串，如果rst初始为最后一个字符的值，如果前一个字符的值>=当前字符
    的值，则 rst += 前一个字符的值；否则，rst -= 前一个字符的值。
*/
    int romanToInt1(string s) {
    	int len=s.length();
        if (len == 0) return 0; 
        //用map来保存罗马符号和相应数字
        map<char,int> roman_map;
        roman_map['I'] = 1;
        roman_map['V'] = 5;
        roman_map['X'] = 10;
        roman_map['L'] = 50;
        roman_map['C'] = 100;
        roman_map['D'] = 500;
        roman_map['M'] = 1000;
        
        int rst = roman_map[s[len - 1]];
        for(int i = len - 2; i >= 0; i--){
            if(roman_map[s[i]] >= roman_map[s[i+1]]){
                rst += roman_map[s[i]];
            }
            else{
                rst -= roman_map[s[i]];
            }
        }
        return rst;
    }
/*
    本解法从前往后遍历字符串，如果后一个字符的值>当前字符的值，则 rst -= 当前字符的值；
    否则，rst += 当前字符的值。
*/
    int romanToInt(string s) {
    	int len=s.length();
        if (len == 0) return 0; 
        //用map来保存罗马符号和相应数字
        map<char,int> roman_map;
        roman_map['I'] = 1;
        roman_map['V'] = 5;
        roman_map['X'] = 10;
        roman_map['L'] = 50;
        roman_map['C'] = 100;
        roman_map['D'] = 500;
        roman_map['M'] = 1000;
        
        int rst = 0;
        for(int i = 0; i < len -1; i++){
            if(roman_map[s[i + 1]] > roman_map[s[i]]){
                rst -= roman_map[s[i]];
            }
            else{
                rst += roman_map[s[i]];
            }
        }
        return rst + roman_map[s[len -1]];
    }    
    
};
