#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class TicTacToe {
    vector<vector<int>> arr;
    int n;
public:
    TicTacToe(int num) {
        arr = vector<vector<int>>(num, vector<int>(num, 0));
        this->n = num;
    }
    
    int move(int row, int col, int player) {
        arr[row][col] = player;
        int i;
        bool win = true;
        for(i=0;i<this->n;i++){
            if(arr[i][col] != player){
                win = false;
                break;
            }
        }
        if(win) return player;
        win = true;
        for(i=0;i<this->n;i++){
            if(arr[row][i] != player){
                win = false;
                break;
            }
        }
        if(win) return player;
        if(row == col){
            win = true;
            for(i=0;i<this->n;i++){
                if(arr[i][i] != player){
                    win = false;
                    break;
                }
            }
            if(win) return player;
        }

        if(row+col == n){
            win = true;
            for(i=n-1;i>=0;i--){
                if(arr[i][n-i] != player){
                    win = false;
                    break;
                }
            }
            if(win) return player;
        }
        return 0;
    }
};

/// @brief helper function for sorting 2-d vector array in ascending order based on last idx / 2nd value or idx 1;
/// @param a 
/// @param b 
/// @return returns boolean value.
bool lastEle(vector<int> a, vector<int> b){
    // return a[1] < b[1];
    return a.back() < b.back();
}

int main(){
    vector<vector<int>> arr = {{3, 1}, {1, 3}, {3, 2}, {1, 2}};
    sort(arr.begin(), arr.end(), lastEle);
    /*  for(auto x: arr){
        cout << x[0] << "," << x[1] << "  ";
    }
    cout << endl;   */
    int n = 2;
    TicTacToe ttt(n);
    vector<vector<int>> move = {{0,0,2},{1,1,1},{0,1,2}};
    for(int i=0;i<move.size();i++){
        cout << ttt.move(move[i][0], move[i][1], move[i][2]) << endl;
    }
    return 0;
}