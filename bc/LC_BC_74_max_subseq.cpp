#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long count = 0;
        vector<int> pos1, pos2;
        int i,j;
        for(i=0;i<text.length();i++){
            if(text[i] == pattern[0]){
                pos1.push_back(i);
            }
            if(text[i] == pattern[1]){
                pos2.push_back(i);
            }
        }
        long long int count1=0, count2=0;
        if(pos2.size()>0){
            count1+= pos2.size();
        }
        int temp_count=0, last = pos2.size() -1;
        if(pos1.size()>0){
            if(pos2.size()>0){
                while(last > -1){
                    if(pos1[pos1.size()-1]<pos2[last]){
                        break;
                    }
                    last -= 1;
                }
                
                for(i=0;i<pos1.size();i++){
                    for(j=0;j<pos2.size();j++){
                        if(pos1[i]<pos2[j]){
                            count1+=1;
                        }
                    }
                }
            }
        }
        if(pos1.size()>0){
            count2+=pos1.size();
        }
        if(pos2.size()>0){
            if(pos1.size()>0){
                for(i=0;i<pos2.size();i++){
                    for(j=0;j<pos1.size();j++){
                        if(pos2[i]>pos1[j]){
                            count2+=1;
                        }
                    }
                }
            }
        }
        return max(count1, count2);
    }
};

int main(int argc, char const *argv[])
{
    string s = "this is string";
    return 0;
}
