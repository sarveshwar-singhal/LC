#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int mini = INT32_MAX;

void doMove(int i, int j, int move, vector<vector<int>> &grid){
    //base case
    if(i==(grid.size()-1) and j==(grid[0].size()-1)){
        mini = min(mini, move);
        return;
    }

    if(i >= grid.size() or j>=grid[0].size() or grid[i][j] == 0){
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

class a{
    int x;
public:
    a(int num){
        x = num;
    }

    void print(){
        cout << "value of x is: " << x << endl;
    }
};

int main(int argc, char const *argv[])
{
    // cout << int('1') << endl;
    a var1(10);
    a var2{20};
    // var1.print();
    // var2.print();
    unsigned int n, m;
    // cin >> n >> m;
    n = 5, m=4;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    // unordered_map<pair<int, int>, vector<int>> dist;
    // unordered_map<pair<int, int>, int> dist;
    vector<vector<vector<int>>> rec(n, vector<vector<int>>(m, vector<int>(4, INT32_MAX)));

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
    for(auto x: rec){
        for(auto y: x){
            for(auto z: y){
                cout << z << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    // doMove(0, 0, 0, grid);
    if(mini == INT32_MAX) mini = -1;
    cout << mini << endl;
    return 0;
}
