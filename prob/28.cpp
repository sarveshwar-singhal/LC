#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // return haystack.find_first_of(needle);
        return haystack.find(needle);
    }
};

int main(int argc, char const *argv[])
{
    string haystack = "sadbutsad", needle = "sad";
    Solution s1;
    cout << s1.strStr(haystack, needle) << endl;
    return 0;
}
