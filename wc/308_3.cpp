#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> mpos, ppos, gpos;
        int mc=0, pc=0, gc = 0;
        bool m, p, g;
        int count=0;
        int i, j;
        char y;
        for(i=0;i<garbage.size();i++){
            m = false; p = false; g=false;
            for(j=0;j<garbage[i].length();j++){
                y = garbage[i][j];
                if(y=='M'){
                    mc+=1;
                    m = true;
                } else if(y=='P'){
                    pc+=1;
                    p = true;
                } else{
                    gc +=1;
                    g = true;
                }
            }
            if(m){
                mpos.push_back(i);
            }
            if(p){
                ppos.push_back(i);
            }
            if(g){
                gpos.push_back(i);
            }
        }
        vector<int> ptravel(travel.size()+1, 0);
        // ptravel[0] = 0;
        for(i=0;i<travel.size();i++){
            ptravel[i+1] = ptravel[i] + travel[i];
        }
        for(i=0;i<mpos.size();i++){
            if(i==0){
                count += ptravel[mpos[i]];
            } else{
                count += ptravel[mpos[i]] - ptravel[mpos[i-1]];
            }
        }
        for(i=0;i<ppos.size();i++){
            if(i==0){
                count += ptravel[ppos[i]];
            } else{
                count += ptravel[ppos[i]] - ptravel[ppos[i-1]];
            }
        }
        for(i=0;i<gpos.size();i++){
            if(i==0){
                count += ptravel[gpos[i]];
            } else{
                count += ptravel[gpos[i]] - ptravel[gpos[i-1]];
            }
        }
        count += mc + pc + gc;
        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution s1;
    vector<string> garbage = {"MMM","PGM","GP"};
    vector<int> travel = {3, 10};
    int ans;
    ans = s1.garbageCollection(garbage, travel);
    cout << ans << endl;
    return 0;
}
