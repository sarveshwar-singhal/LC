#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int i;
        int cnt1 = 0, cnt2=0, mid = s.length()/2;
        string vowel = "aeiouAEIOU";
        for(i=0;i<mid;i++){
            // vowel.find()
            if(vowel.find(s[i])!=vowel.npos) cnt1+=1;
            if(vowel.find(s[i+mid])!=vowel.npos) cnt2+=1;
        }
        // cout << "value of cnt1: " << cnt1 << " value of cnt2: " << cnt2 << endl;
        return cnt1 == cnt2;
    }
};

int main(){
    string s = "book", a;
    Solution s1;
    // a = "stuvwxyz";
    // s = "textbook";
    // cout << s.find(a[0]) << endl;
    cout << s1.halvesAreAlike(s) << endl;
    return 0;
}