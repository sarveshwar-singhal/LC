#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    
    int subarrayGCD(vector<int>& nums, int k) {

        int i, j;
        for(i=0;i<nums.size();i++){
            if(nums[i] % k ==0){
                nums[i] /= k;
            }else {
                nums[i] = 0;
            }
        }

    }
};