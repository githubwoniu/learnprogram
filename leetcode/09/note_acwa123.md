class Solution {
public:
	int pow_ten(int x)
	{
		int s=1;
		for(int i=1; i<=x; i++)
			s*=10;
		return s;
	}
    bool isPalindrome(int x) {
		if(x<0) return false;
        int n = 1;
        int xx=x;
        while(xx/10!=0)
        {
            n++;
            xx/=10;
        }
        if(n==1) return true;
        while(n>1)
        {
            int i=(x/(int)(pow_ten(n-1)));
            int j=(x%10);
            if(i!=j)    return false;
            x/=10;
            x%=(int)(pow_ten(n-2));
            n-=2;
        }
        return true;
    }
};
