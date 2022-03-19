#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        char ch, remove_char;
        int i, count;
        bool flow, ans = true;
        st.clear();
        if(s.length()&1==1){
            return false;
        }
        for(i=0;i<s.length();i++){
            ch=s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                flow = true;
            } else{
                flow = false;
            }
            if(flow){
                st.push_back(ch);
            }else{
                if(st.size()<1){
                    return false;
                }
                remove_char = st[st.size()-1];
                st.pop_back();
                count = remove_char + ch;
                if(!(count==81 || count == 184 || count == 248)){
                    return false;
                }
            }
        }
        if(st.size()>0){
            return false;
        }
        return true;
    }

    bool temp(char ch, vector<char> st){
        char remove_char;
        remove_char = st[st.size()-1];
        if(ch == ')'){
                    if(remove_char != '('){
                        return false;
                    }
                } else if(ch == '}'){
                    if(remove_char != '{'){
                        return false;
                    }
                } else if(ch == ']'){
                    if(remove_char != '['){
                        return false;
                    }
                }
    }
};