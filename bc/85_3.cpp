#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>
using namespace std;


class Solution {
public:

    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        unordered_map<int, int> sby;
        int i, j;
        int dir;
        for(auto x: shifts){
            dir = 1;
            if(x[2] == 0){
                dir = -1;
            }
            for(i=x[0];i<=x[1];i++){
                if(sby.find(i) == sby.end()){
                    sby[i] = 0;
                }
                sby[i] += dir;
            }
        }
        int temp;
        for(auto x: sby){
            temp = s[x.first] - 96;
            temp += x.second;
            temp %= 26;
            if(temp < 1){
                temp += 26;
            }
            s[x.first] = temp + 96;
        }
        return s;
    }

    string shiftingLetters1(string s, vector<vector<int>>& shifts) {
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
            //below out throwing TLE
            // out += char(li[i] + 96);
            //Big Blunder. it will convert digit to string and not digit to char and then string.
            // out += to_string(li[i] + 96);
            //try 3
            s[i] = char(li[i] + 96);
        }
        return s;
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
