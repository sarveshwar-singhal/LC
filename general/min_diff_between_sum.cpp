#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//an individual should work on different type of task every day. max no of days till which individual can work on different tasks.
//task types = [7, 3, 4]; task[i] = no of task of that particular type.
//indv can work for 14 days 0 1 0 1 0 1 0 2 0 2 0 2 0 2 -> one of the combination.
//eg 2: task types = [7, 3, 5]; task[i] = no of task of that particular type.
//indv can work for 15 days 0 1 0 1 0 1 2 1 2 1 2 1 2 1 2 -> one of the combination.

int countMaxDays(vector<int> &tasks){

    int left=0, right=tasks.size()-1, lsum=0, rsum=0, mxDays=0;
    sort(tasks.begin(), tasks.end());
    while(left<right){
        lsum += tasks[left];
        rsum += tasks[right];
        mxDays = 2 * min(lsum, rsum) + (lsum!=rsum?1:0);
        if(lsum < rsum){
            left++;
            rsum -= tasks[right];
        } else if (lsum > rsum){
            right-=1;
            lsum -= tasks[left];
        } else {
            left+=1;
            right-=1;
        }
    }
    return mxDays;
}

int main(){
    vector<int> tasks = {7, 3, 4};
    tasks = {7, 3, 5};
    tasks = {2, 3, 4, 7};
    tasks = {7, 2, 3};
    tasks = {2, 6, 1};
    tasks = {2, 2, 2, 2};
    cout << countMaxDays(tasks) << endl;
    return 0;
}