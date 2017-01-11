## 链接


https://leetcode.com/problems/remove-nth-node-from-end-of-list/


## 解题思路

1. 先遍历一个pre，作为侦探兵。
2. 一次遍历，只要pre为NULL，就可以找出要删除的元素的前一个位置，即为res。
3. 删除元素

***注意***

要删除元素为第一个位置时，返回值问题。



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
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		if (n < 0||head==NULL||head->next==NULL) return NULL;
		
		//pre表示从head开始遍历第n个结点，意思就是pre在res之前n+1个结点
		//那么当pre指向NULL时，res正好是倒数第n个结点的前置结点。
		ListNode* pre = head;
		while (n&&pre)
		{
			pre = pre->next;
			--n;
		}
		
		//n!=0表示n的大于链表的长度，报错
		if(n!=0)  return NULL;
		
		//flag用来标识是否删除的是头指针，如果是，则为true
		bool flag = (n == 0 && pre == NULL);
		ListNode* dumpHead = new ListNode(0);
		dumpHead->next = head;
		ListNode* res = dumpHead;
		while (pre)
		{
			pre = pre->next;
			res = res->next;
		}
		//删除
		res->next = res->next->next;
		if (flag) head = res->next;
		delete dumpHead;
		return head;
	}
};

```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
