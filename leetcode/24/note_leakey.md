## 链接


https://leetcode.com/problems/swap-nodes-in-pairs/


## 题目





## 释义






## 补充描述






## 代码






```c++

//代码放在这个块里面，可以高亮关键字
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head -> next == NULL)
            return head;
        ListNode *p1 = head, *p2 = head, *p3 = head -> next, *p4 = head -> next -> next;
        p2 -> next = p4;
        p3 -> next = p2; 
        p1 = p3;
        head = p1; //change first two nodes
        while (p2 != NULL && p3 != NULL && p4 != NULL){
        if (p3 -> next -> next -> next != NULL){
            p1 = p1 -> next;
            p2 = p2 -> next;
            p3 = p3 -> next -> next -> next;
            p4 = p4 -> next -> next;
            p1 -> next = NULL;
            p2 -> next = p4;
            p3 -> next = p2;
            p1 -> next = p3;
            p1 = p1 -> next;
        } 
        else
            break;
        }
        return head;
    }
};


```



## 更多

![](https://github.com/githubwoniu/learnprogram/blob/master/image/erweima.png)

PS: 请保留二维码链接，以便更多人参与进来。谢谢。
