bool SearchBi(int arr[], int l, int r, int x){
    while (l <= r){
        int mid = (l+r)/2;
        if (arr[mid] == x)
            return true;
        if (arr[mid] > x)
            r = mid-1;
        else
            l = mid+1;
    }
    return false;
}