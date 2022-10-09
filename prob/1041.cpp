#include<iostream>
using namespace std;

class Solution {
    void applyRotations(int &x, int &y, int &dir, string &instructions){
        int i;
        for(i=0;i<instructions.size();i++){
            if(instructions[i] == 'G'){
                if(dir == 0){
                    x +=1;
                }
                if(dir==1){
                    y+=1;
                }
                if(dir==2){
                    x-=1;
                }
                if(dir == 3){
                    y-=1;
                }
                continue;
            }
            if(instructions[i] == 'L'){
                dir +=1;
                dir %= 4;
                continue;
            }
            if(instructions[i] == 'R'){
                dir -=1;
                if(dir < 0){
                    dir = 3;
                }
            }
        }
    }

public:
    bool isRobotBounded(string instructions) {
        int dir = 1;
        int i, j;
        int x = 0, y=0;
        // applyRotations(x, y, dir, instructions);
        // if(x!=0 or y!=0){
        //     return false;
        // }
        for(i=0;i<4;i++){
            applyRotations(x, y, dir, instructions);
        }
        if(x==0 && y == 0 && dir == 1){
            return true;
        }
        return false;
    }
};

int main(){

    Solution s1;
    string instructions = "GGLLGG";
    // instructions = "GL";
    cout << s1.isRobotBounded(instructions) << endl;
    return 0;
}