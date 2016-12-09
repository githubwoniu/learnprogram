```cpp
class Solution {
public:
    
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        bool result = false;
        
        string str = to_string(x);
        string str2(str);
        reverse(str.begin(),str.end());
        
        if(str == str2) result = true;
        
        return result;
    }
};
```
