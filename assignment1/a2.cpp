#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A[] = {1, 5, 6, 2, 8, 10, 7, 12};
    int N = sizeof(A) / sizeof(A[0]);

    sort(A, A + N);

    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < N; right++) {
        while (A[right] - A[left] > 10) {
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }

    cout << maxLen;
    return 0;
}
