#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int i, val, ans;
        for(i=0;i<nums.size();i++){
            if(nums[i]<0){
                val = nums[i]/value;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int a = -7, b = 3;
    a = -999933185;
    b= 123;
    // cout << fixed << setprecision(4) << floor((float) a/b) << endl;
    cout << abs((int) floor((float) a/b)) << endl;
    float f = (a*1.0)/b;
    f = floor(f);
    cout << f << endl;
    // int x = f;
    // cout << x << endl;
    cout << a%b << endl;
    return 0;
}
