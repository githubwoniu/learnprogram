#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x)
	{
		string beforeNum,upsiteDownNum;
		stringstream ss;
		ss << x;
		ss>>beforeNum;
		ss.clear();

		for (auto iter=beforeNum.rbegin();iter!=beforeNum.rend();++iter)
		{
			upsiteDownNum.push_back(*iter);
		}

		if (beforeNum==upsiteDownNum)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	Solution temp;
	bool b=temp.isPalindrome(1234321);

	return 0;
}
