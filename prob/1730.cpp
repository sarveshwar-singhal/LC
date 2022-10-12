#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int len;

    void findWays(vector<vector<string>> &grid, int i, int j, int cnt){
        //base case
        if(i>=grid.size() or j>=grid[0].size() or i<0 or j<0 or (grid[i][j] == "X") or cnt >= this->len){
            return;
        }

        if(grid[i][j] == "#"){
            this->len = min(this->len, cnt);
            return;
        }

        //rec case
        string tmp = grid[i][j];
        grid[i][j] = "X";
        findWays(grid, i+1, j, cnt+1);
        findWays(grid, i, j+1, cnt+1);
        findWays(grid, i-1, j, cnt+1);
        findWays(grid, i, j-1, cnt+1);
        grid[i][j] = tmp;
        return;
    }
public:

    Solution(){
        this->len = INT32_MAX;
    }

    int getFood(vector<vector<string>>& grid) {
        int i=0, j=0;
        bool done = false;
        for(i=0;i<grid.size();i++){
            for(j=0;j<grid[0].size();j++){
                if(grid[i][j] == "#"){
                    done = true;
                    break;
                }
            }
            if(done){
                break;
            }
        }
        if(!done){
            return -1;
        }
        done = false;
        for(i=0;i<grid.size();i++){
            for(j=0;j<grid[0].size();j++){
                if(grid[i][j] == "*"){
                    done = true;
                    break;
                }
            }
            if(done){
                break;
            }
        }

        cout << "value of i and j is " << i << "  " << j << endl;
        findWays(grid, i, j, 0);
        // cout << this->len << endl;
        if(this->len == INT32_MAX){
            return -1;
        }
        return this->len;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<string>> grid = {{"X","X","X","X","X","X"},
                                    {"X","*","O","O","O","X"},
                                    {"X","O","O","#","O","X"},
                                    {"X","X","X","X","X","X"}};
    // grid = {{"X","X","X","X","X"},{"X","*","X","O","X"},{"X","O","X","#","X"},{"X","X","X","X","X"}};
    grid = {{"#","O","O","O","O","O","O","O"},
            {"O","O","O","O","O","O","O","O"},
            {"O","O","#","#","O","O","O","O"},
            {"O","O","#","O","X","O","O","O"},
            {"O","O","O","O","O","O","#","O"},
            {"O","O","O","#","*","O","O","O"},
            {"O","O","O","O","O","O","O","O"}};
    grid = {{"O","O","X","O","O","O","O"},
            {"X","X","O","O","X","O","O"},
            {"O","X","X","O","X","O","O"},
            {"O","O","O","O","O","O","O"},
            {"O","O","O","O","O","O","O"},
            {"O","O","O","O","O","X","O"},
            {"O","O","O","O","O","O","O"},
            {"O","O","O","O","O","X","O"},
            {"O","O","*","O","O","X","O"}};
    Solution s1;
    cout << s1.getFood(grid) << endl;
    return 0;
}
