#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

// -->> Wrote this code with absolutly no help and it was correct at first return

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int result = 0;
    int rightLimit = n+1;
    int leftLimit = 0;
    int upLimit = n+1;
    int downLimit = 0;
    int d1UpperSteps = min(n - r_q, n - c_q);
    int d1LowerSteps = min(r_q - 1, c_q -1);
    int d2UpperSteps = min(n - r_q, c_q - 1);
    int d2LowerSteps = min(r_q - 1, n - c_q);
    for (auto box : obstacles) {
        // for horizontal range between obstacles
        if (box[0] == r_q) {
            if (box[1] > c_q) {
                rightLimit = min(rightLimit, box[1]);
            }
            if (box[1] < c_q) {
                leftLimit = max(leftLimit, box[1]);
            }
        }
        // for vertical range between obstacles
        if (box[1] == c_q) {
            if (box[0] > r_q) {
                upLimit = min(upLimit, box[0]);
            }
            if (box[0] < r_q) {
                downLimit = max(downLimit, box[0]);
            }
        }
        // for diagonal 1 range between obstacles
        if (box[0] - box[1] == r_q - c_q) {
            if (box[0] > r_q && box[1] > c_q) {
                d1UpperSteps = min(d1UpperSteps, box[0] - 1 - r_q);
            }
            if (box[0] < r_q && box[1] < c_q) {
                d1LowerSteps = min(d1LowerSteps, r_q - 1 - box[0]);
            }
        }
        // for diagonal 2 range between obstacles
        if (box[0] - r_q == c_q - box[1]) {
            if (box[0] - r_q > 0 && c_q - box[1] > 0) {
                d2UpperSteps = min(d2UpperSteps, box[0] - 1 - r_q);
            }
            if (box[0] - r_q < 0 && c_q - box[1] < 0) {
                d2LowerSteps = min(d2LowerSteps, r_q - 1 - box[0]);
            }
        }
    }
    result += rightLimit - leftLimit - 2;
    result += upLimit - downLimit - 2;
    result += d1UpperSteps + d1LowerSteps + d2UpperSteps + d2LowerSteps;
    return result;
}

// -->> ends here

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

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
