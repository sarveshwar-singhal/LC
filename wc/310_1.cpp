#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        int ans = INT32_MIN;
        for(int i=0;i<nums.size();i++){
            if((nums[i] & 1) == 0){
                if(freq.find(nums[i]) == freq.end()){
                    freq[nums[i]] = 0;
                }
                freq[nums[i]] +=1;
            }
        }
        if(freq.size()==0){
            return -1;
        }
        int cnt = INT32_MIN;
        for(auto x: freq){
            if(x.second > cnt){
                ans = x.first;
                cnt = x.second;
            } else if(x.second == cnt){
                ans = min(ans, x.first);
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> arr = {0, 1, 2, 2, 4, 4, 1};
    Solution s1;
    cout << s1.mostFrequentEven(arr) << endl;
    return 0;
}
