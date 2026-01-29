#include <iostream>
using namespace std;

bool canDivide(int arr[], int n, int m, int maxOR) {
    int segments = 1;
    int currentOR = 0;

    for (int i = 0; i < n; i++) {
        if ((currentOR | arr[i]) <= maxOR) {
            currentOR |= arr[i];
        } else {
            segments++;
            currentOR = arr[i];
            if (segments > m)
                return false;
        }
    }
    return true;
}

int minimizeMaxOR(int arr[], int n, int m) {
    int low = 0, high = 0;

    for (int i = 0; i < n; i++)
        high |= arr[i];   // Maximum possible OR

    int answer = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canDivide(arr, n, m, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = 4;
    int m = 2;

    cout << minimizeMaxOR(arr, n, m);
    return 0;
}
