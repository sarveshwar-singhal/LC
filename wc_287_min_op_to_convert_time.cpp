#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int convertTime(string current, string correct) {
        int current_hr, current_min, correct_hr, correct_min;
        int curr, corr, diff, op;
        current_hr =  stoi(current.substr(0, 2));
        current_min = stoi(current.substr(3, 2));
        correct_hr =  stoi(correct.substr(0, 2));
        correct_min = stoi(correct.substr(3, 2));
        curr = current_hr * 60 + current_min;
        corr = correct_hr * 60 + correct_min;
        diff = corr - curr;
        op = 0;
        op = (int) diff/60;
        diff = diff%60;
        op += (int) diff/15;
        diff = diff%15;
        op += (int) diff/5;
        diff = diff%5;
        op += (int) diff/1;
        return op;
    }
};

int main(int argc, char const *argv[]){
    Solution s1;
    string current, correct;
    current = "02:30"; correct = "04:35";
    cout << s1.convertTime(current, correct) << endl;
}