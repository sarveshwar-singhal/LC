#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int ans = -1, sz = words.size(), i;
        for(i=0;i<sz;i++){
            if(words[(startIndex + i)%sz] == target){
                ans = i;
                break;
            }
        }
        for(i=0;i<sz;i++){
            if(words[(startIndex - i + sz)%sz] == target){
                ans = min(i, ans);
                break;
            }
        }
        return ans;
    }
};

int main(){
    vector<string> words = {"hello","i","am","leetcode","hello"};
    string target = "hello";
    int startIndex = 3;
    Solution s1;
    cout << s1.closetTarget(words,target,startIndex) << endl;
    return 0;
}