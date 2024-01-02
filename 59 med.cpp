#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */

vector<string> bomberMan(int n, vector<string> grid) {
    if (n == 0 || n == 1) return grid;

    int rows = grid.size();
    int cols = grid[0].size();

    vector<string> gridC(rows, string(cols, 'O'));
    if (n % 2 == 0) return gridC;

    vector<string> gridA(rows, string(cols, 'O'));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'O') {
                gridA[i][j] = '.';
                if (i - 1 >= 0) gridA[i - 1][j] = '.';
                if (i + 1 < rows) gridA[i + 1][j] = '.';
                if (j - 1 >= 0) gridA[i][j - 1] = '.';
                if (j + 1 < cols) gridA[i][j + 1] = '.';
            }
        }
    }
    if ((n+1) % 4 == 0) return gridA;

    vector<string> gridB(rows, string(cols, 'O'));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (gridA[i][j] == 'O') {
                gridB[i][j] = '.';
                if (i - 1 >= 0) gridB[i - 1][j] = '.';
                if (i + 1 < rows) gridB[i + 1][j] = '.';
                if (j - 1 >= 0) gridB[i][j - 1] = '.';
                if (j + 1 < cols) gridB[i][j + 1] = '.';
            }
        }
    }
    if ((n-1) % 4 == 0) return gridB;
    else return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
