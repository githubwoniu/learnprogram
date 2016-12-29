## 链接


https://leetcode.com/problems/merge-two-sorted-lists/


## 题目





## 释义






## 补充描述






## 代码






```c++

//代码放在这个块里面，可以高亮关键字
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2, *p, *head;
            if (p1 == NULL)
        return l2;
    else if (p2 == NULL)
        return l1;
    if (p1 -> val <= p2 -> val){
        head = p1;
        p1 = p1 -> next;
    }// first node same with smaller one
    else{
        head = p2;
        p2 = p2 -> next;
    }
    p = head;
    while (p1 != NULL || p2 != NULL){
        if (p1 == NULL){
            p -> next = p2;
            p2 = p2 -> next;
        } // if l1 ends
        else if (p2 == NULL){
            p -> next = p1;
            p1 = p1 -> next;
        }
        else if (p1 -> val <= p2 -> val){
            p -> next = p1;
            p1 = p1 -> next;
        }
        else{
            p -> next = p2;
            p2 = p2 -> next;
        }
        p = p -> next; // p move to the next node
    }
    return head;
    }
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
