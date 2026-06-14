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
    int pairSum(ListNode* head) {
        vector<int>v;
        ListNode* temp=head;
        while(temp!=nullptr){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int low=0;
        int high=v.size()-1;
        int maxsum=-1;
        while(low<high){
            int sum=v[low]+v[high];
            maxsum=max(maxsum,sum);
            low++;
            high--;
        }
        return maxsum;
    }
};