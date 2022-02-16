/**
  * This question is asked by Apple. Given two sorted linked lists, merge them together in ascending order and return a reference to the merged list
  *
  * Ex: Given the following lists...
  * 
  * list1 = 1->2->3, list2 = 4->5->6->null, return 1->2->3->4->5->6->null
  * list1 = 1->3->5, list2 = 2->4->6->null, return 1->2->3->4->5->6->null
  * list1 = 4->4->7, list2 = 1->5->6->null, return 1->4->4->5->6->7->null
  *
  */
// Question: https://leetcode.com/problems/merge-two-sorted-lists
// Solution:

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr && list2 == nullptr){
        return list1;
    }
    if(list1 == nullptr){
        return list2;
    }
    if(list2 == nullptr){
        return list1;
    }

    ListNode* head = nullptr;
    if(list1->val < list2->val){
        head = list1;
        list1 = list1->next;
    }else{
        head = list2;
        list2 = list2->next;
    }

    ListNode* head_ref = head;
    while(list1 != nullptr && list2 != nullptr){
        if(list1->val < list2->val){
            head_ref->next = list1;
            list1 = list1->next;    
        }else{
            head_ref->next = list2;
            list2 = list2->next;
        }
        head_ref = head_ref->next;
    }

    if(list1 == nullptr){
        list1 = list2;
    }
        head_ref->next = list1;
    return head;
}
