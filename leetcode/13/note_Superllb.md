#### 考虑到最后一个字符没有比较对象，将其对应的整数直接相加，得到最终结果。

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int strLen = s.size();
        
        if (!s.empty()) 
        	cout << "Please input a roman number！" << endl;
        
        for (int i = 0; i < strLen-1; i++) {
        	if (getVal(s[i]) >= getVal(s[i + 1])) {
        		sum += getVal(s[i]);
        	}
        	else {
        		sum -= getVal(s[i]);
        	}
        }
        sum += getVal(s[strLen-1]);
        return sum;
        }
    
        int getVal(char c) {
    	switch (c) {
    		case 'I': return 1;
    		case 'V': return 5;
    		case 'X': return 10;
    		case 'L': return 50;
    		case 'C': return 100;
    		case 'D': return 500;
    		case 'M': return 1000;
    
    		default:return 0;
    		break;
    	} 
    }
};
```
