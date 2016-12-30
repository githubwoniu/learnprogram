## 链接


https://leetcode.com/problems/swap-nodes-in-pairs/


## 解题思路

1. 找到要交换的前驱就行。




## 代码






```c++
//借鉴别人的代码
ListNode* swapPairs(ListNode* head) {
	if (!head  || !head->next) return head;
	ListNode tempNode(0);
	ListNode *helper = &tempNode;
	ListNode *ret = head;
	ListNode *cur = helper;
	while (ret  && ret->next) {
		ListNode *next = ret->next->next;
		cur->next = ret->next;
		cur = cur->next;
		cur->next = ret;
		cur = cur->next;
		cur->next = nullptr;
		ret = next;
	}
	if (ret) cur->next = ret;
	return helper->next;
}
```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。