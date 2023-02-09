#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
    vector<int> prime = {2,3,5,7,11};
public:

    bool isPrime(int n){
        bool temp = false;
        if(n&1 == 0 && n!=2){
            return false;
        }
        if(n < prime.back()){
            for(auto x: prime){
                if(n == x){
                    return true;
                } else if(x > n){
                    break;
                }
            }
            return false;
        } else if(n == prime.back()){
            return true;
        } else if(n > pow(prime.back(), 2)) {
            calcPrime(n);
        }
    }

    void calcPrime(int n){
        for(int i=prime.back()+2;i<=sqrt(n);i+=2){
            
        }
    }

    int calcPrimeFactSum(int n){

    }

    int smallestValue(int n) {
        int ans = n;
        while(!isPrime(ans)){

        }
        return ans;
    }
};