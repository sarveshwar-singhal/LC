#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        // sort(tasks.begin(), tasks.end());
        int i;
        map<int, int> score;
        for(i=0;i<tasks.size();i++){
            if(score.find(tasks[i]) != score.end()){
                score[tasks[i]] +=1;
            } else{
                score[tasks[i]] = 1;
            }
        }
        int key, value, count, out;
        count = 0;
        for(auto pair: score){
            // key = pair.first;
            value = pair.second;
            out = find_match(value);
            if(out == -1){
                count = -1;
                break;
            }
            count += out;

        }
        return count;
    }

    int find_match(int x){
        int a, b;
        if(x<2){
            return -1;
        } else if(x==2){
            return 1;
        } else if(x==3){
            return 1;
        }
        int i;
        a = x/3;
        b = x%3;
        while(a>=0 && b>=0){
            if(b%2==0){
                return a + b/2;
            } else{
                a -=1;
                b+=3;
            }
        }
        return a + b/2;
    }
};


int main(int argc, char const *argv[])
{
    Solution s1;
    string s = "00000000";
    vector<int> x = {2,2,3,3,2,4,4,4,4,4};
    x= {5,5,5,5};
    int k;
    k = 3;
    // s="this is";
    cout << s1.minimumRounds(x) << endl;
    // cout << to_string(48) << endl;
    return 0;
}
