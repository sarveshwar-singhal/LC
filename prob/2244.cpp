#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
// class b{

// };

// class Solution : public b{

// };

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        for(auto val: tasks){
            if(freq.find(val) != freq.end()){
                freq[val] +=1;
            } else{
                freq[val] = 1;
            }
        }
        int ans = 0, num, two, three;
        for(pair<int, int> x : freq){
            if(x.second < 2){
                return -1;
            }
            num = x.second;
            three = num/3;
            num %= 3;
            two = num/2;
            num %= 2;
            while(num > 0){
                three -=1;
                num += 3 + two*2;
                two = num/2;
                num %= 2;
            }
            ans += three + two;
        }
        return ans;
    }
};

int main(){
    vector<int> tasks = {2,2,3,3,2,4,4,4,4,4};
    tasks = {2, 3, 3};
    Solution s1;
    cout << s1.minimumRounds(tasks) << endl;
    return 0;
}