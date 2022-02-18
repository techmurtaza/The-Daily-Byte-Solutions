/**
  * This question is asked by Facebook. Given a linked list and a value n, remove the nth to last node and return the resulting list.
  *
  * Ex: Given the following linked lists...
  * 
  * 1->2->3->null, n = 1, return 1->2->null
  * 1->2->3->null, n = 2, return 1->3->null
  * 1->2->3->null, n = 3, return 2->3->null
  *
  */
// Question: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Solution:    
    //Single Pass Solution
ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode* head_fast = head, *head_slow = head;

    while(n && head_fast->next != nullptr){
        head_fast = head_fast->next;
        n--;
    }

    while( head_fast != nullptr && head_fast->next != nullptr){
        head_fast = head_fast->next;
        head_slow = head_slow->next;
    }

    if(head_slow->next != nullptr && (head_slow != head || !n)){
        head_slow->next = head_slow->next->next;
    }else{
        head = head_slow->next;
    }

    return head;
}
