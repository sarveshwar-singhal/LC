#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        string ans = "";
        for(auto x: s) freq[x]++;
        vector<pair<char, int>> freq_vec(freq.begin(), freq.end());
        // need to check this
        // sort(freq_vec.begin(), freq_vec.end(), )
        for(auto x: freq_vec){
            cout << x.first << ": " << x.second <<endl;
        }
        return ans;
    }
};

int main(){
    Solution s1;
    string s = "tttree";
    string ans = "";
    ans = s1.frequencySort(s);
    cout << ans << endl;
    return 0;
}