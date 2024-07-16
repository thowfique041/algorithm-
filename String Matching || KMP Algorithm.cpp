#include <bits/stdc++.h>
using namespace std;

// Function to compute the LPS (Longest Prefix Suffix) array
vector<int> lps(const string &s) {
    int n = s.size();
    vector<int> v(n, 0);
    int j = 1;
    int i = 0;
    while (j < n)
     {
        if (s[i] == s[j]) {
            v[j] = i + 1;
            i++;
            j++;
        }
         else {
            if (i == 0) {
                v[j] = 0;
                j++;
            }
             else {
                i = v[i - 1];
            }
        }
    }
    return v;
}

int main() {
    string s, ss;
    getline(cin, s);
    getline(cin, ss);

    /// Convert the input strings to uppercase to make the search case-insensitive
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    transform(ss.begin(), ss.end(), ss.begin(), ::toupper);

    int i = 0, j = 0;
    vector<int> v = lps(ss);

    while (i < s.size() && j < ss.size()) {
        if (s[i] == ss[j]) {
            i++;
            j++;
        } 
        else {
            if (j == 0) 
            {
                i++;
            } 
            else {
                j = v[j - 1];
            }
        }
    }

    if (j == ss.size()) {
        cout << "Found substring index at "<<i-j << endl;
    } 
    else {
        cout << "NO" << endl;
    }

    return 0;
}
