#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt=0, i;
        unordered_set<char> vowel = {'a','e','i','o','u'};
        for(i=left;i<=right;i++){
            if(vowel.find(words[i][0])!=vowel.end() && vowel.find(words[i].back())!= vowel.end()){
                cnt +=1;
            }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
