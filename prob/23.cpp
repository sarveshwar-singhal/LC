#include<iostream>
#include<vector>
#include<map>
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
    ListNode* head=NULL, *top=NULL;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i, minIdx=0;
        bool elePresent = true;
        while(minIdx >= 0){
            for(i=0;i<lists.size();i++){
                if(lists[i]==NULL) continue;
                if(lists[i]->val < lists[minIdx]->val){
                    minIdx = i;
                }
            }
            // cout << "value of minIdx " << i << endl;
            insert(lists[minIdx]);
            lists[minIdx] = lists[minIdx]->next;
            minIdx = getFirstAvailIdx(lists);
        }
        return head;
    }

    void insert(ListNode* lists){
        cout << "inside insert " << endl;
        if(this->head == NULL){
            this->head = new ListNode(lists->val);
            this->top = this->head;
        } else {
            this->top->next = new ListNode(lists->val);
            this->top = this->top->next;
        }
    }

    int getFirstAvailIdx(vector<ListNode*> &lists){
        for(int i=0;i<lists.size();i++){
            if(lists[i] != NULL) return i;
        }
        return -1;
    }
};


class Solution1 {
    ListNode* head=NULL, *top=NULL;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, int> freq;
        for(ListNode* &x: lists){
            while(x!= NULL){
                freq[x->val]++;
                x = x->next;
            }
        }
        int y;
        for(pair<int, int> x: freq){
            for(y=0;y<x.second;y++){
                ListNode *n = new ListNode(x.first);
                if(top==NULL){
                    head = top = n;
                } else {
                    top->next = n;
                    top = top->next;
                }
            }
        }
        return head;
    }
};