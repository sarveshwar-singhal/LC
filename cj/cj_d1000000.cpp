#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
public:
    void count(){
        int T;
        int N;
        int i, j;
        int count, pos;
        cin >> T;
        for(i=0;i<T;i++){
            cin >> N;
            int arr[N] = {0};
            for(j=0;j<N;j++){
                cin >> arr[j];
            }
            sort(arr, arr+N);
            count = 0; pos = 0;
            for(j=0;j<N;j++){
                if(arr[j]>=pos+1){
                    count++;
                    pos++;
                }
            }
            cout << "Case #"<<i+1<<": "<<count << endl;

        }
    }
};

int main(int argc, char const *argv[]){
    Solution s1;
    s1.count();
}


void rough(){
    // for(j=0;j<N;j++){
    //     cout << arr[j] << " ";
    // }
    // cout << endl;
}