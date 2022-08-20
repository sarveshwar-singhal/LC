#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int secondsToRemoveOccurrences1(string s) {
        int i, j;
        int z_count, pos, len;
        len = s.length();
        z_count = 0;
        pos = -1;
        for(i=0;i<len;i++){
            if(s[len-i-1] == '0'){
                z_count++;
                pos = i+1;
            }
        }
        return pos - z_count +1;
    }
    int secondsToRemoveOccurrences(string s) {
        int i, j;
        int pos1, pos0;
        int len, op;
        len = s.length();
        for(i=0;i<len;i++){
            if(s[i] == '1'){
                pos1 = i;
            }
            if(s[len-i-1] == '0'){
                pos0 = len -i -1;
            }
        }
        bool found;
        op = 0;
        while(pos1>pos0){
            found = false;
            for(i=0;i<len-1;i++){
                if(s[i] == '0' && s[i+1]=='1'){
                    found=true;
                    swap(s[i], s[i+1]);
                    i++;
                }
            }
            if(found){
                op++;
            }
            for(i=0;i<len;i++){
                if(s[i] == '1'){
                    pos1 = i;
                }
                if(s[len-i-1] == '0'){
                    pos0 = len -i -1;
                }
            }
        }
        return op;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution s1;
    string blocks = "0110101";
    blocks = "11100";
    blocks="001011";
    // blocks = "001011";
    int ans, k;
    k = 7;
    // ans = s1.minimumRecolors(blocks, k);
    ans = s1.secondsToRemoveOccurrences(blocks);
    cout << ans << endl;
    return 0;
}
