#include<iostream>
#include<vector>
#include <set>
#include<algorithm>
using namespace std;

int main(){

    vector<int> v = {5,4,3,2,1};
    sort(v.begin(), v.end());
    for(int x: v){
        cout << x << " " ;
    }
    cout << endl;

    return 0;
}

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        int i;
        int count=0;
        long long int sum =0;
        i=1;
        int prev=0;
        int min_value;
        set<int> s(nums.begin(), nums.end());
        nums.clear();
        nums.assign(s.begin(), s.end());
        sort(nums.begin(), nums.end());
        while(true){
            if(prev==nums.size()){
                break;
            }
            if(i<nums[prev]){
                min_value = min(k, nums[prev]-i);
                sum += (long long int) (2*i + min_value-1)/2;
                k -= min_value;
                if(k==0){
                    return sum;
                }
                // while(i<nums[prev]){
                //     if(count == k){
                //         return sum;
                //     }
                //     sum += i;
                //     i+=1;
                //     count +=1;
                // }
            }
            // i=nums[prev];
            i=nums[prev]+1;
            prev+=1;
        }
        i+=1;
        while(true){
            sum += i;
            i+=1;
            count +=1;
            if(count==k){
                return sum;
            }
        }

        // while(true){
        //     if(count == k){
        //         return sum;
        //     }

        // }
    }

    long long temp(vector<int>& nums, int k){
        set<int> s(nums.begin(), nums.end());
        int i=1;
        int count = 0;
        long long int sum = 0;
        while(true){
            if(count == k){
                return sum;
            }
            if(s.find(i) == s.end()){
                sum += i;
                count += 1;
            }
            i+=1;
        }
    }
};