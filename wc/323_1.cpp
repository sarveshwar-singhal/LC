#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int i,j;
        int row = grid.size(), col = grid[0].size();
        for(i=0;i<row;i++){
            sort(grid[i].begin(), grid[i].end());
        }
        int ans = 0;
        int mini;
        for(j=0;j<col;j++){
            mini = 0;
            for(i=0;i<row;i++){
                if(mini < grid[i][j]){
                    mini = grid[i][j];
                }
            }
            ans += mini;
        }
        return ans;
    }
};

int main(){
    int x, z;
    float y;
    x = 10;
    z = pow(x, 2);
    // y = sqrt(z);
    // x = sqrt(z);
    // x = y = sqrt(z);
    // if(x==y){
    //     cout << x << "  " << y << endl;
    // }
    z = 101;
    x = sqrt(z);
    cout << x << endl;
    if(x == sqrt(z)){
        cout << "valid comparision of int and float" << endl;
    }
    if(sqrt(z) == int(sqrt(z))){
        cout << "equal" << endl;
    }
    return 0;
}