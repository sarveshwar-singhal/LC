#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int i, temp;
        int train;
        train = 0;
        temp = 0;
        for(i=0;i<energy.size();i++){
            temp += energy[i];
        }
        if(initialEnergy <= temp){
            train += temp - initialEnergy + 1;
        }
        // cout << train << endl;
        int mpos;
        mpos = 0;
        for(i=1;i<experience.size();i++){
            if(experience[mpos] < experience[i]){
                mpos = i;
            }
        }
        // cout << mpos << endl;
        temp = 0;
        for(i=0;i<mpos;i++){
            temp += experience[i];
        }
        if(experience[mpos] - temp - initialExperience > 0){
            train += experience[mpos] - temp -initialExperience + 1;
        } else if(experience[mpos] - temp - initialExperience == 0){
            train++;
        }
        return train;
    }

    //incorrect solution
    int minNumberOfHours1(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int i, temp;
        int train;
        train = 0;
        temp = 0;
        for(i=0;i<energy.size();i++){
            temp += energy[i];
        }
        if(initialEnergy < temp){
            train += temp - initialEnergy + 1;
        } else if(initialEnergy == temp){
            train += 1;
        }
        int mpos = 0;
        for(i=1;i<experience.size();i++){
            if(experience[mpos] < experience[i]){
                mpos = i;
            }
        }
        temp = 0;
        for(i=0;i<mpos;i++){
            temp+= experience[i];
        }
        for(i=0;i<experience.size();i++){
            if(initialExperience < experience[i]){
                train += experience[i] - initialExperience + 1;
                initialExperience = experience[i] + 1;
            } else if(initialExperience == experience[i]){
                train += 1;
                initialExperience = experience[i] + 1;
            } else{
                initialExperience += experience[i];
            }
        }
        return train;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution s1;
    int initialEng, initialExp;
    vector<int> energy, experience;
    initialEng = 5; initialExp = 3;
    energy = {1, 4, 3, 2};
    experience = {2, 6, 3, 1};
    int ans;
    ans = s1.minNumberOfHours(initialEng, initialExp, energy, experience);
    cout << ans << endl;
    return 0;
}
