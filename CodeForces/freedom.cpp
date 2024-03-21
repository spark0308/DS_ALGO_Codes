#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<long long> arr)
{
    map<long long, long long> mp;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long num = arr[i] * 3;
        long long deno = arr[i] - 1;

        if (deno != 0 && num % deno == 0)
        {
            long long ai = num / deno;
            ans = ans + mp[ai];
        }
        mp[arr[i]]++;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        // long long ans = 0;
        // for(int i=0; i<n-1; i++){
        //     for(int j=i+1; j<n; j++){
        //         long long a = arr[i] - arr[j];
        //         long long b = arr[i] + arr[j];
        //         long long c = arr[i] * arr[j];

        //         if((2*b) == (a + c) ) ans += 1;
        //     }
        // }

        cout << solution(n, arr) << endl;
    }
}