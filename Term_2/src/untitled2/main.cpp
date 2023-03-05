#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main() {
    char *X = (char *) calloc(1, 1);
    char *Y = (char *) calloc(1, 1);
    char *Z = (char *) calloc(1, 1);
    unsigned choice;
    unsigned iterations;
    string mas;
    cin >> iterations;
    int k;
    char a, b;
    X[0] = '0';
    Y[0] = '0';
    for(int l = 0, j = 0; j < iterations; j++) {
        cin >> choice;
        if (choice == 1) {
            cin >> k >> a >> b;
            int i = (int) strlen(X);
            while (i > k - 1) {
                X[i] = X[i - 1];
                i--;
            }
            X[k - 1] = a;
            i = (int) strlen(Y);
            while (i > k - 1) {
                Y[i] = Y[i - 1];
                i--;
            }
            Y[k - 1] = b;
        }
        if (choice == 2) {
            cin >> k;
            int i = k - 1;
            while (i < (int) strlen(X)) {
                X[i] = X[i + 1];
                i++;
                X[strlen(X) - 1] = '\0';
            }
            i = k - 1;
            while (i < (int) strlen(Y)) {
                Y[i] = Y[i + 1];
                i++;
            }
        }
        if (choice == 3) {
            cin >> k;
            int num_Z = atoi(X) + atoi(Y);
            itoa(num_Z, Z, 10);
            if(k > strlen(Z))
                mas+="-1\n";
            else {
                mas += Z[k - 1];
                mas += '\n';
            }
        }
    }
    cout << mas;
    return 0;
}