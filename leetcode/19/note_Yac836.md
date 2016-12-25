## 链接


https://leetcode.com/problems/remove-nth-node-from-end-of-list/


## 解题思路

1. 遍历求出链表长度
2. 找出要删除的元素的前一个位置
3. 删除元素

***注意***

1. 要删除元素为第一个位置时，返回值问题。






## 代码






```c++
ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *begin = head;
	int len = 1;
	while (begin->next != nullptr) {
		len++;
		begin = begin->next;
	}
	if (len == n)
		return head->next;
	int remove = len - n;
	begin = head;
	len = 1;
	while (len < remove) {
		begin = begin->next;
		len++;
	}
	begin->next = begin->next->next;
	return head;
}
```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。