#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    void punched_card(){
        int T;
        int R,C;
        int i, j, k;
        string top, first, middle, bottom, out;
        cin >> T;
        for(i=0;i<T;i++){
            cin >> R >> C;
            top = "";
            top += "..+";
            for(j=0;j<C-1;j++){
                top += "-+";
            }
            first = ".";
            bottom = "+";
            middle = "|";
            for(j=0;j<C;j++){
                first += ".|";
                bottom += "-+";
                middle += ".|";
            }
            out = top + "\n" + first + "\n" + bottom + "\n";
            for(j=0;j<R-1;j++){
                out += middle + "\n" + bottom + "\n";
            }
            cout << "Case #" << i+1<<":"<<endl;
            cout << out;
        }
    }
};

int main(int argc, char const *argv[]){
    Solution s1;
    s1.punched_card();
}