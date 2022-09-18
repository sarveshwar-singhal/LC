#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    //trying stack approach having indexes of unused element.
    int minGroups4(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end());
        int sz = intervals.size(), sz1;
        int i, j;
        int cnt=0, done = 0, left = 0, right = 0;
        queue<int> unused;
        for(i=0;i<sz;i++) unused.push(i);
        while(true){
            left = INT32_MAX; right = 0;
            sz1 = unused.size();
            for(i=0;i<sz1;i++){
                j = unused.front();
                unused.pop();
                if(intervals[j][0] > right){
                    right = intervals[j][1];
                    done+=1;
                    continue;
                } else if(intervals[j][1])
                unused.push(j);
            }
            cnt+=1;
            if(done==sz) break;
        }
        return cnt;
    }

    //trying with single row maintaining used/unused - nothing major changed. still TLE
    int minGroups3(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int sz = intervals.size();
        vector<int> used(sz, 0);
        int i, j;
        int cnt=0, done = 0, prev = 0;

        for(i=0;i<sz;i++){
            prev = 0;
            for(j=0;j<sz;j++){
                if(used[j]==1){
                    continue;
                }
                if(used[j]==0 && intervals[j][0] > prev){
                    prev = intervals[j][1];
                    used[j] = 1;
                    done+=1;
                }
            }
            cnt+=1;
            if(done==sz) break;
        }
        return cnt;
    }

    //some test cases passes. TLE for some cases
    //to avoid size limit exceeeded not declaring n*n at one, rather appending after each iteration
    int minGroups2(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int sz = intervals.size();
        // vector<vector<int>> arr(intervals.size()+1, vector<int>(intervals.size(), 0));
        vector<vector<int>> arr(1, vector<int>(sz, 0));
        vector<int> curr_row(sz, 0);
        // int arr[sz+1][sz] = {0};
        int prev;
        int done = 0;
        for(int i=1;i<=sz;i++){
            prev = 0;
            for(int j=0;j<sz;j++){
                if(arr[i-1][j] == 1){
                    // curr_row.push_back(1);
                    curr_row[j] = 1;
                    // arr[i][j] = 1;
                    continue;
                }
                if(intervals[j][0] > prev){
                    // arr[i][j] = 1;
                    // curr_row.push_back(1);
                    curr_row[j] =1;
                    prev = intervals[j][1];
                    done +=1;
                }
            }
            arr.push_back(curr_row);
            curr_row=vector<int>(sz, 0);
            // curr_row.erase();
            if(done==sz) break;
        }
        return arr.size() - 1;
    }

    //better than 1, but memory limit exceeded
    int minGroups1(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> arr(intervals.size()+1, vector<int>(intervals.size(), 0));
        int sz = intervals.size();
        // int arr[sz+1][sz] = {0};
        int prev;
        int done = 0;
        int cnt = 0;
        for(int i=1;i<=sz;i++){
            prev = 0;
            for(int j=0;j<sz;j++){
                if(arr[i-1][j] == 1){
                    arr[i][j] = 1;
                    continue;
                }
                if(intervals[j][0] > prev){
                    arr[i][j] = 1;
                    prev = intervals[j][1];
                    done +=1;
                }
            }
            cnt +=1;
            if(done==sz) break;
        }
        return cnt;
        int i;
        for(i=sz;i>0;i--){
            if(arr[i][0] == 1){
                return i;
                break;
            }
        }
        return i;
        /*  for(int i=1;i<=intervals.size();i++){
            for(int j=0;j<intervals.size();j++){
                if((arr[i][j] & 1) == 1){
                    cnt+=1;
                    break;
                }
            }
        }   */
        // return cnt;
    }

    //some test case passes; TLE
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> taken(intervals.size(), 0);
        int ans = 0;
        int prev = 0;
        bool done;
        int min_i = 0;
        for(int i=0;i<intervals.size();i++){
            prev = 0;
            done = false;
            min_i = intervals.size();
            for(int j=i;j<intervals.size();j++){
                if(taken[j]==0 && intervals[j][0] > prev){
                    taken[j] = 1;
                    prev = intervals[j][1];
                    done = true;
                }else if(taken[j] == 0){
                    min_i = min(j, min_i);
                }
            }
            if(done){
                ans +=1;
            }
            i = min_i-1;
        }
        return ans;
    }
};

void temp_check(){
    queue<int> arr;
    arr.push(1);
    arr.push(2);
    arr.push(3);
    arr.push(4);
    arr.push(5);
    for(int i=0;i<arr.size();i++){
        cout << arr.back() << endl;
        arr.pop();
    }
}


int main(int argc, char const *argv[])
{
    vector<vector<int>> intervals = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
    Solution s1;
    // temp_check();
    cout << s1.minGroups4(intervals) << endl;
    return 0;
}
