#include<iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode *head=NULL, *top=NULL;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i, minIdx=0;
        bool elePresent = true;
        while(elePresent){
            // minIdx = 0;
            for(i=0;i<=lists.size();i++){
                if(lists[i]==NULL) continue;
                if(lists[i]->val < lists[minIdx]->val){
                    minIdx = i;
                }
            }
            insert(lists[i]);

        }
    }

    void insert(ListNode* &lists){
        if(this->head == NULL){
            head = new ListNode(lists->val);
            top = head;
        } else {
            top->next = new ListNode(lists->val);
        }
    }
};