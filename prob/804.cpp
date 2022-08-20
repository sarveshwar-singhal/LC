#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // string s[];
        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int i, j;
        unordered_map<string, int> transform;
        string s = "";
        for(i=0;i<words.size();i++){
            s = "";
            for(j=0;j<words[i].size();j++){
                s+=code[words[i][j]-97];
            }
            transform[s] = 0;
        }
        return transform.size();
    }
};

int main(){
    Solution s1;
    vector<string> words = {"gin","zen","gig","msg"};
    // words = {"a"};
    int ans;
    ans = s1.uniqueMorseRepresentations(words);
    cout << ans << endl;
    return 0;
}