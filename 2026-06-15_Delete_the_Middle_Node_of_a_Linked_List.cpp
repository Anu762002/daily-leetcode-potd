#include<bits/stdc++.h>
using namespace std;

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp=head;
        if(head->next==nullptr) return nullptr;
        int cnt=0;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        int k=cnt/2 +1;
        temp=head;
        ListNode* prev=nullptr;
        while(--k){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        temp->next=nullptr;
        delete(temp);
        return head;
    }
};