#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPowerOfThree3(int n){
        if(n<1){
            return false;
        }
        while(n%3==0){

        }
        return false;
    }

    //tried basic approach of multiplying up
    bool isPowerOfThree2(int n) {
        if(n<1 || n & 1 ==0){
            return false;
        }
        if(n==1){
            return true;
        }
        int x=3;
        int quo, rem;
        while(true){
            quo = n/x;
            rem = n%x;
            if(quo == 1 && rem == 0){
                return true;
            }else if(rem !=0){
                return false;
            }
            x *= 3;
        }
        return false;
    }

    bool isPowerOfThree1(int n) {
        if(n<1){
            return false;
        }

        if((n ^ n-1) == 1){
            return true;
        } else{
            return false;
        }
    }
};

int main(int argc, char const *argv[])
{
    int n;
    n=45;
    Solution s1;
    // bool ans = s1.isPowerOfThree(n);
    // cout << ans << endl;
    // cout << false << endl;
    cout << s1.isPowerOfThree(n) << endl;
    cout << s1.isPowerOfThree1(n) << endl;
    return 0;
}
