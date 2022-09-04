#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char, int> pos;
        int i, j;
        for(i=0;i<s.length();i++){
            if(pos.find(s[i])!=pos.end()){
                if(i-pos[s[i]] - 1 != distance[s[i] - 97]){
                    return false;
                }
            } else{
                pos[s[i]] = i;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
