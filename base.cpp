#include<iostream>
using namespace std;

class Check{

public:
    void checkFloatOperation(){
        float f1 = 0.1, f2 = 0.3;
        cout << f1+f2 << endl;
        cout << 1 - 0.9 << endl;
    }

    

};

int main(){
    Check c1;
    c1.checkFloatOperation();
    return 0;
}