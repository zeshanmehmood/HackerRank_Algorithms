#include <bits/stdc++.h>
using namespace std;


string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void extraLongFactorials(int n) {
    vector<int> result;
    result.push_back(1);
    for (int i = 2; i <= n; i++) {
        int carry = 0;
        int product;
        for (int& digit : result) {
            product = digit * i + carry;
            digit = product % 10;
            carry = product / 10;
        }
        while (carry != 0) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }
    for (auto i = result.rbegin(); i != result.rend(); i++) {
        cout << *i;
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

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
