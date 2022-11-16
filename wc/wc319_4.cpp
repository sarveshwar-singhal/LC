#include<iostream>
using namespace std;

class Solution {
    int *arr;
public:

    void findMax(){

    }

    int maxPalindromes(string s, int k) {
        arr = new int(s.length());
        arr = {0};
        for(int i=0;i<s.length();i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
// 5.2 -> 1.04
// 6.4 -> 3.2

int main(){
    string s = "temporary";
    int k;
    k=4;
    Solution s1;
    s1.maxPalindromes(s, 4);
    return 0;
}