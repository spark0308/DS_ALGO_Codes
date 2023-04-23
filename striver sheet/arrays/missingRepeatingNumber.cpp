#include <bits/stdc++.h>
using namespace std;

vector<int> equationMethod(vector<int> nums, int n)
{
    int sum = (n * (n + 1)) / 2;
    int squares = (n * (n + 1) * (2 * n + 1)) / 6;

    int eleSum = 0;
    int eleSquares = 0;

    for (auto x : nums)
    {
        eleSum += x;
        eleSquares += (x * x);
    }

    int diff = sum - eleSum;
    int diffSquare = squares - eleSquares;

    int missingNumber = (diffSquare / diff + diff) / 2;
    int repeatingNumber = missingNumber - diff;

    vector<int> ans;
    ans.push_back(missingNumber);
    ans.push_back(repeatingNumber);

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (auto &x : nums)
        cin >> x;

    // Solution Function;
    vector<int> ans = equationMethod(nums, n);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}