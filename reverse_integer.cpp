#include<iostream>
#include<vector>
// #include<math.h>
// #include<cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev_num;
        rev_num = 0;
        int temp, max_num, min_num;
        max_num = INT32_MAX, min_num=INT32_MIN;
        while(x){
            temp = x%10;
            if(rev_num>max_num/10 ||(rev_num == max_num && temp>7)){
                return 0;
            }
            if(rev_num<min_num/10 || (rev_num==min_num && temp<-8)){
                return 0;
            }
            rev_num = rev_num*10 + temp;
            x = x/10;
        }
        return rev_num;
    }

    int try1(int x){
        if(x>2147447412 || x<-2147447412){
            return 0;
        }
        int temp = x;
        int len = 0;
        -2147483412;
        while(temp!=0){
            len++;
            temp = temp/10;
        }
        if(len>9){
            if(x%100000 > 47412 || x%100000 < -47412){
                return 0;
            }
        }
        temp = x;
        x = abs(x);
        int num=0;
        while(x>0){
            num = num*10 + x%10;
            x = x/10;
        }
        if(temp<0){
            num = -num;
        }
        return num;
    }

    int try2(int x){
        if(x==0){
            return 0;
        }
        int num1;
        vector<int> max_value, min_value;
        num1 = INT32_MAX;
        while(num1>0){
            max_value.push_back(num1%10);
            num1 /= 10;
        }
        num1=INT32_MIN;
        while(num1){
            min_value.push_back(num1%10);
            num1 /= 10;
        }
        while(x){
            if(x%10==0){
                x=x/10;
            } else{
                break;
            }
        }
        int len_x, y;
        y = x, len_x=0;
        while(y){
            y /=10;
            len_x += 1;
        }
        y=x;
        int rev_num;
        // cout << y << endl;
        // cout << x << endl;
        // cout << "len_x " << len_x << endl;
        rev_num=0;
        if(x>0){
            while(y){
                if(y%10>max_value[len_x-1]){
                    cout << "error" << endl;
                    return 0;
                } else{
                    rev_num = rev_num*10 + y%10;
                    y = y/10;
                }
                len_x -=1;
            }
        } else{
            while(y){
                if(y%10<min_value[len_x-1]){
                    return 0;
                } else{
                    rev_num = rev_num*10 + y%10;
                    y /=10;
                }
                len_x -=1;
            }
        }
        return rev_num;
    }

    int try3(int x){
        int rev_num = 0;
        try{
            while(x){
                rev_num = rev_num*10 + x%10;
                x /= 10;
            }
        }catch(exception e){
            return 0;
        }
        return rev_num;
    }
};

int main(int argc, char const *argv[])
{
    int x = INT32_MAX;
    x = -123, x=90000, x= 2534236469;
    // cout << x << endl;
    // cout << INT32_MIN << endl;
    Solution s1;
    int val = s1.reverse(x);
    cout << val << endl;
    return 0;
}
