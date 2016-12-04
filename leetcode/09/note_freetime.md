```
bool isPalindrome(int x) {
    int temp, new_num;
    temp = x;
    new_num = 0;
    if(x < 0)
    {
        return 0;
    }
    else
    {
        while(temp!=0)
        {
            new_num *= 10;
            new_num += temp%10;
            temp /= 10;
        }
        if(new_num == x)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
```
