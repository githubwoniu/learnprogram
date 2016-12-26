## 链接


https://leetcode.com/problems/merge-two-sorted-lists/


## 解题思路

1. 先新建一个节点tres，指向两个链表中最小的。
2. 再新建一个节点res，使它指向tres,用于保存结果。
3. 然后一次比较两个链表中的元素，使tres指向其中较小元素，然后后移tres，使它指向它的下一个




## 代码






```c++
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (!l1 && !l2)
		return  nullptr;
	if (!l1)
		return l2;
	if (!l2)
		return l1;
	ListNode* tres;
	if (l1->val < l2->val) {
		tres = l1;
		l1 = l1->next;
	}
	else {
		tres = l2;
		l2 = l2->next;
	}
	ListNode* res = tres;
	while (l1&&l2) {
		if (l1->val < l2->val) {
			tres->next = l1;
			l1 = l1->next;
		}
		else {
			tres->next = l2;
			l2 = l2->next;
		}
		tres = tres->next;
	}
	if (l1)
		tres->next = l1;
	if (l2)
		tres->next = l2;
	return res;
}


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。