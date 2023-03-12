#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int i, j, cnt=0;
        string s = "";
        char c = chars[0];

        for(i=0;i<chars.size();i++){
            if(c == chars[i]){
                cnt+=1;
            } else {
                s += c;
                if(cnt>1){
                    s += to_string(cnt);
                }
                cnt=1;
                c = chars[i];
            }
        }
        s += c;
        if(cnt>1){
            s += to_string(cnt);
        }
        for(i=0;i<s.length();i++){
            chars[i] = s[i];
        }
        return s.length();
    }
};

int main(){
    vector<char> chars = {'a', 'a', 'b', 'b','c','c','c'};
    chars = {'a'};
    Solution s1;
    int cnt = s1.compress(chars);
    for(int i=0;i<cnt;i++){
        cout << chars[i] << " ";
    }
    cout << endl;
    return 0;
}