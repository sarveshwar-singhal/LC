#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bas;
    
    bool isStrictlyPalindromic1(int n) {
        int i, j, k;
        bool outcome = true;
        for(i=2;i<=(n-2);i++){
            // bas.clear();
            getStringRep(n, i);
            j=0; k = bas.size()-1;
            while(j<k){
                if(bas[j] != bas[k]){
                    outcome = false;
                    break;
                }
                j+=1;
                k-=1;
            }
            if(!outcome){
                break;
            }
        }
        return outcome;
    }

    void getStringRep(int n, int base){
        bas.clear();
        while(n>0){
            bas.push_back(n%base);
            n /=base;
        }
    }

    bool isStrictlyPalindromic(int n){
        //mathematically this will always be false.
        return false;
    }
};

int main(int argc, char const *argv[])
{   
    Solution s1;
    int n;
    // n=20;
    // s1.getStringRep(n, 2);
    cout << s1.isStrictlyPalindromic(n) << endl;
    return 0;
}
