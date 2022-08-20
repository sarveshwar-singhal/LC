#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int len;
        len = nums.size();
        if(len&1==1){
            return false;
        }
        int count, i;
        count = 0;
        for(i=0;i<nums.size();i++){
            count ^= nums[i];
        }
        if(count==0){
            return true;
        } else{
            return false;
        }
    }
};

int main(int argc, char const *argv[])
{

}
