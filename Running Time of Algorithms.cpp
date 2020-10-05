int runningTime(vector<int> arr) {
    int n = arr.size();
    int count = 0;

    for (int i = 1; i < n; i++) {
        int j = i;
        while (arr[j] < arr[j-1] && j > 0) {
            swap(arr[j], arr[j-1]);
            j--;
            count++;
        }
    }
    return count;
}
