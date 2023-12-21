#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {
    string sClean = s;
    sClean.erase(remove(sClean.begin(), sClean.end(), ' '), sClean.end());
    int L = sClean.size();
    float rootL = sqrt(L);
    int r = floor(rootL);
    int c = ceil(rootL);
    if (r * c < L) r++;
    vector<vector<char>> sArray(r, vector<char>(c, '\0'));
    int a = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a < sClean.size()) {
                sArray[i][j] = sClean[a];
                a++;
            }
            else break;
        }
    }
    string result;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            if (sArray[j][i] != '\0') {
                result.push_back(sArray[j][i]);
            }
        }
        if (i < c - 1) {
            result.push_back(' ');
        }
    }
    return result;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
