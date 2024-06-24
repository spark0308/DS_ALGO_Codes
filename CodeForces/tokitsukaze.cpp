#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    switch (n % 4)
    {
    case 1:
        cout << 0 << " A";
        break;

    case 3:
        cout << 2 << " A";
        break;

    case 2:
        cout << 1 << " B";
        break;

    case 0:
        cout << 1 << " A";
        break;

    default:
        break;
    }
}