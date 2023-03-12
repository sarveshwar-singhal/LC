#include<vector>
using namespace std;

template<typename T>
class Vector : public vector<T>{
    vector<T> arr;
public:

    int size(){
        return this->size();
    }

    bool operator ==(Vector<T> obj){
        if(this->size() != obj.size()) return false;

        for(int i=0;i<obj.size();i++){
            if(this->arr[i] != obj[i]) return false;
        }
        return true;
    }
};