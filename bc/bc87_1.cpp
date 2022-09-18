#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int p1, p2;
        p1 = 0; p2 = 0;
        int i=0, j=0;
        while(i<players.size() && j<trainers.size()){
            if(players[i]<=trainers[j]){
                p1+=1;
                i+=1;
                j+=1;
            } else{
                j+=1;
            }
        }
        return p1;
    }
};