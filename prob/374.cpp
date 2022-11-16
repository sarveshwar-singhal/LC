#include<iostream>
using namespace std;

// int guess(int);

class Solution {
public:
    int guessNumber(int n) {
        // math.ra
        int num;
        int left = 1, right = n;
        int res=1;
        num = (left+right)/2;
        while(res){
            res = guess(num);
            if(res < 0){
                right = num-1;
            }else if(res > 0){
                left = num + 1;
            }
            num = (left+right)/2;
        }
        return num;
    }

    int guess(int num){
        int val = 1;
        if(val<num){
            return -1;
        }else if(val > num){
            return 1;
        }else{
            return 0;
        }
    }
};



int main(){
    Solution s1;
    int n = 10;
    cout << s1.guessNumber(n) << endl;
    return 0;
}