#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:

    int countCollisions(string directions) {
        int i;
        stack<char> dir;
        int count = 0;
        char temp, push_char;
        for(i=0;i<directions[i];i++){
            if(dir.empty()){
                dir.push(directions[i]);
            } else{
                push_char = ' ';
                cout << "else" << endl;
                while(!(dir.empty())){
                    temp = dir.top();
                    if(temp == 'R' && directions[i]=='L'){
                        count+=2;
                        push_char= 'S';
                    } else if(temp == 'R' && directions[i]=='S'){
                        count+=1;
                        push_char= 'S';
                    } else if(temp=='S' && directions[i]=='L'){
                        count+=1;
                        push_char= 'S';
                    } else{
                        dir.push(temp);
                        if(temp!='S')
                            push_char = directions[i];
                        break;
                    }
                }
                if(push_char!=' ')
                    dir.push(push_char);
            }

        }
        return count;
    }

    int countCollisions1(string directions) {
        if(directions.length()<2){
            return 0;
        }
        int count=0, i, prev_count=-1;
        vector<int> index;
        for(i=0;i<directions.length();i++){
            index.push_back(i);
        }
        while(true){
            for(i=0;i<index.size();i++){
                if(directions[index[i]] =='S'){
                    continue;
                }else if(directions[index[i]]=='L'){
                    if(i==0) continue;
                    if(directions[index[i-1]]=='R'){
                        count+=2;
                        directions[index[i]] = 'S';
                        directions[index[i-1]] = 'S';
                    } else if(directions[index[i-1]]=='S'){
                        count+=1;
                        directions[index[i]] = 'S';
                    }
                }else if(directions[index[i]] == 'R'){
                    if(i==index.size()-1) continue;
                    if(directions[index[i+1]]=='L'){
                        count+=2;
                        directions[index[i+1]]='S';
                        directions[index[i]]='S';
                    } else if(directions[index[i+1]]=='S'){
                        count+=1;
                        directions[index[i]]='S';
                    }
                }
            }
            if(prev_count!=count){
                prev_count = count;
            } else{
                break;
            }
        }
        return prev_count;
    }
};

int main(int argc, char const *argv[])
{
    Solution s1;
    vector<int> vec = {1,2,3};
    int ans;
    string s = "SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR";
    ans = s1.countCollisions(s);
    cout << ans << endl;
    return 0;
}
