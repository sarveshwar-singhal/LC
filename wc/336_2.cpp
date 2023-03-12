#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int i, cnt=0;
        long sum=0;
        sort(nums.begin(), nums.end());
        for(i=nums.size()-1;i>=0;i--){
            if(nums[i]>=0){
                cnt+=1;
                sum+=nums[i];
            } else {
                break;
            }
        }
        if(sum==0){
            return 0;
        }
        for(i;i>=0;i--){
            if(sum > (abs(nums[i]))){
                sum += nums[i];
                cnt += 1;
            } else {
                break;
            }
        }
        cout << "value of count: " << cnt << endl;
        cout << "value of sum: " << sum << endl;
        // for(i=0;i<nums.size();i++){
        //     if(nums[i]>=0){
        //         break;
        //     } else {
        //         if(sum > (abs(nums[i]))){
        //             sum += nums[i];
        //             cnt += 1;
        //         } else {
        //             break;
        //         }
        //     }
        // }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {2,-1,0,1,-3,3,-3};
    Solution s1;
    cout << s1.maxScore(nums) << endl;
    return 0;
}
