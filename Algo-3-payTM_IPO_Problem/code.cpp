#include <bits/stdc++.h>
using namespace std;

void traverseString(string s, int index)
{
    int i = 1;
    int profit = 0, buyStockPrice = INT_MAX, sellTime = 0, time = 0, hr = 9, min = 30;
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
            int currentStockPrice = stoi(num);
            if (currentStockPrice < buyStockPrice)
            {
                buyStockPrice = currentStockPrice;
            }
            if (currentStockPrice - buyStockPrice > profit)
            {
                profit = currentStockPrice - buyStockPrice;
                sellTime = time;
            }
            time++;

            num = "";
        }
        else
        {
            num += s[i];
        }
        i++;
    }
    int hradd = (sellTime * 10) / 60;
    int minadd = (sellTime * 10) % 60;
    hr += hradd;
    min += minadd;
    if (min >= 60)
    {
        hr++;
        min %= 60;
    }
    hr %= 12;
    if (hr == 0)
        hr = 12;
    string answer = '[' + to_string(profit) + ',' + to_string(hr) + '.' + to_string(min);
    if (min == 0)
        answer += '0';
    answer += ']';

    cout << answer << endl;
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
        getline(cin, s);
        traverseString(s, j);
    }
}