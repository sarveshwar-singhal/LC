#include<iostream>
#include<vector>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i] != '*'){
                st.push(s[i]);
            } else {
                st.pop();
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s1;
    string s = "leet**cod*e";
    cout << s1.removeStars(s) << endl;
    return 0;
}
