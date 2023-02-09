#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int minDeletionSize(vector<string> &strs){
        int ans = 0, sz = strs.size(), i, j;
        if(sz < 2){
            return 0;
        }
        char c;
        for(i=0;i<strs[0].size();i++){
            c = strs[0][i];
            for(j=1;j<sz;j++){
                if(c > strs[j][i]){
                    ans +=1;
                    break;
                }
                c = strs[j][i];
            }
        }
        return ans;
    }
};

int main(){
    vector<string> strs = {"cba","daf","ghi"};
    strs = {"a","b"};
    // strs = {'a','b'};
    Solution s1;
    cout << s1.minDeletionSize(strs) << endl;
    return 0;
}