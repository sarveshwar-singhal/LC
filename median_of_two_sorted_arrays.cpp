#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len = nums1.size() + nums2.size();
    int l1, l2;
    int num, count=0, med;
    int val;
    double ans;
    l1 = nums1.size()-1, l2 = nums2.size()-1;
    med=len - len/2 - 1;
    if(len&1==1){
        num = 1;
    } else{
        num = 2;
    }
    while(med>0){
        if(l1>=0 && l2>=0){
            if(nums1[l1]<nums2[l2]){
                l2--;
            } else{
                l1--;
            }
        }else if(l2>=0){
            l2--;
        }else{
            l1--;
        }
        med--;
    }
    if(l1>=0 && l2>=0){
        if(nums1[l1]<nums2[l2]){
            val = nums2[l2];
            l2--;
        } else{
            val = nums1[l1];
            l1--;
        }
    } else if(l2>=0){
        val = nums2[l2];
        l2--;
    } else{
        val = nums1[l1];
        l1--;
    }
    if(num==1){
        ans = val/num;
        return ans;
    }

    if(l1>=0 && l2>=0){
        if(nums1[l1]<nums2[l2]){
            val+= nums2[l2];
            l2--;
        } else{
            val+= nums1[l1];
            l1--;
        }
    } else if(l2>=0){
        val += nums2[l2];
        l2--;
    } else{
        val += nums1[l1];
        l1--;
    }
    ans = val/num;
    return ans;

    }
};

int main(int argc, char const *argv[])
{

    return 0;
}