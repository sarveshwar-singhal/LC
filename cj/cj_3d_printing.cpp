#include<iostream>
using namespace std;

class Solution{
public:
    void Printing_3d(){
        int T;
        // int C[3], M[3], Y[3], K[3];
        int C, M, Y, K;
        int min_c = INT32_MAX, min_m= INT32_MAX, min_y= INT32_MAX, min_k= INT32_MAX;
        int total = 1000000, sum;
        int avail[4], pos, val;
        int i, j;
        cin >> T;
        for(i=0;i<T;i++){
            min_c = INT32_MAX, min_m= INT32_MAX, min_y= INT32_MAX, min_k= INT32_MAX;
            int out[4] = {0};
            for(j=0;j<3;j++){
                cin >> C >> M >> Y >> K;
                min_c = min(min_c, C);
                min_m = min(min_m, M);
                min_y = min(min_y, Y);
                min_k = min(min_k, K);
            }

            if(min_c+min_m+min_y+min_k < total){
                cout << "Case #" << i+1 <<": IMPOSSIBLE" << endl;
            } else if (min_c+min_m+min_y+min_k == total){
                cout << "Case #" << i+1 <<": "<<min_c << " "<<min_m << " " << min_y << " " << min_k << endl; 
            } else{
                avail[0] = min_c;
                avail[1] = min_m;
                avail[2] = min_y;
                avail[3] = min_k;
                sum = 0;
                while(true){
                    pos = max_position(avail);
                    val = min(avail[pos], total-sum);
                    avail[pos] -= val;
                    out[pos] = val;
                    sum += val;
                    if(sum==total){
                        break;
                    }
                }
                cout << "Case #" << i+1 <<": "<<out[0] << " "<<out[1] << " " << out[2] << " " << out[3] << endl; 
            }
        }
    }

    int max_position(int avail[]){
        int max=0;
        int j;
        for(j=1;j<4;j++){
            if(avail[j]>avail[max]){
                max = j;
            }
        }
        return max;
    }
};

int main(int argc, char const *argv[]){
    Solution s1;
    s1.Printing_3d();
}