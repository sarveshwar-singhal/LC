#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // string s[];
        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int i;
        unordered_map<string, int> count;
        for(i=0;i<code.size();i++){
            cout << code[i] << endl;
        }
        return 0;
    }
};

int main(){
    Solution s1;
    vector<string> words = {"gin","zen","gig","msg"};
    s1.uniqueMorseRepresentations(words);
    return 0;
}