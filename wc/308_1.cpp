#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    //try 3: no new vector for prefix sum. used existing nums
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> out(queries.size(), 0);
        int i;
        for(i=1;i<nums.size();i++){
            nums[i] += nums[i-1];
        }
        int l, r, mid, key;
        for(i=0;i<queries.size();i++){
            key = queries[i];
            l=0, r=nums.size()-1;
            while(l<=r){
                mid = (l+r)/2;
                if(key < nums[mid]){
                    r = mid-1;
                } else if(key > nums[mid]){
                    l = mid+1;
                } else{
                    l = mid+1;
                    break;
                }
            }
            out[i] = l;
        }
        return out;
    }
    //try2: used binary search for finding base index
    vector<int> answerQueries2(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> psum(nums.size(), 0);
        vector<int> out(queries.size(), 0);
        int i;
        psum[0] = nums[0];
        for(i=1;i<nums.size();i++){
            psum[i] += psum[i-1] + nums[i];
        }
        int l, r, mid, key;
        for(i=0;i<queries.size();i++){
            key = queries[i];
            l=0, r=psum.size()-1;
            while(l<=r){
                mid = (l+r)/2;
                if(key < psum[mid]){
                    r = mid-1;
                } else if(key > psum[mid]){
                    l = mid+1;
                } else{
                    l = mid+1;
                    break;
                }
            }
            out[i] = l;
        }
        return out;
    }

    //used linear search for finding base index
    vector<int> answerQueries1(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        // for(auto x: nums){
        //     cout << x << " ";
        // }
        // cout << endl;
        vector<int> psum(nums.size(), 0);
        vector<int> out(queries.size(), 0);
        int i;
        psum[0] = nums[0];
        for(i=1;i<nums.size();i++){
            psum[i] += psum[i-1] + nums[i];
        }
        for(i=0;i<psum.size();i++){
            cout << psum[i] << " ";
        }
        cout << endl;
        int low, high, mid, key;
        for(i=0;i<queries.size();i++){
            key = queries[i];
            high = 0;
            for(low=0;low<psum.size();low++){
                if(psum[low] <= key){
                    high+=1;
                } else{
                    break;
                }
            }
            out[i] = high;
        }
        return out;
    }
};

void func(){
    //trial code
    /*  if(queries[i] < psum[0]){
        out[i] = 0;
    } else if (queries[i] >= psum[psum.size()-1]){
        out[i] = psum.size();
    } else{
        low = 0; high = psum.size() -1;
        key = queries[i];
        while(low < high){
            mid = (low+high)/2;
            if(key>psum[mid]){
                low = mid+1;
            } else if(key < psum[mid]){
                high = mid -1;
            } else{
                low = mid+1;
                break;
            }
        }
        out[i] = low;
    }   */
}

int main(int argc, char const *argv[])
{
    vector<int> nums, queries;
    nums = {5, 4, 2, 1};
    queries = {3, 10, 21};
    nums= {736411,184882,914641,37925,214915};
    queries = {331244,273144,118983,118252,305688,718089,665450};
    vector<int> ans;
    Solution s1;
    ans = s1.answerQueries(nums, queries);
    for(auto x: ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
