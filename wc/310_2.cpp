#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionString(string s) {
        int cnt = 0;
        unordered_map<char, int> freq;
        // bool last = false;
        for(int i=0;i<s.length();i++){
            if(freq.find(s[i]) == freq.end()){
                freq[s[i]] = 1;
                // last = true;
            }else{
                cnt+=1;
                freq.clear();
                freq[s[i]] = 1;
                // last = false;
            }
        }
        if(freq.size() > 0){
            cnt+=1;
        }
        return cnt;
    }
};


int main(int argc, char const *argv[])
{
    string s= "ssssss";
    Solution s1;
    cout << s1.partitionString(s) << endl;
    return 0;
}
