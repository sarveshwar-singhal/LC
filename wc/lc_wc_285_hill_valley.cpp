#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int i, j;
        j=0;
        int total = 0;
        for(i=1;i<nums.size()-1;i++){
            if(nums[i] == nums[j] || nums[i] == nums[i+1]){
                continue;
            }else if((nums[i]>nums[j] && nums[i]>nums[i+1]) || (nums[i]<nums[j] && nums[i]<nums[i+1])) {
                total+=1;
                j=i;
            }
        }
        return total;
    }
};

int main(int argc, char const *argv[])
{
    Solution s1;
    vector<int> vec = {1,2,3};
    int ans;
    ans = s1.countHillValley(vec);
    // cout << ans << endl;
    return 0;
}
