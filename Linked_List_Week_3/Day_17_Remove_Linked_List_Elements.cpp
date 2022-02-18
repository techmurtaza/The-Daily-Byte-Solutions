/**
  * This question is asked by Google. Given a linked list and a value, remove all nodes containing the provided value, and return the resulting list.
  *
  * Ex: Given the following linked lists...
  * 
  * 1->2->3->null, value = 3, return 1->2->null
  * 8->1->1->4->12->null, value = 1, return 8->4->12->null
  * 7->12->2->9->null, value = 7, return 12->2->9->null
  *
  */
// Question: https://leetcode.com/problems/remove-linked-list-elements/
// Solution:

ListNode* removeElements(ListNode* head, int val) {
  
  while(head && head->val == val){
      head = head->next;
  }

  ListNode* head_ref = head;
  while(head_ref && head_ref->next){
      if(head_ref->next->val == val){
          head_ref->next = head_ref->next->next;
          continue;
      }
      head_ref = head_ref->next;
  }
  return head;
}
