#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void rough();

class Solution {
public:
    vector<vector<int>> meet;
    int rooms;
    
    void readData(string filename){
        fstream fp, fout;
        fp.open(filename, ios::in);
        // fout.open("format.txt", ios::in | ios::out | ios::app);
        if(fp.is_open()){
            string line = "";
            string tmp = "";
            char c;
            int i1, i2;
            // string line = "";
            getline(fp,line);
            // cout << l1.length() << endl;
            // cout << l1 << endl;
            rooms = stoi(line);
            stack<char> format;
            int j, k;
            // cout << rooms << endl;
            while(getline(fp, line)){
                for(int i=0;i<line.length();i++){
                    tmp = "";
                    if(line[i] == ']'){
                        while(true){
                            c = format.top();
                            format.pop();
                            if(c==','){
                                // reverse(tmp);
                                j=0;k=tmp.size()-1;
                                while(j<k){
                                    swap(tmp[j], tmp[k]);
                                    j+=1;
                                    k-=1;
                                }
                                if(tmp == ""){
                                    break;
                                }
                                i2 = stoi(tmp);
                                tmp = "";
                                continue;
                            }
                            if(c=='['){
                                j=0;k=tmp.size()-1;
                                while(j<k){
                                    swap(tmp[j], tmp[k]);
                                    j+=1;
                                    k-=1;
                                }
                                // cout << tmp << endl;
                                i1 = stoi(tmp);
                                tmp = "";
                                break;
                            }
                            tmp += c;
                        }
                        meet.push_back({i1, i2});
                    } else{
                        format.push(line[i]);
                    }
                }
            }
            fp.close();
        } else{
            cout << "Unable to open file" << endl;
        }
    }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        // vector<unsigned long long> lastTime(n, 0);
        unsigned long long lastTime[n] = {0};
        // vector<unsigned int> freq(n, 0);
        unsigned long long freq[n] = {0};
        unsigned long long pos_min;
        sort(meetings.begin(), meetings.end());
        int i;
        int pos, val_min;
        for(auto x: meetings){
            val_min = INT32_MAX;
            //value minimum
            for(i=0;i<n;i++){
                if(x[0]>=lastTime[i]){
                    val_min = i;
                    break;
                }
            }
            //pos min
            pos = 0;
            pos_min = lastTime[0];
            for(i=1;i<n;i++){
                if(pos_min > lastTime[i]){
                    pos_min = lastTime[i];
                    pos = i;
                }
            }
            pos = min(pos, val_min);
            // cout << "min index found" << endl;
            if(lastTime[pos] == 0){
                lastTime[pos] = x[1];
            } else{ 
                if(x[0] >= lastTime[pos]){
                    lastTime[pos] = x[1];
                } else{
                    lastTime[pos] += (x[1] - x[0]);
                }
            }
            freq[pos] +=1;
        }
        // cout << "value of pos now " << pos << endl;
        pos = 0;
        int maxi = freq[0];
        for(i=1;i<n;i++){
            if(maxi < freq[i]){
                maxi = freq[i];
                pos = i;
            }
        }
        return pos;
    }

};

void checkStringAppend(){
    cout << "trying to append value from left" <<endl;
    string s = "";
    for(int i=97; i<=100;i++){
        // s.begin() = char(i);
        // s.
    }
    cout << s << endl;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> meetings = {{0,10},{1,5},{2,7},{3,4}};
    int n;
    n=3;
    meetings = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};
    // meetings.push_back({7, 19});
    // meetings = {{0, 10}, {1, 2}, {12, 14}, {13, 15}};
    // meetings = {{18, 19}, {3, 12}, {17, 19}, {2, 13}, {7, 10}};
    Solution s1;
    string filename = "/home/new/vscode/DsaEssentials/self/2402_input.txt";
    s1.readData(filename);
    int ans;
    // cout << s1.rooms << endl;
    // ans = s1.mostBooked(s1.rooms, s1.meet);
    ans = s1.mostBooked(n, meetings);
    cout << ans << endl;
    // cout << s1.mostBooked(n, meetings) << endl;

    return 0;
}


void rough(){
    /*  for(i=0;i<lastTime.size();i++){
        if(mini > lastTime[i] && x[0] >= lastTime[i]){
            mini = lastTime[i];
            pos = i;
        }
    }   */
}