#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s, ss;
    cout << "Enter two strings for LCS: ";
    cin >> s >> ss;

    int l = s.size();
    int ll = ss.size();

    vector<vector<int>> a(l + 1, vector<int>(ll + 1, 0));

    for (int i = 0; i <= l; i++) {
        for (int j = 0; j <= ll; j++) {
            if (i == 0 || j == 0)
                a[i][j] = 0;
            else if (s[i - 1] == ss[j - 1])
                a[i][j] = a[i - 1][j - 1] + 1;
            else {
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
            }
        }
    }

    cout<<"LCS table is : "<<endl;
    for (int i = 0; i <= l; i++) {
        for (int j = 0; j <= ll; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
