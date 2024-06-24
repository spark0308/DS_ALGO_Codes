#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<string, int> stones;
    map<string, string> powers;
    vector<string> colors = {"purple", "green", "blue", "orange", "red", "yellow"};

    powers.insert({"purple", "Power"});
    powers.insert({"green", "Time"});
    powers.insert({"blue", "Space"});
    powers.insert({"orange", "Soul"});
    powers.insert({"red", "Reality"});
    powers.insert({"yellow", "Mind"});

    for(int i=0; i<n; i++)
    {
        string color;
        cin>>color;

        stones[color] = 1;
    }


    cout<<(6-n)<<endl;
    for(auto x: colors){
        if(stones[x] == 0){
            cout<<powers[x]<<endl;
        }
    }
    
}