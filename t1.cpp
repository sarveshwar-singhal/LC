#include<iostream>
#include<vector>
using namespace std;

//function to check for 2d vectors
void vector2d(){
    vector<vector<int>> vec2d;
    vec2d = {{1,2,3},{2,3,4},{3,4,5}};
    
}

int main(int argc, char const *argv[])
{
    int a= 10;
    cout << a << "    " << &a << endl;
    a = 20;
    cout << a << "    " << &a << endl;
    int arr[3] = {0};
    int i;
    for(i=0;i<3;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
