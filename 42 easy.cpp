#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */

void kaprekarNumbers(int p, int q) {
    vector<int> kaprekar;
    for (int i = p; i <= q; i++) {
        long long n = i;
        long long n2 = n * n;
        int d = 1;
        while (n / 10 != 0) d++;
        vector<int> n2array;
        while (n2 != 0) {
            n2array.push_back(n2 % 10);
            n2 /= 10;
        }
        if (n2array.size() == 1) n2array.push_back(0);
        reverse(n2array.begin(), n2array.end());
        vector<int> l;
        vector<int> r;
        for (auto i = 0u; i < n2array.size() / 2; i++) {
            l.push_back(n2array[i]);
        }
        for (auto i = n2array.size() / 2; i < n2array.size(); i++) {
            r.push_back(n2array[i]);
        }
        int left = 0;
        int right = 0;
        for (auto i = 0u; i < l.size(); i++) {
            left = left * 10 + l[i];
        }
        for (auto i = 0u; i < r.size(); i++) {
            right = right * 10 + r[i];
        }
        int total = left + right;
        if (total == i) kaprekar.push_back(total);
    }
    if (kaprekar.empty()) cout << "INVALID RANGE";
    else for (int x : kaprekar) cout << x << " ";
}

int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
