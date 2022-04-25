#include <bits/stdc++.h>
using namespace std;

vector<int> traverseString(string s)
{
    int i = 1;
    vector<int> arr;
    string num = "";
    while (i < s.length())
    {
        if (s[i] == ' ')
        {
            i++;
            continue;
        }
        if (s[i] == ',' || s[i] == ']')
        {
            int number = stoi(num);
            arr.push_back(number);

            num = "";
        }
        else
        {
            num += s[i];
        }
        i++;
    }
    return arr;
}

void solve(string a, string b, string c)
{
    vector<int> takeOutOrders = traverseString(a);
    vector<int> dineInOrders = traverseString(b);
    vector<int> servedOrders = traverseString(c);
    // x is pointer to takeOutOrders and y is to dineInorders
    int x = 0, y = 0, dineInOrdersSize = dineInOrders.size(), takeOutOrdersSize = takeOutOrders.size();
    for (int i = 0; i < servedOrders.size(); i++)
    {
        if (x < takeOutOrdersSize && takeOutOrders[x] == servedOrders[i])
            x++;
        else if (y < dineInOrdersSize && dineInOrders[y] == servedOrders[i])
            y++;
        else
        {
            cout << "Invalid" << endl;
            return;
        }
    }
    cout << "Valid" << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>> arr;
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    for (int j = 1; j <= t; j++)
    {
        string a, b, c;
        getline(cin, a);
        getline(cin, b);
        getline(cin, c);
        solve(a, b, c);
    }
}