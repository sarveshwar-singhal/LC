#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> smallestSubarrays2(vector<int>& nums){
        vector<int> ans(nums.size(), 1);
        vector<int> max_idx(nums.size(), 0);
        int i, j, len;
        int maxi, ele, prev;
        len=nums.size();
        for(i=0;i<len;i++){
            maxi=i;
            for(j=i+1; j<len;j++){
                if(nums[maxi] < nums[j]){
                    maxi = j;
                }
            }
            max_idx[i] = maxi;
        }
        for(i=0; i< len; i++){
            maxi=1;
            ele = nums[i];
            prev = nums[i];
            for(j=i+1;j<len;j++){
                ele |= nums[j];
                if(ele > prev){
                    maxi = j-i+1;
                    prev = ele;
                }
                if(j >= max_idx[i] && (prev & ~0) ==0){
                    break;
                }
            }
            ans[i] = maxi;
        }
        return ans;
    }

    vector<int> smallestSubarrays1(vector<int>& nums){
        vector<int> max_idx(nums.size(), 0);
        int i, j ;
        int maxi;
        int len = nums.size();
        for(i=0;i<len;i++){
            maxi=i;
            for(j=i+1; j<len;j++){
                if(nums[maxi] < nums[j]){
                    maxi = j;
                }
            }
            max_idx[i] = maxi;
        }
        vector<int> ans(len, 1);
        for(i=0;i<len;i++){
            maxi = 1;
            for(j=i+1;j<max_idx[i];j++){

            }
        }
        return max_idx;
    }

    vector<int> smallestSubarrays(vector<int>& nums) {
        int maxi = 0;
        int i, j;
        for(i=1;i<nums.size();i++){
            if(nums[maxi] < nums[i]){
                maxi = i;
            }
        }
        int len = floor(log(nums[maxi])) +1;
        vector<vector<int>> binary(len, vector<int>(len, 0));
        vector<int> base_vec(len, 0);
        int ele;
        for(i=0;i<nums.size();i++){
            base_vec = vector<int>(len, 0);
            ele = nums[i];
            j=len-1;
            while(ele!=0){
                base_vec[j] = ele%2;
                ele /= 2;
                j--; 
            }
            binary[i] = base_vec;
        }
        for(i=len-1;i>=0;i--){

        }
        return base_vec;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 0, 2, 1, 3};
    vector<int> ans;
    Solution s1;
    nums = {1, 2};
    nums = {9, 5,0,10,7,2,9,2,4};

    ans = s1.smallestSubarrays2(nums);
    for(auto x: ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
