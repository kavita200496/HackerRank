string abbreviation(string a, string b) {
    int n = a.size();
    int m = b.size();
    if (m > n) return "NO";
    
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        if (islower(a[i-1])) dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(m, i); j++) {
            if (islower(a[i-1])) dp[i][j] = dp[i][j] || dp[i-1][j];
            if (toupper(a[i-1]) == b[j-1]) dp[i][j] = dp[i][j] || dp[i-1][j-1];
        }
    }
    if (dp[n][m]) return "YES";
    return "NO";
}
