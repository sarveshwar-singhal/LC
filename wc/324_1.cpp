#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    int similarPairs1(vector<string>& words) {
        // unordered_set<char> s1(words.begin(), words.end());
        // unordered_set<char> s1(words);
        // unordered_set<char> s1(words[0].begin(), words[0].end());
        // unordered_set<char> s1(words[0]);
        vector<unordered_set<char>> uni_char(words.size());
        // unordered_map<unordered_set<char>, int> uni_word;
        unordered_map<string, int> uni_word;
        int ans = 0, i=0;
        for(auto x: words){
            uni_char[i++] = unordered_set<char>(x.begin(), x.end());
        }
        for(auto x: uni_char){
            for(auto y: x){
                cout << y;
            }
            cout << endl;
        }
        for(auto x: uni_char){
            string temp = string(x.begin(), x.end());
            // string temp = x;
            if(uni_word.find(temp) == uni_word.end()){
                uni_word[temp] = 1;
            } else {
                uni_word[temp] += 1;
            }
        }
        // int temp;
        for(auto x: uni_word){
            ans += (uni_word[x.first] * (uni_word[x.first]-1))/2;
        }
        return ans;
    }

    int similarPairs(vector<string>& words) {
        // vector<unordered_set<char>> uni_char(words.size());
        queue<unordered_set<char>> uni_char;
        int i=0, len, ans = 0, cnt=0;
        for(auto x: words){
            // uni_char[i++] = unordered_set<char>(x.begin(), x.end());
            uni_char.push(unordered_set<char>(x.begin(), x.end()));
        }
        unordered_set<char> temp;
        while(!uni_char.empty()){
            temp = uni_char.front();
            uni_char.pop();
            len = uni_char.size(), cnt = 1;
            for(i=0;i<len;i++){
                if(temp == uni_char.front()) cnt +=1;
                else uni_char.push(uni_char.front());
                uni_char.pop();
            }
            ans += (cnt * (cnt -1))/2;
        }
        return ans;
    }
};



int main(){
    string w1 = "bac", w2 = "aabc";
    unordered_set<char> us1(w1.begin(), w1.end()), us2(w2.begin(), w2.end());
    // us1 == us2;
    // cout << (us1 == us2) << endl;
    // return 0;
    Solution s1;
    vector<string>  words = {"aba","aabb","abcd","bac","aabc"} ;
    words = {"aabb","ab","ba"};
    words = {"nba","cba","dba"};
    cout << s1.similarPairs(words) << endl;

    return 0;
}