#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int rob(vector<int>& nums){
        if(nums.size() < 1){
            return 0;
        } else if(nums.size() == 1){
            return nums[0];
        } else if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        int prev, curr, upcoming;
        prev = 0;
        curr = nums[0];
        upcoming = 0;
        int i;
        for(i=1;i<nums.size();i++){
            if(nums[i] + prev > curr){
                upcoming = nums[i] + prev;
                prev = curr;
                curr = upcoming;
            } else{
                prev = curr;
            }
        }
        return curr;
    }

    int rob1(vector<int>& nums) {
        if(nums.size() < 1){
            return 0;
        } else if(nums.size() == 1){
            return nums[0];
        } else if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }

        int x, n;
        x = nums[0];
        n = nums.size();
        x = x + rob(nums);
    }

    int total(vector<int>& nums, int start, int n){
        if(n - start < 0){
            return 0;
        } else if(n - start == 0){
            return nums[start];
        } else if(n - start == 1){
            return max(nums[start+0], nums[start+1]);
        }

        int x, y, z;
        x = nums[start];
        // z = total(nums, start+3, n);
        // x = x + max(total(nums, start+2, n), total(nums, start+3, n));
        // x = x + max(total(nums, start+2, n), z);
        x = x + total(nums, start+2, n);
        y = nums[start+1];
        // y = y + max(total(nums, start+3, n), total(nums, start+4, n));
        // y = y + max(z, total(nums, start+4, n));
        y = y + total(nums, start+3, n);
        // y = y + z;
        return max(x, y);
    }
};

int main(){
    Solution s1;
    vector<int> nums = {2, 7, 9, 3,1};
    nums = {114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188,67,205,94,205,169,241,202,144,240};
    nums = {155,44,52,58,250,225,109,118,211,73,137,96,137,89,174,66,134,26,25,205,239,85,146,73,55,6,122,196,128,50,61,230,94,208,46,243,105,81,157,89,205,78,249,203,238,239,217,212,241,242,157,79,133,66,36,165};
    // nums = {226,174,214,16,218,48,153,131,128,17,157,142,88,43,37,157,43,221,191,68,206,23,225,82,54,118,111,46,80,49,245,63,25,194,72,80,143,55,209,18,55,122,65,66,177,101,63,201,172,130,103,225,142,46,86,185,62,138,212,192,125,77,223,188,99,228,90,25,193,211,84,239,119,234,85,83,123,120,131,203,219,10,82,35,120,180,249,106,37,169,225,54,103,55,166,124};
    int n, start;
    n = nums.size()-1;
    start = 0;
    cout << n << " " << start << endl;
    int outcome;
    // outcome = s1.total(nums, start, n);
    outcome = s1.rob(nums);
    cout << outcome << endl;
    return 0;
}