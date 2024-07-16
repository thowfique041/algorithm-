#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    // Convert the input string to uppercase
    transform(s.begin(), s.end(), s.begin(), ::toupper);

    int n = s.size();
    vector<int> v(n, 0);

    int j = 1;
    int i = 0;
    while (j < n) {
        if (s[i] == s[j]) {
            v[j] = i + 1;
            i++;
            j++;
        } else {
            if (i == 0) {
                v[j] = 0;
                j++;
            } else {
                i = v[i - 1];
               
            }
        }
    }
    

   
    return 0;
}
