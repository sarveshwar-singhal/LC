#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i, j, req, len;
        len = blocks.length();
        req = len+1;
        int curr_req;
        for(i=0;i<=len-k;i++){
            curr_req = 0;
            for(j=i;j<i+k;j++){
                if(blocks[j] == 'W'){
                    curr_req++;
                }
            }
            req = min(req, curr_req);
        }
        return req;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution s1;
    string blocks = "WBBWWBBWBW";
    // blocks = "BWWWBB";
    int ans, k;
    k = 7;
    ans = s1.minimumRecolors(blocks, k);
    cout << ans << endl;
    return 0;
}
