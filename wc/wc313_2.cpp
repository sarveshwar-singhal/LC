#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //approach with no extra space
    int maxSum1(vector<vector<int>> &grid){
        int i, j;
        for(i=0;i<grid.size();i++){
            for(j=1;j<grid[i].size();j++){
                grid[i][j] += grid[i][j-1];
            }
        }

        int msum = -1, csum = 0;
        for(i=0;i<grid.size()-2;i++){
            for(j=0;j<grid[i].size()-2;j++){
                if(j==0){
                    csum = grid[i][j+2] + grid[i+2][j+2] + grid[i+1][j+1] - grid[i+1][j];
                } else{
                    csum = grid[i][j+2] - grid[i][j-1] + grid[i+2][j+2] - grid[i+2][j-1] + grid[i+1][j+1]  - grid[i+1][j];
                }
                msum = max(msum, csum);
            }
        }
        return msum;
    }

    //approach using extra vector for prefix sum
    int maxSum(vector<vector<int>>& grid) {
        vector<vector<long>> psum;
        int i, j;
        for(i=0;i<grid.size();i++){
            vector<long> temp(grid[i].size()+1, 0);
            temp[0] = 0;
            for(j=0;j<grid[i].size();j++){
                temp[j+1] = temp[j] + grid[i][j];
            }
            psum.push_back(temp);
            temp.clear();
        }
        /*  for(i=0;i<psum.size();i++){
            for(j=0;j<psum[i].size();j++){
                cout << psum[i][j] << " ";
            }
            cout << endl;
        }   */
        int msum = -1, csum = 0;
        for(i=0;i<psum.size()-2;i++){
            for(j=1;j<psum[i].size()-2;j++){
                csum = psum[i][j+2] - psum[i][j-1] + psum[i+2][j+2] - psum[i+2][j-1] + psum[i+1][j+1] - psum[i+1][j];
                msum = max(msum, csum);
            }
        }
        return msum;
    }
};

int main(){
    vector<vector<int>> grid = {{6,2,1,3},{4,2,1,5},{9,2,8,7},{4,1,2,9}};
    // grid = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s1;
    cout << s1.maxSum1(grid) << endl;
    return 0;
}