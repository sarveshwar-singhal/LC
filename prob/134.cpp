#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i, j, ans=-1, gasAvail=0, n= gas.size();
        //trying octal, hexal number in c++
        // i = 09991;
        // i = 08881;
        // i = 0008;
        // i = 0xf423;
        for(i=0;i<n;i++){
            gasAvail = gas[i];
            for(j=0;j<n;j++){
                if(gasAvail < cost[(i+j)%n]){
                    break;
                }
                gasAvail += gas[(i+j+1)%n] -cost[(i+j)%n];
            }
            // cout << gasAvail << endl;
            if(i+n == i+j){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> gas = {1,2,3,4,5}, cost = {3,4,5,1,2};
    Solution s1;
    cout << s1.canCompleteCircuit(gas, cost) << endl;
    return 0;
}