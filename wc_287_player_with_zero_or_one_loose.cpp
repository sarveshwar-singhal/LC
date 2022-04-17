#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> winner, looser;
        int i, len;
        len = matches.size();
        for(vector<int> outcome: matches){
            cout << outcome << endl;
        }
    }
};

int main(int argc, char const *argv[]){
    Solution s1;
}