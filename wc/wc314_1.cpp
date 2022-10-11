#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int i, j;
        int mdiff = logs[0][1];
        int midx = logs[0][0];
        for(i=1;i<logs.size();i++){
            if(mdiff < logs[i][1] - logs[i-1][1]){
                mdiff = logs[i][1] - logs[i-1][1];
                midx = logs[i][0];
            }else if(mdiff == logs[i][1] - logs[i-1][1]){
                midx = min(logs[i][0], midx);
            }
        }
        return midx;
    }
};