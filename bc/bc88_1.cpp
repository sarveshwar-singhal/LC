#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        int i, j;
        // unordered_map<char, int> freq;
        int freq[26] = {0};
        for(i=0;i<word.length();i++){
            if(freq[word[i] - 97] == 0){
                freq[word[i]-97] = 1;
            } else {
                freq[word[i]-97] +=1;
            }
        }

        int total=0, nzero=0;
        for(i=0;i<26;i++){
            total += freq[i];
            if(freq[i] != 0) nzero +=1;
        }
        if(total%nzero == 1 || (total-1)%(nzero-1) == 0){
            return true;
        } else {
            return false;
        }
    }
};