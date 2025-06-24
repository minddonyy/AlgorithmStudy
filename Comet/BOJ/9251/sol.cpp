using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
string s1 = "ABCBDAB";
string s2 = "BDCAB";

int main() {
    
    s1 = '.' + s1; s2 = '.' + s2;
    int len1 = s1.length();
    int len2 = s2.length();
    vector<vector<int>> dp(len1, vector<int>(len2, 0));
    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[len1 - 1][len2 - 1] << '\n';
    return 0;
}