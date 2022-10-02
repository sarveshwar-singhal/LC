#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int commonFactors(int a, int b) {
        int i, mini = min(a, b);
        int cnt = 1;
        for(i=2;i<=mini;i++){
            if(a%i==0 && b%i==0){
                cnt +=1;
            }
        }
        return cnt;
    }
};