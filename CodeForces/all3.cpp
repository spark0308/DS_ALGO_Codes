#include <bits/stdc++.h>
using namespace std;

void printMap(map<int, int> mp){
    cout<<"-----"<<endl;
    for(auto x: mp) cout<<x.first<<" -> "<<x.second<<endl;
    cout<<"-----"<<endl;
}

int solution(int n, vector<int> arr)
{
    int ans = 0;
    map<int, int> mp;
    for (auto x : arr)
        mp[x]++;

    //printMap(mp);

    for (int i = 0; i < n; i++)
    {
        map<int, int> mp2(mp);
        for (int j = i; j < n; j++)
        {
            mp2[arr[j]]--;
            mp2[(arr[j]%3) + 1]++;
            
            //cout<<"map2\n";
            //printMap(mp2);
            //cout<<"map1\n";
            //printMap(mp);

            if(mp2[1] > 0 && mp2[2] > 0 && mp2[3] > 0) ans++;
        }
    }

    return ans;
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &x : arr)
            cin >> x;
        
        cout<<solution(n, arr)<<endl;
    }
}
