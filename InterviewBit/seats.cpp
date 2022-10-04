#include<iostream>
using namespace std;

class Solution{

public:
    int findEmpty(string &A, int j, bool asce){
        if(asce){
            for(int i=j;i<A.size();i++){
                if(A[i] == '.'){
                    return i;
                }
            }
        } else{
            for(int i=j;i>=0;i--){
                if(A[i] == '.'){
                    return i;
                }
            }
        }
        return 0;
    }

    int seats(string A) {
        int i, j, left, right, llimit, rlimit;
        int num=0;
        for(i=0;i<A.size();i++){
            if(A[i] == 'x') {left = i; break;}
        }

        for(i=A.size()-1;i>=0;i--){
            if(A[i] == 'x') {right = i; break;}
        }

        for(i=0;i<A.size();i++){
            if(A[i] == 'x') {num +=1;}
        }
        // cout << "left " << left << " right " << right << " size " << num << endl;
        int center;
        center = (left + right) / 2;
        int temp = 0;
        for(i=center-1;i>=0;i--){
            if(A[i] == 'x') temp+=1;
        }
        for(i=center+1;i<A.size();i++){
            if(A[i] == 'x') temp-=1;
        }
        llimit = rlimit = center;
        if(temp > 0){
            llimit -= num/2;
            rlimit += (num-1) - num/2;
        } else if(temp < 0){
            llimit -= (num-1)/2;
            rlimit += (num-1) - (num-1)/2;
        } else {
            if(llimit - left > right - rlimit){
                llimit -= num/2;
                rlimit += (num-1) - num/2;
            } else {
                llimit -= (num-1)/2;
                rlimit += (num-1) - (num-1)/2;
            }
        }
        // llimit = center - (num-1)/2;
        // rlimit = center + (num - 1) -  (num - 1)/ 2;
        // cout << "llimit = " << llimit << " rlimit = " << rlimit << endl;
        int ans = 0;
        i = left; j = llimit;
        while(i<llimit){
            if(A[i] == 'x'){
                j = findEmpty(A, j, true);
                // cout << j-i << endl;
                ans += j-i;
                j+=1;
                // cout << "inside first if" << endl;
            }
            i+=1;
        }
        i = right; j=rlimit;
        while(rlimit < i){
            if(A[i] == 'x'){
                j = findEmpty(A, j, false);
                ans += i-j;
                j-=1;
                // cout << "inside second if" << endl;
            }
            i-=1;
        }
        return ans % 10000003;
    }
};

int main(){
    string s = "....x..xx...x..";
    Solution s1;
    cout << s1.seats(s) << endl;
    return 0;
}