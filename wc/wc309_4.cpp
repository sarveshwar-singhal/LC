#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> lastTime(n, 0);
        vector<int> freq(n, 0);
        sort(meetings.begin(), meetings.end());
        int i;
        int pos_min, pos, val_min;
        for(auto x: meetings){
            val_min = INT32_MAX;
            //value minimum
            for(i=0;i<lastTime.size();i++){
                if(x[0]>=lastTime[i]){
                    val_min = i;
                    break;
                }
            }
            //pos min
            pos = -1;
            pos_min = INT32_MAX;
            for(i=0;i<lastTime.size();i++){
                if(pos_min > lastTime[i]){
                    pos_min = lastTime[i];
                    pos = i;
                }
            }
            pos = min(pos, val_min);
            if(lastTime[pos] == 0){
                lastTime[pos] = x[1];
            } else{
                if(x[0] >= lastTime[pos]){
                    lastTime[pos] = x[1];
                } else{
                    lastTime[pos] += x[1] - x[0];
                }
            }
            freq[pos] +=1;
        }
        pos = -1;
        int maxi = INT32_MIN;
        for(i=0;i<freq.size();i++){
            if(maxi < freq[i]){
                maxi = freq[i];
                pos = i;
            }
        }
        return pos;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> meetings = {{0,10},{1,5},{2,7},{3,4}};
    int n;
    n=3;
    meetings = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};
    // meetings = {{0, 10}, {1, 2}, {12, 14}, {13, 15}};
    // meetings = {{18, 19}, {3, 12}, {17, 19}, {2, 13}, {7, 10}};
    Solution s1;
    cout << s1.mostBooked(n, meetings) << endl;
    return 0;
}


void rough(){
    /*  for(i=0;i<lastTime.size();i++){
        if(mini > lastTime[i] && x[0] >= lastTime[i]){
            mini = lastTime[i];
            pos = i;
        }
    }   */
}