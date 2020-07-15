#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    long count = 0;
    if (n == 0) return count;
    if (n == 1) {
        count = 1;
        return count;
    } 
    int dp1[n];
    int dp2[n];
    dp1[0] = 1;
    dp2[n-1] = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i-1]) dp1[i] = dp1[i-1]+1;
        else dp1[i] = 1;
    } 

    for (int i = n-2; i >= 0; i--) {
        if (arr[i] > arr[i+1]) dp2[i] = dp2[i+1]+1;
        else dp2[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        count += max(dp1[i], dp2[i]);
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
