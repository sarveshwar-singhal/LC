#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:

    //not working
    void visit(vector<vector<int>> &conn, int i, int j){
        //base case
        if(j>=conn[0].size()){
            visit(conn, i+1, i+2);
            return;
        }

        if(i>=conn.size()){
            return;
        }
        //rec case
        int row, col;
        for(row=i;row<conn.size();row++){
            for(col=row;col<conn[0].size();col++){
                if(conn[row][col] & 1){
                    visit(conn, row, col+1);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int i, j;
        int cnt = 0;
        for(i=0;i<isConnected.size();i++){
            for(j=i;j<isConnected[0].size();j++){
                if(isConnected[i][j] & 1){
                    visit(isConnected, i, j);
                    cnt +=1;
                }
            }
        }
        return 0;
    }

    //working - can have improvements
    void find_neighbor(vector<vector<int>> &conn, int i, int j, set<int> &s1){
        //base case
        if(s1.size() == conn.size()){
            return;
        }

        //rec case
        int row = i, col;
        for(col=j;col<conn[0].size();col++){
            if(conn[row][col] ==1){
                conn[row][col] = 0;
                conn[col][row] = 0;
                if(s1.find(col) == s1.end()){
                    s1.insert(col);
                    find_neighbor(conn, col, 0, s1);
                }
            }
        }
    }

    int findCircleNum1(vector<vector<int>>& isConnected) {
        int i, j;
        int cnt = 0;
        set<int> s1;
        for(i=0;i<isConnected.size();i++){
            if(s1.find(i) == s1.end()){
                cnt +=1;
                find_neighbor(isConnected, i, 0, s1);
            }
        }
        cout << cnt << endl;
        return cnt;
    }

    void find_neighbor1(vector<vector<int>> &conn, int row, int col, vector<int> &done){

        int i = row, j;
        for(j=col;j<conn[0].size();j++){
            if(conn[i][j] == 1){
                conn[i][j] = 0;
                conn[j][i] = 0;
                find_neighbor1(conn, j, 0, done);
                done[j] = 1;
            }
        }
    }

    int findCircleNum2(vector<vector<int>> &isConnected){
        vector<int> done(isConnected.size(), 0);
        int i, j;
        int cnt =0;
        for(i=0;i<isConnected.size();i++){
            if(done[i] == 0){
                cnt +=1;
                find_neighbor1(isConnected, i, 0, done);
            }
        }
        cout << cnt << endl;
        return cnt;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> isConn = {{1,1,0},{1,1,0},{0,0,1}};
    isConn = {{1,0,0},{0,1,0},{0,0,1}};
    isConn = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    s1.findCircleNum2(isConn);
    return 0;
}