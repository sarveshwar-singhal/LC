#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int i, cnt, k=0;
        bool found = true;
        while(found){
            cnt = h;
            k += 1;
            found = false;
            for(i=piles.size()-1;i>=0;i--){
                cnt -= piles[i]/k + (piles[i]%k==0? 0 : 1) ;
                // cout << ceil(piles[i]/k) << endl;
                if(cnt<0){
                    found = true;
                    break;
                }
            }
        }
        return k;
    }

    //throwing TLE on 114/123 test case
    //converting to (int) improved 1 more test case. Issue with floating point division error.
    int minEatingSpeed1(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int i, cnt;
        float k=0.0;
        bool found = true;
        while(found){
            cnt = h;
            k += 1.0;
            found = false;
            for(i=piles.size()-1;i>=0;i--){
                cnt -= (int) ceil(piles[i]/k);
                // cout << ceil(piles[i]/k) << endl;
                if(cnt<0){
                    found = true;
                    break;
                }
            }
        }
        return (int) k;
    }
};


int main(){

    Solution s1;
    vector<int> piles = {3,6,7,11};
    int h = 8;
    //long input in java
    piles = {312884470};
    h = 312884469;
    cout << s1.minEatingSpeed(piles, h) << endl;
    return 0;
}