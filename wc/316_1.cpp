#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int t1s, t1e, t2s, t2e;
        t1s = stoi(event1[0].substr(0, 2))*60 + stoi(event1[0].substr(3, 2));
        t1e = stoi(event1[1].substr(0, 2))*60 + stoi(event1[1].substr(3, 2));
        t2s = stoi(event2[0].substr(0, 2))*60 + stoi(event2[0].substr(3, 2));
        t2e = stoi(event2[1].substr(0, 2))*60 + stoi(event2[1].substr(3, 2));
        
    }
};