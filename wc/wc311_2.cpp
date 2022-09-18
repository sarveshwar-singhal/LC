#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countLen(string &s, string left, int i){
        //base case
        if(i==s.length()){
            return left.length();
        }

        //rec case
        int l1 = 0, l2 =0;
        l2 = countLen(s, left, i+1);
        if(left.back() < s[i]){
            l1 = countLen(s, left+s[i], i+1);
            // countLen(s, left, i+1);
        }
        return max(l1, l2);
    }

    int longestContinuousSubstring(string s) {
        // return countLen(s, "", 0);
        if(s.length() < 2){
            return s.length();
        }
        int i, j;
        int l1=0, l2 =0;
        string s1 = "";
        int len = s.length();
        for(i=0;i<len-1;i++){
            s1 = s[i];
            l1 = 1;
            for(j=i+1;j<len;j++){
                if(s1.back() == s[j]-1){
                    l1 +=1;
                    s1 = s[j];
                } else{
                    break;
                }
            }
            l2 = max(l1, l2);
        }
        return l2;
    }
};


int main(int argc, char const *argv[])
{
    string s= "abacaba";
    s = "awy";
    int ans;
    Solution s1;
    ans = s1.longestContinuousSubstring(s);
    cout << ans << endl;
    return 0;
}
