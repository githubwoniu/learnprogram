## 链接


https://leetcode.com/problems/remove-nth-node-from-end-of-list/


## 题目





## 释义






## 补充描述






## 代码






```c++

//代码放在这个块里面，可以高亮关键字
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fp = head, *sp = head; //use two pointers
        for (int i = 0; i < n; i++)
            fp = fp -> next;
        if (fp == NULL)
            return head -> next;
        while (fp -> next != NULL){
            fp = fp -> next;
            sp = sp -> next;
        }
        sp -> next = sp -> next -> next;
        return head;
    }
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
