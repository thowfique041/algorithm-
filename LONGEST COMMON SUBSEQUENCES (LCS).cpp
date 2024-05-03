#include <bits/stdc++.h>
using namespace std;

string findLCS(const string &s, const string &ss, const vector<vector<int>> &lcsTable) {
    int l = s.size();
    int ll = ss.size();
    string lcs;

    int i = l, j = ll;
    while (i > 0 && j > 0) {
        if (s[i - 1] == ss[j - 1]) {
            lcs = s[i - 1] + lcs;
            i--;
            j--;
        } else if (lcsTable[i - 1][j] > lcsTable[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return lcs;
}

int main() {
    string s, ss;
    cout << "Enter two strings for LCS: ";
    cin >> s >> ss;

    int l = s.size();
    int ll = ss.size();

    // Using vector for dynamic memory allocation
    vector<vector<int>> lcsTable(l + 1, vector<int>(ll + 1, 0));

    for (int i = 0; i <= l; i++) {
        for (int j = 0; j <= ll; j++) {
            if (i == 0 || j == 0)
                lcsTable[i][j] = 0;
            else if (s[i - 1] == ss[j - 1])
                lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
            else {
                lcsTable[i][j] = max(lcsTable[i - 1][j], lcsTable[i][j - 1]);
            }
        }
    }

    // Print the LCS table
    for (int i = 0; i <= l; i++) {
        for (int j = 0; j <= ll; j++) {
            cout << lcsTable[i][j] << " ";
        }
        cout << endl;
    }

    string lcs = findLCS(s, ss, lcsTable);
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
