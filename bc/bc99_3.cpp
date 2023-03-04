#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

class Solution{

public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        vector<pair<int, int>> dist;
        int prev = -1, i, mx=1;
        for(i=0;i<ranges.size();i++){
            if(prev >= ranges[i][0]){
                prev = max(prev, ranges[i][1]);
                // ranges.back()[1] = prev;
                dist.back().second = prev;
            } else {
                dist.push_back({ranges[i][0], ranges[i][1]});
                prev = dist.back().second;
            }
        }
        mx=1;
        for(i=0;i<dist.size();i++){
            mx = mx*2;
            mx %= 1000000007;
        }
        return mx;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> arr = {{6,10},{5,15}};
    arr = {{1,3},{10,20},{2,5},{4,8}};
    cout << s1.countWays(arr) << endl;
    return 0;
}