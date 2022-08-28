#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        vector<char> clean;
        char c;
        int i;
        for(i=0;i<s.size();i++){
            if(s[i] == '*'){
                clean.pop_back();
            } else{
                clean.push_back(s[i]);
            }
        }
        string out = "";
        for(i=0;i<clean.size();i++){
            out += clean[i];
        }
        return out;
    }
};

int main(int argc, char const *argv[])
{
    Solution s1;
    string s = "erase*****";
    string sol = "";
    sol = s1.removeStars(s);
    cout << sol << endl;
    return 0;
}
