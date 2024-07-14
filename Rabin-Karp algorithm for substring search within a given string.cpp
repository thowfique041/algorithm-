#include <bits/stdc++.h>
using namespace std;
#define d 256 // Number of possible ASCII characters

bool cmp(const string& s, const string& ss, int j) {
    for (int i = 0; i < ss.size(); i++) {
        if (s[j + i] != ss[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s, ss;
    cout << "String: ";
    getline(cin, s);
    cout << "Substring: ";
    getline(cin, ss);

    int h = 101; // Default prime number for modulus
    string hInput;
    cout << "Enter a prime number for modulus to reduce hash collisions (or press Enter to use default): ";
    getline(cin, hInput);

   /// Optional feature to allow user to input a prime number
    if (!hInput.empty()) {
        try {
            h = stoi(hInput);
        } catch (invalid_argument&) {
            cout << "Invalid input. Using default prime number " << h << "." << endl;
        }
    }
    
    /// If you want to avoid the optional feature, comment out the above lines and uncomment the next line
    /// cin >> h;

    int n = s.size();
    int m = ss.size();
    int patternHash = 0, textHash = 0, highestPow = 1;

    // Compute the highest power of d (d^(m-1) % h)
    for (int i = 0; i < m - 1; i++) {
        highestPow = (highestPow * d) % h;
    }

    // Compute initial hash values for pattern and first window of text
    for (int i = 0; i < m; i++) {
        patternHash = (d * patternHash + ss[i]) % h;
        textHash = (d * textHash + s[i]) % h;
    }

    // Sliding window to check for matches
    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash && cmp(s, ss, i)) {
            cout << "Found your substring at index: " << i << endl;
            return 0;
        }

        // Update hash value for next window
        if (i < n - m) {
            textHash = (d * (textHash - s[i] * highestPow) + s[i + m]) % h;
            // Ensure the hash value is positive
            if (textHash < 0) {
                textHash = (textHash + h) % h;
            }
        }
    }

    cout << "Not found" << endl;
    return 0;
}
