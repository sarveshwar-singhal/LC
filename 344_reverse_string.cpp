#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int first, last;
        first = 0;
        last = s.size() -1;
        char ch;
        while(first<last){
            ch=s[first];
            s[first]=s[last];
            s[last]= ch;
            first++;
            last--;
        }
        
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
