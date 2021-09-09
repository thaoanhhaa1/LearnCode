int binarySearch(int arr[], int n, int x) {
    int r = n - 1;
    int l = 0;
    while (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid-1] < x && arr[mid] > x)
        return mid;
    if (arr[mid] > x)
        r = mid - 1;
    if (arr[mid] < x)
        l = mid + 1;
    }
}