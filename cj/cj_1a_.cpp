#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main(int argc, char const *argv[])
{
    int t, n, start, last, minimum, val;
    cin >> t;
    int i, j, prev, count;
    for(i=0;i<t;i++){
        cin >> n;
        vector<int> sweet(n);
        for(j=0;j<n;j++){
            cin >> sweet[j];
        }
        start = 0; last=n-1;
        count = 0; prev=0; val = -1;
        while(start <= last){
            if(sweet[start]<=sweet[last]){
                val = sweet[start];
                start+=1;
            } else{
                val = sweet[last];
                last-=1;
            }
            if(val >= prev){
                count +=1;
                prev = val;
            }
        }
        cout << "Case #" <<i+1 << ": " << count << endl;
        sweet.clear();
    }
    return 0;
}

void temp(){
    /*   if(sweet[start] >= prev && sweet[last]>=prev){
        if(sweet[start]< sweet[last]){
            count+=1;
            prev=sweet[start];
            start+=1;
        } else if (sweet[last] <= sweet[start]){
            count+=1;
            prev=sweet[last];
            last -=1;
        }
    } else if(sweet[start] >= prev){
        prev = sweet[start];
        start +=1;
        count+=1;
    } else if(sweet[last] >= prev){
        prev = sweet[last];
        last-=1;
        count +=1;
    } else{
        break;
    }   */
}