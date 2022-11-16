#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void print(vector<vector<int>>& grid){
        int i, j;
        for(i=0;i<grid.size();i++){
            for(j=0;j<grid[0].size();j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size(), -1);
        vector<vector<int>> ngrid(grid.size(), vector<int>(grid[0].size()+2, 0));
        int i, j,k;
        for(i=0;i<grid.size();i++){
            for(j=0;j<grid[0].size();j++){
                ngrid[i][j+1] = grid[i][j];
            }
        }
        // print(grid);
        // cout << endl;
        // print(ngrid);
        // return ans;
        int row = ngrid.size();
        for(j=1;j<ngrid[0].size()-1;j++){
            k=j;
            for(i=0;i<row;i++){
                if(ngrid[i][k]==1 and ngrid[i][k+1]==1){
                    k+=1;
                }else if(ngrid[i][k]==-1 and ngrid[i][k-1]==-1){
                    k-=1;
                }else{
                    break;
                }

                if(i==row-1){
                    ans[j-1] = k-1;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
    vector<int> ans;
    Solution s1;
    grid = {{-1}};
    grid = {{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1},{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1}};
    ans = s1.findBall(grid);
    for(auto x: ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}