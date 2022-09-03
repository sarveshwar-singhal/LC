#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int i;
        vector<long> psum(nums.size(), 0);
        psum[0] = nums[0];
        for(i=1;i<nums.size();i++){
            psum[i] = psum[i-1] + nums[i];
        }
        unordered_map<long, int> check;
        check[psum[1]] = 1;
        for(i=2;i<psum.size();i++){
            if(check.find(psum[i] - psum[i-2])!=check.end()){
                return true;
            }
            check[psum[i]-psum[i-2]] = 1;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4,5};
    Solution s1;
    cout << s1.findSubarrays(nums) << endl;
    return 0;
}
