#include <bits/stdc++.h>
using namespace std;

bool sortnum(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

void displayAnswer(vector<vector<int>> &arr)
{
    string answer = "";
    answer += '[';
    for (int i = 0; i < arr.size(); i++)
    {
        answer += to_string(arr[i][1]) + ", " + to_string(arr[i][0]);
        if (i != arr.size() - 1)
            answer += ", ";
    }
    answer += ']';
    cout << answer;
}

void traverseString(vector<vector<int>> &arr, string s, int index)
{
    int i = 1, sumOfStringArr = 0;
    string num = "";
    map<int, bool> reapeatNumber;
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
            if (reapeatNumber[number] == false)
            {
                sumOfStringArr += number;
                reapeatNumber[number] = true;
            }
            num = "";
        }
        else
        {
            num += s[i];
        }
        i++;
    }
    arr.push_back({sumOfStringArr, index});
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
        traverseString(arr, s, j);
    }

    sort(arr.begin(), arr.end(), sortnum);
    displayAnswer(arr);
}