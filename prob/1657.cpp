#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_set<char> uni_char1, uni_char2;
        unordered_map<char, int> freq_char1, freq_char2;
        for(auto x: word1){
            uni_char1.insert(x);
            if(freq_char1.find(x)==freq_char1.end()){
                freq_char1[x] = 1;
            } else{
                freq_char1[x] +=1;
            }
        }
        for(auto x: word2){
            uni_char2.insert(x);
            if(freq_char2.find(x)==freq_char2.end()){
                freq_char2[x] = 1;
            } else{
                freq_char2[x] +=1;
            }
        }
        if(uni_char1 != uni_char2){
            return false;
        }
        // vector<int> a(freq_char1.size()), b(freq_char2.size());
        // vector<int> a(freq_char1.begin().second, freq_char1.end().second);
        vector<int> a, b;
        for(auto x: freq_char1) a.push_back(x.second);
        for(auto x: freq_char2) b.push_back(x.second);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        // return true;
        return a == b;
    }
};

bool checkEqual(vector<int> &a, vector<int> &b){
    return a == b;
}

int main(){
    vector<int> a = {1,2,3}, b={3, 4, 5};
    // cout << checkEqual(a, b) << endl;
    b = {1,2,3};
    // cout << checkEqual(a, b) << endl;
    string word1 = "abc", word2 = "bca";
    word1 = "a", word2 = "aa";
    word1 = "cabbba", word2 = "abbccc";
    word1 = "cabbba", word2 = "deefff";
    Solution s1;
    cout << s1.closeStrings(word1, word2) << endl;
    return 0;
}