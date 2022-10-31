#include<iostream>
#include<vector>
using namespace std;

int mini = INT32_MAX;

void doMove(int i, int j, int move, vector<vector<int>> &grid){
    //base case
    if(i >= grid.size() or j>=grid[0].size() or grid[i][j] == 0){
        return;
    }

    if(i==(grid.size()-1) and j==(grid[0].size()-1)){
        mini = min(mini, move);
        return;
    }

    //rec case
    int tmp = grid[i][j];
    grid[i][j] = 0;
    doMove(i+tmp, j, move+1, grid);
    doMove(i, j+tmp, move+1, grid);
    doMove(i-tmp, j, move+1, grid);
    doMove(i, j-tmp, move+1, grid);
    grid[i][j] = tmp;
    return;
}

int main(int argc, char const *argv[])
{
    // cout << int('1') << endl;
    unsigned int n, m;
    // cin >> n >> m;
    n = 5, n=4;
    vector<vector<int>> grid{n, vector<int>(m, 0)};
    int i, j;
    string s = "";
    /*  getline(cin, s);
    for(i=0;i<n;i++){
        getline(cin, s);
        // cout << s << endl;
        for(j=0;j<s.length();j++){
            // char c = s[j];
            // grid[i][j] = stoi("ab");
            // grid[i][j] = stoi(s[j]);
            grid[i][j] = stoi(s.substr(j, 1));
            // grid[i][j] = stoi(char(s[j]));
            // grid[i][j] = int(s[j]) - 48;
            // grid[i][j] = stoi(c);
            // grid[i][j] = s[j] - 48;
        }
    }   */
    grid = {{2,1,2,0},{1,2,0,3},{3,1,1,3},{1,1,2,0},{1,1,1,0}};
    for(auto x: grid){
        for(auto y: x){
            cout << y << " ";
        }
        cout << endl;
    }
    doMove(0, 0, 0, grid);
    if(mini == INT32_MAX) mini = -1;
    cout << mini << endl;
    return 0;
}
