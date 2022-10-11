#include<iostream>
#include<ctime>
#include<vector>
using namespace std;

class Solution1 {
    int cnt;

    void ways(string &s, int i){
        //base case
        if(i >= s.length()){
            cnt +=1;
            return;
        }

        //rec case
        string tmp = s.substr(i,1);
        if(stoi(tmp) < 1){
            return;
        } else{
            ways(s, i+1);
        }
        if(i<s.length()-1){
            tmp = s.substr(i, 2);
            if(stoi(tmp) > 26){
                return;
            } else {
                ways(s, i+2);
            }
        }
    }
public:

    int numDecodings(string s) {
        this->cnt = 0;
        ways(s, 0);
        cout << this->cnt << endl;
        return this->cnt;
    }
};

//working solution - minor improvements needed
class Solution2 {
    vector<int> arr;

    int countWays(string &s, int i){
        //base case
        if(i>s.length()){
            return 0;
        }
        if(i==s.length()){
            // cout << "inside = " << endl;
            this->arr[i] = 1;
            return 1;
        }

        if(this->arr[i] != 0){
            // cout << "return arr[i] " << endl;
            return arr[i];
        }
        //rec case
        //single char
        if(stoi(s.substr(i, 1)) > 0){
            this->arr[i] += countWays(s, i+1);
        } else{
            return this->arr[i];
        }
        //multiple char
        if(stoi(s.substr(i, 2)) < 27){
            this->arr[i] += countWays(s, i+2);
        } else{
            return this->arr[i];
        }
        return this->arr[i];
    }
public:
    int numDecodings(string s) {
        arr = vector<int>((s.size()+1), 0);
        countWays(s, 0);
        cout << this->arr[0] << endl;
        return this->arr[0];
    }
};

class Solution {
    vector<int> arr;

    int countWays(string &s, int i){
        //base case
        if(i>s.length()){
            return 0;
        }
        if(i==s.length()){
            // cout << "inside = " << endl;
            this->arr[i] = 1;
            return 1;
        }

        if(this->arr[i] != 0){
            // cout << "return arr[i] " << endl;
            return arr[i];
        }
        //rec case
        //single char
        if(stoi(s.substr(i, 1)) > 0){
            this->arr[i] += countWays(s, i+1);
        } else{
            return 0;
        }
        //multiple char
        if(stoi(s.substr(i, 2)) < 27){
            this->arr[i] += countWays(s, i+2);
        }
        return this->arr[i];
    }
public:
    int numDecodings(string s) {
        arr = vector<int>((s.size()+1), 0);
        countWays(s, 0);
        // cout << this->arr[0] << endl;
        return this->arr[0];
    }
};

void check_bounds(){
    int i =0;
    long l = 0;
    int j;
    cout << int('A') << endl;
    for(j=0;j<100000;j++){
        i += (90001 + j);
        l += (90001 + j);
    }
    cout << i << endl;
    cout << l << endl;
}

int main(){
    auto t1 = clock();
    string s = "abcdef";
    string x = s.substr(2, 2);
    Solution s1;
    string decode = "11106";
    // decode = "12";
    // decode = "06";
    decode = "111111111111111111111111111111111111111111111";
    decode = "1201234";
    // t1 = clock();
    Solution1().numDecodings(decode);
    s1.numDecodings(decode);
    auto t2 = clock();
    cout << t2 - t2 << endl;
    return 0;
}

void rough(){
    for(int i=0;i<10;i++){
        cout << i << " ";
    }
    cout << endl;
}