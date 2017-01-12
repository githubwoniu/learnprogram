## 链接


https://leetcode.com/problems/swap-nodes-in-pairs/


## 解题思路

首先，建了一个虚假头，这样可以统一操作。
建立两个指针pre,p;pre指向p的前面一个结点。
然后每两个指针，进行一次操作。

注意：结点个数为奇数的特例。




## 代码


```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
	public:
	ListNode* swapPairs(ListNode* head)
	{
		ListNode* dumpHead = new ListNode(100);
		dumpHead->next = head;

		ListNode* p = head;
		ListNode* pre = dumpHead;

		while(p)
		{
			//处理奇数结点的情况
			if(p->next == NULL)
			{
				ListNode* tem = dumpHead->next;
				delete dumpHead;
				return tem;
			}
			pre->next = p->next;
			p->next = p->next->next;
			pre->next->next = p;
			pre = p;
			p = p->next;
		}

		ListNode* tem = dumpHead->next;
		delete dumpHead;
		return tem;
	}
};
```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
