#include <iostream>
int main() {
    int t = 0;
    int n = 0;
    std::cin >> t;
    int *sum = new int[t]{};
    int max = 0, imax = -1;
    for (int i = 0; i < t; i++) {
        std::cin >> n;
        int *arr = new int[n];
        for (int j = 0; j < n; j++) {
            std::cin >> arr[j];
        }
        for (int j = 0; j < n; j++) {
            if (arr[j] > max) {
                max = arr[j];
                imax = j;
            }
            if (arr[j] == 0) {
                arr[j] = -1;
                sum[i] = sum[i] + max;
                max = 0;
                arr[imax] = -1;
                j = 0;
            }
        }
        max = 0;
    }
    for (int i = 0; i < t; i++) {
        std::cout << sum[i] << '\n';
    }
    return 0;
}