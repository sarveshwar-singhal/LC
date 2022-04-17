#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        string s1 = s;
        string out = string("");
        string temp;
        int sum;
        int i,j;
        // cout << s1 << endl;
        while(s1.length() > k){
            // cout << "this" << endl;
            out = "";
            for(i=0;i<s1.length();i+=k){
                temp = s1.substr(i, k);
                sum=0;
                // cout << temp << endl;
                // cout << temp.length() << endl;
                for(j=0;j<temp.length();j++){
                    // cout << temp[j] << endl;
                    sum+= (int) temp[j] - 48;
                }
                // cout << sum << endl;
                // break;
                out+= to_string(sum);
            }
            s1 = out;
            // cout << out << endl;
            // cout << s1.length() << endl;
        }
        return s1;
    }
};


int main(int argc, char const *argv[])
{
    Solution s1;
    string s = "00000000";
    int k;
    k = 3;
    // s="this is";
    cout << s1.digitSum(s, k) << endl;
    // cout << to_string(48) << endl;
    return 0;
}
