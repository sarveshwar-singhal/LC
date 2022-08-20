#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;


class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> li(s.length(), 0);
        int i, j;
        for(i=0;i<li.size();i++){
            li[i] = s[i] - 96;
        }
        int val;
        for(auto x: shifts){
            val = 1;
            if(x[2] == 0){
                val = -1;
            }
            for(i=x[0];i<=x[1];i++){
                li[i] += val;
            }
        }
        string out = "";
        for(i=0;i<li.size();i++){
            li[i] %= 26;
            if(li[i] < 1){
                li[i] += 26;
            }
            out += char(li[i] + 96);
        }
        return out;
    }
};


int main(int argc, char const *argv[])
{
    // string s = "temp";
    // char s[] = "temp";
    Solution s1;
    string s = "";
    vector<vector<int>> shifts;
    shifts = {{0,1,0},{1,2,1},{0,2,1}};
    s = "abc";
    string ans;
    ans = s1.shiftingLetters(s, shifts);
    // cout << s.size() << " " << s.length() << endl;
    cout << ans << endl;
    return 0;
}
